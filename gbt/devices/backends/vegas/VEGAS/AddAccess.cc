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
    ADDACCESS(VEGAS, VegasCoordinator_PANEL,
              altair, VegasHost,
              new CoordinatorControlDDL(VegasMsg::Vegas),
              0);//new CoordinatorMonitorDDL(VegasMsg::Vegas));
    
    ADDACCESS(BankAMgr, VegasBankA_PANEL,
              altair, VegasHost,
              new BankControlDDL(VegasMsg::BankAMgr),
              0);//new BankMonitorDDL(VegasMsg::BankAMgr));

    ADDACCESS(BankBMgr, VegasBankB_PANEL,
              altair, VegasHost,
              new BankControlDDL(VegasMsg::BankBMgr),
              0);//new BankMonitorDDL(VegasMsg::BankBMgr));

    ADDACCESS(BankCMgr, VegasBankC_PANEL,
              altair, VegasHost,
              new BankControlDDL(VegasMsg::BankCMgr),
              0);//new BankMonitorDDL(VegasMsg::BankCMgr));

    ADDACCESS(BankDMgr, VegasBankD_PANEL,
              altair, VegasHost,
              new BankControlDDL(VegasMsg::BankDMgr),
              0);//new BankMonitorDDL(VegasMsg::BankDMgr));

    ADDACCESS(BankEMgr, VegasBankE_PANEL,
              altair, VegasHost,
              new BankControlDDL(VegasMsg::BankEMgr),
              0);//new BankMonitorDDL(VegasMsg::BankEMgr));

    ADDACCESS(BankFMgr, VegasBankF_PANEL,
              altair, VegasHost,
              new BankControlDDL(VegasMsg::BankFMgr),
              0);//new BankMonitorDDL(VegasMsg::BankFMgr));

    ADDACCESS(BankGMgr, VegasBankG_PANEL,
              altair, VegasHost,
              new BankControlDDL(VegasMsg::BankGMgr),
              0);//new BankMonitorDDL(VegasMsg::BankGMgr));

    ADDACCESS(BankHMgr, VegasBankH_PANEL,
              altair, VegasHost,
              new BankControlDDL(VegasMsg::BankHMgr),
              0);//new BankMonitorDDL(VegasMsg::BankHMgr));

    return 0;
}

NameList ManagerNames =
{
    "VEGAS",
    "BankAMgr",
    "BankBMgr",
    "BankCMgr",
    "BankDMgr",
    "BankEMgr",
    "BankFMgr",
    "BankGMgr",
    "BankHMgr",
    0
};

//NameList *getManagerBase()
NameList *getManagerNames()
{
    return reinterpret_cast<NameList*>(&ManagerNames);
}

#endif//defined(SOLARIS) || defined(LINUX)
