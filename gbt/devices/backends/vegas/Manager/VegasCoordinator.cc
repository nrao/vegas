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

// Parent
#include "VegasCoordinator.h"
// Local
#include "ValonSynth.h"
#include "VegasCoordinatorId.h"
#include "VegasManager.h"
#include "VegasMsg.h"
// YGOR
#include "gbtRpcNumbers.h"

VegasCoordinator::VegasCoordinator()
    :
    Coordinator(VegasCoordinatorId::childCount,
                VegasCoordinatorId::ParameterCnt,
                "Vegas",
                VegasMsg::Vegas),
    m_clk(0)
{
    // Clock synthesizer
    m_clk = new Synthesizer("/dev/ttyS0");

    // Submanagers
    // Bank A
    childRecipient[VegasCoordinatorId::BankAMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankAMgr, this);
    childManager[VegasCoordinatorId::BankAMgr] = new VegasManager;
    childManager[VegasCoordinatorId::BankAMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankAMgr]);
    childPanel[VegasCoordinatorId::BankAMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankAMgr]);
    childManager[VegasCoordinatorId::BankAMgr]->init();
    server[VegasCoordinatorId::BankAMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankAMgr],
        VegasBankA_PANEL);
    // Bank B
    childRecipient[VegasCoordinatorId::BankBMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankBMgr, this);
    childManager[VegasCoordinatorId::BankBMgr] = new VegasManager;
    childManager[VegasCoordinatorId::BankBMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankBMgr]);
    childPanel[VegasCoordinatorId::BankBMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankBMgr]);
    childManager[VegasCoordinatorId::BankBMgr]->init();
    server[VegasCoordinatorId::BankBMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankBMgr],
        VegasBankB_PANEL);
    // Bank C
    childRecipient[VegasCoordinatorId::BankCMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankCMgr, this);
    childManager[VegasCoordinatorId::BankCMgr] = new VegasManager;
    childManager[VegasCoordinatorId::BankCMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankCMgr]);
    childPanel[VegasCoordinatorId::BankCMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankCMgr]);
    childManager[VegasCoordinatorId::BankCMgr]->init();
    server[VegasCoordinatorId::BankCMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankCMgr],
        VegasBankC_PANEL);
    // Bank D
    childRecipient[VegasCoordinatorId::BankDMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankDMgr, this);
    childManager[VegasCoordinatorId::BankDMgr] = new VegasManager;
    childManager[VegasCoordinatorId::BankDMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankDMgr]);
    childPanel[VegasCoordinatorId::BankDMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankDMgr]);
    childManager[VegasCoordinatorId::BankDMgr]->init();
    server[VegasCoordinatorId::BankDMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankDMgr],
        VegasBankD_PANEL);
    // Bank E
    childRecipient[VegasCoordinatorId::BankEMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankEMgr, this);
    childManager[VegasCoordinatorId::BankEMgr] = new VegasManager;
    childManager[VegasCoordinatorId::BankEMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankEMgr]);
    childPanel[VegasCoordinatorId::BankEMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankEMgr]);
    childManager[VegasCoordinatorId::BankEMgr]->init();
    server[VegasCoordinatorId::BankEMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankEMgr],
        VegasBankE_PANEL);
    // Bank F
    childRecipient[VegasCoordinatorId::BankFMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankFMgr, this);
    childManager[VegasCoordinatorId::BankFMgr] = new VegasManager;
    childManager[VegasCoordinatorId::BankFMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankFMgr]);
    childPanel[VegasCoordinatorId::BankFMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankFMgr]);
    childManager[VegasCoordinatorId::BankFMgr]->init();
    server[VegasCoordinatorId::BankFMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankFMgr],
        VegasBankF_PANEL);
    // Bank G
    childRecipient[VegasCoordinatorId::BankGMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankGMgr, this);
    childManager[VegasCoordinatorId::BankGMgr] = new VegasManager;
    childManager[VegasCoordinatorId::BankGMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankGMgr]);
    childPanel[VegasCoordinatorId::BankGMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankGMgr]);
    childManager[VegasCoordinatorId::BankGMgr]->init();
    server[VegasCoordinatorId::BankGMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankGMgr],
        VegasBankG_PANEL);
    // Bank H
    childRecipient[VegasCoordinatorId::BankHMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankHMgr, this);
    childManager[VegasCoordinatorId::BankHMgr] = new VegasManager;
    childManager[VegasCoordinatorId::BankHMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankHMgr]);
    childPanel[VegasCoordinatorId::BankHMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankHMgr]);
    childManager[VegasCoordinatorId::BankHMgr]->init();
    server[VegasCoordinatorId::BankHMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankHMgr],
        VegasBankH_PANEL);
}

VegasCoordinator::~VegasCoordinator()
{
    for(int i = ManagerId::ParameterCnt; i < pn; ++i)
    {
        delete p[i];
    }

    for(int i = 0; i < VegasCoordinatorId::childCount; ++i)
    {
        delete server[i];
        delete childManager[i];
    }
}
