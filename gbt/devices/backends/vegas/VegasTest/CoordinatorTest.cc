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

#include "CoordinatorTest.h"
#include "VegasCoordinator.h"

void
CoordinatorTest::setUp()
{
    vegas_coordinator = new VegasCoordinator;
    vegas_coordinator->standby();
    waitForState(ManagerId::Standby);
    assertStatus();
}

void
CoordinatorTest::tearDown()
{
    vegas_coordinator->off();
    delete vegas_coordinator;
    vegas_coordinator = 0;
}

void
CoordinatorTest::assertStatus(const Msg::Level status)
{
    Msg::Level mgr_status;
    vegas_coordinator->getParameterValue(ManagerId::status, &mgr_status);
    CPPUNIT_ASSERT_EQUAL(status, mgr_status);
}

void
CoordinatorTest::waitForState(ManagerId::State target)
{
    ManagerId::State state;
    do
    {
        usleep(1000);
        vegas_coordinator->sequence();
        vegas_coordinator->getParameterValue(ManagerId::state, &state);
    } while(state != target);
}

//-------//
// Tests //
//-------//
// testCreateVegas
void
CoordinatorTest::testCreate()
{
    CPPUNIT_ASSERT(vegas_coordinator != 0);
}

// testOnSequence
void
CoordinatorTest::testActivate()
{
    vegas_coordinator->on();
    waitForState(ManagerId::Ready);
    assertStatus();
}

// vco_range
void
CoordinatorTest::test_vco_range()
{
    vco_range vcor = {2200, 4400};

    // Valid
    vegas_coordinator->putParameterValue(VegasCoordinatorId::vco_range, &vcor);
    vegas_coordinator->regChange();
    assertStatus();

    // Invalid
    vcor.min = vcor.max + 1;
    vegas_coordinator->putParameterValue(VegasCoordinatorId::vco_range, &vcor);
    vegas_coordinator->regChange();
    assertStatus(Msg::Notice);
}
