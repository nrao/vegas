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

#ifndef MANAGERTEST_H
#define MANAGERTEST_H

// Local
#include "VegasManager.h"
// CPPUNIT
#include <cppunit/extensions/HelperMacros.h>

class ManagerTest : public CppUnit::TestCase
{
    CPPUNIT_TEST_SUITE(ManagerTest);
        CPPUNIT_TEST(testCreate);
        CPPUNIT_TEST(testActivate);
        // Parameter tests
        CPPUNIT_TEST(test_cal);
    CPPUNIT_TEST_SUITE_END();

public:
    ManagerTest();

    void setUp();
    void tearDown();

protected:
    void assertStatus(const Msg::Level status = Msg::Clear);
    void waitForState(ManagerId::State);

    //
    void testCreate();
    void testActivate();

    // Parameters
    void test_cal();

private:
    VegasManager *vegas_manager;
};

inline
ManagerTest::ManagerTest()
    :
    CppUnit::TestCase()
{
}

#endif//MANAGERTEST_H
