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

#include "VegasManagerId.h"
#include "VegasTest.h"

void
VegasTest::setUp()
{
    vegas_manager = new VegasManager;
    vegas_manager->standby();
    wait_for_state(ManagerId::Standby);

    check_status();
}

void
VegasTest::tearDown()
{
    vegas_manager->off();
    delete vegas_manager;
    vegas_manager = 0;
}

void
VegasTest::check_status()
{
    vegas_manager->regChange();
    Msg::Level status;
    vegas_manager->getParameterValue(ManagerId::status, &status);
    CPPUNIT_ASSERT_EQUAL(Msg::Clear, status);
}

void
VegasTest::wait_for_state(ManagerId::State target)
{
    ManagerId::State state = ManagerId::Off;
    do
    {
        usleep(1000);
        vegas_manager->sequence();
        vegas_manager->getParameterValue(ManagerId::state, &state);
    } while(state != target);
}

//-------//
// Tests //
//-------//
void
VegasTest::test_create_vegas()
{
    CPPUNIT_ASSERT(vegas_manager != 0);
}

void
VegasTest::test_off_on_sequence()
{
    vegas_manager->off();
    vegas_manager->on();
    wait_for_state(ManagerId::Ready);
    Msg::Level status;
    vegas_manager->getParameterValue(ManagerId::status, &status);
    CPPUNIT_ASSERT_EQUAL(Msg::Clear, status);
}
