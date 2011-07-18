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

#ifndef VEGAS_H
#define VEGAS_H

#include "Parameter.h"
#include "VegasId.h"
#include "VegasMsg.h"

class Sampler;

class Vegas : public ManagerSynchronous
{
public:
    Vegas();
    ~Vegas();

    void constructSamplers();
    void monitor();

protected:
    // Parameters
    int acc_lenAct(const int &acc_len);
    int acc_lenChk(const int &acc_len);
    void acc_lenDep(int &acc_len);

    int armAct(const int &arm);
    int armChk(const int &arm);
    void armDep(int &arm);

    int adc_snap0_ctrlAct(const int &adc_snap0_ctrl);
    int adc_snap0_ctrlChk(const int &adc_snap0_ctrl);
    void adc_snap0_ctrlDep(int &adc_snap0_ctrl);

    int adc_snap1_ctrlAct(const int &adc_snap1_ctrl);
    int adc_snap1_ctrlChk(const int &adc_snap1_ctrl);
    void adc_snap1_ctrlDep(int &adc_snap1_ctrl);

    int dest_ipAct(const int &dest_ip);
    int dest_ipChk(const int &dest_ip);
    void dest_ipDep(int &dest_ip);

    int dest_ip_selAct(const int &dest_ip_sel);
    int dest_ip_selChk(const int &dest_ip_sel);
    void dest_ip_selDep(int &dest_ip_sel);

    int dest_portAct(const int &dest_port);
    int dest_portChk(const int &dest_port);
    void dest_portDep(int &dest_port);

    int dest_port_selAct(const int &dest_port_sel);
    int dest_port_selChk(const int &dest_port_sel);
    void dest_port_selDep(int &dest_port_sel);

    int tintAct(const double &tint);
    int tintChk(const double &tint);
    void tintDep(double &tint);

    int sync_periodAct(const int &sync_period);
    int sync_periodChk(const int &sync_period);
    void sync_periodDep(int &sync_period);

    int sync_period_selAct(const int &sync_period_sel);
    int sync_period_selChk(const int &sync_period_sel);
    void sync_period_selDep(int &sync_period_sel);

    // int Act(const &);
    // int Chk(const &);
    // void Dep( &);

private:
    //ProposedStartTime sampleEstimatedStartTime();

    // Samplers?
};

#endif//VEGAS_H
