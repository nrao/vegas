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

#include "ManagerTest.h"
#include "VegasManager.h"

void
ManagerTest::setUp()
{
    vegas_manager = new VegasManager("BankAMgr", VegasMsg::BankAMgr);
    vegas_manager->standby();
    waitForState(ManagerId::Standby);
    assertStatus();
}

void
ManagerTest::tearDown()
{
    vegas_manager->off();
    delete vegas_manager;
    vegas_manager = 0;
}

void
ManagerTest::assertStatus(const Msg::Level status)
{
    Msg::Level mgr_status;
    vegas_manager->getParameterValue(ManagerId::status, &mgr_status);
    CPPUNIT_ASSERT_EQUAL(status, mgr_status);
}

void
ManagerTest::waitForState(ManagerId::State target)
{
    ManagerId::State state;
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
// testCreate
void
ManagerTest::testCreate()
{
    CPPUNIT_ASSERT(vegas_manager != 0);
}

// testManagerActivate
void
ManagerTest::testActivate()
{
    vegas_manager->on();
    waitForState(ManagerId::Ready);
    assertStatus();
}


// test_cal
void
ManagerTest::test_cal()
{
    int cal;

    // Valid
    cal = 0;
    vegas_manager->putParameterValue(VegasManagerId::cal, &cal);
    vegas_manager->regChange();
    assertStatus();

    cal = 1;
    vegas_manager->putParameterValue(VegasManagerId::cal, &cal);
    vegas_manager->regChange();
    assertStatus();

    // Invalid
    cal = -1;
    vegas_manager->putParameterValue(VegasManagerId::cal, &cal);
    vegas_manager->regChange();
    assertStatus(Msg::Notice);

    cal = 2;
    vegas_manager->putParameterValue(VegasManagerId::cal, &cal);
    vegas_manager->regChange();
    assertStatus(Msg::Notice);

}
