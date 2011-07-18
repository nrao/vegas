//# Copyright (C) 2011 Associated Universities, Inc. Washington DC, USA.
//# 
//# This program is free software; you can redistribute it and/or modify
//# it under the terms of the GNU General Public License as published by
//# the Free Software Foundation; either version 2 of the License, or
//# (at your option) any later version.
//# 
//# This program is distributed in the hope that it will be useful, but
//# WITHOUT ANY WARRANTY; without even the implied warranty of
//# MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
//# General Public License for more details.
//# 
//# You should have received a copy of the GNU General Public License
//# along with this program; if not, write to the Free Software
//# Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
//# 
//# Correspondence concerning GBT software should be addressed as follows:
//#	GBT Operations
//#	National Radio Astronomy Observatory
//#	P. O. Box 2
//#	Green Bank, WV 24944-0002 USA

#include "auto_ptr.h"
#include "DeviceAccessContainer.h"
#include "gbtRpcNumbers.h"
#include "PanelServer.h"
#include "str.h"
#include "Thread.h"
#include "Vegas.h"

#include <signal.h>
#include <iostream>

using std::cout;
using std::cerr;
using std::endl;

char const *manager_name = "VEGAS";
unsigned long rpc_number = VEGAS_PANEL;

auto_pointer<Vegas> manager;
auto_pointer<PanelServer> server;

void InitManager();
void RunManager();
void signal_handler(int sig);

/********************************************************************
 * main()
 *
 ** Sets up the process and runs it.
 *
 *******************************************************************/

int main(int argc, char **argv)
{
    signal(SIGHUP, signal_handler);     // hangup
#if !defined(DEBUG)                     // when debugging, wish to use CTRL-C
    signal(SIGINT, signal_handler);     // interrupt
#endif
    signal(SIGQUIT, signal_handler);    // quit
    signal(SIGTERM, signal_handler);    // software termination
    signal(SIGPIPE, SIG_IGN);
    
    InitManager();
    RunManager();

    return 0;
}

/********************************************************************
 * InitManager()
 *
 ** Creates and initializes the VEGAS manager
 *
 *******************************************************************/

void InitManager()
{
    DeviceAccessContainer *ddlib;
    String system_up_msg(128, "%s is initializing", manager_name);

    Message::systemUpMessage(GbtMsg::Vegas, system_up_msg.c_str());
    ddlib = DeviceAccessContainer::instance(manager_name);

    if (ddlib->size() == 0)
    {
        cerr << "Error loading " << manager_name << " library" << endl;
        assert(0);
    }

    manager.reset(new Vegas);
    server.reset(new PanelServer(manager.get(), rpc_number));
    cerr << "Initializing " << manager_name << " Manager " << endl;
    manager->init();
    cerr << "Done Initializing " << manager_name << "Manager " << endl;
}

/********************************************************************
 * RunManager()
 *
 ** Runs the manager.  First, spawns the monitor thread, then turns
 *  the manager on, activates it, and calls server->run().
 *
 *******************************************************************/

void RunManager()
{
    TimeStamp now, lasttime;
    
    cout << "Spawning tasks" << endl;

    TimeStamp lastsequence;
    TimeStamp last_heath_check;
    while (!server->done())
    {
        server->poll_with_qos(500);

        now = getTimeOfDay();

        if ((now - lastsequence).Sec() >= 0.3)
        {
            manager->sequence();
            lastsequence = now;
        }

        if ((now - lasttime).Sec() > 20.0)
        {
            lasttime = now;  
        }

        if ((now - last_heath_check).Sec() > 30.0)
        {
            last_heath_check = now;
        }
    }
}

/********************************************************************
 * signal_handler(int sig)
 *
 ** The Manager's signal handler.  Allows the manager to terminate
 *  gracefully upon receiving the most common signals.
 *
 * @param int sig: The signal received.
 *
 *******************************************************************/

void signal_handler(int sig)
{
    if (signal(sig, SIG_IGN) == SIG_ERR)
    {
        cerr << "System error: signal" << endl ;
        exit(2);
    }

    switch (sig)
    {
        case SIGTERM:
            cerr << "Terminate  " << getTimeOfDay() << endl ;
            break;
        case SIGHUP:
            cerr << "Hangup  " << getTimeOfDay() << endl ;
            break;
        case SIGINT:
            cerr << "Interrupt  " << getTimeOfDay() << endl ;
            break;
        case SIGQUIT:
            cerr << "Quit  " << getTimeOfDay() << endl ;
            break;
    }

    server->terminate();
    cerr << "Server terminated." << endl;
}
