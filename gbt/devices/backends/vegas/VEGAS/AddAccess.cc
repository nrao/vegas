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

#if defined(SOLARIS) || defined(LINUX)
#include "AddAccess.h"
#include "BankDDL.h"
#include "CoordinatorDDL.h"
#include "gbtRpcNumbers.h"
#include "GbtMsg.h"
#include "VegasMsg.h"

DeviceAccess *addAccess(const char *subdevice)
{
    ADDACCESS( VEGAS, VegasCoordinator_PANEL,
	       altair, VegasHost,
               new CoordinatorControlDDL(VegasMsg::Vegas),
               new CoordinatorMonitorDDL(VegasMsg::Vegas));
    
    ADDACCESS( Manager1, VegasBankA_PANEL,
               altair, VegasHost,
               new BankControlDDL(VegasMsg::Vegas),
               new BankMonitorDDL(VegasMsg::Vegas));
    ADDACCESS( Manager2, VegasBankB_PANEL,
               altair, VegasHost,
               new BankControlDDL(VegasMsg::Vegas),
               new BankMonitorDDL(VegasMsg::Vegas));
    ADDACCESS( Manager3, VegasBankC_PANEL,
               altair, VegasHost,
               new BankControlDDL(VegasMsg::Vegas),
               new BankMonitorDDL(VegasMsg::Vegas));
    ADDACCESS( Manager4, VegasBankD_PANEL,
               altair, VegasHost,
               new BankControlDDL(VegasMsg::Vegas),
               new BankMonitorDDL(VegasMsg::Vegas));
    ADDACCESS( Manager5, VegasBankE_PANEL,
               altair, VegasHost,
               new BankControlDDL(VegasMsg::Vegas),
               new BankMonitorDDL(VegasMsg::Vegas));
    ADDACCESS( Manager6, VegasBankF_PANEL,
               altair, VegasHost,
               new BankControlDDL(VegasMsg::Vegas),
               new BankMonitorDDL(VegasMsg::Vegas));
    ADDACCESS( Manager7, VegasBankG_PANEL,
               altair, VegasHost,
               new BankControlDDL(VegasMsg::Vegas),
               new BankMonitorDDL(VegasMsg::Vegas));
    ADDACCESS( Manager8, VegasBankH_PANEL,
               altair, VegasHost,
               new BankControlDDL(VegasMsg::Vegas),
               new BankMonitorDDL(VegasMsg::Vegas));
    return 0;
}

NameList ManagerNames =
{
    "VEGAS",
    "Manager1",
    "Manager2",
    "Manager3",
    "Manager4",
    "Manager5",
    "Manager6",
    "Manager7",
    "Manager8",
    0
};

//NameList *getManagerBase()
NameList *getManagerNames()
{
    return reinterpret_cast<NameList*>(&ManagerNames);
}

#endif//defined(SOLARIS) || defined(LINUX)
