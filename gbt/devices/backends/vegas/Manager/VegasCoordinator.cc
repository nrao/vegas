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
    //m_clk = new Synthesizer("/dev/ttyS0");

    initializeParameters();
    int success = init();
    if(!success)
    {
        std::cout << "Coordinator initialization failed" << std::endl;
    }

    // Submanagers
    // Bank A
    childRecipient[VegasCoordinatorId::BankAMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankAMgr, this);
    childManager[VegasCoordinatorId::BankAMgr] =
        new VegasManager(vegasChildName[VegasCoordinatorId::BankAMgr], VegasMsg::BankAMgr);
    childManager[VegasCoordinatorId::BankAMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankAMgr]);
    childPanel[VegasCoordinatorId::BankAMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankAMgr]);
    childManager[VegasCoordinatorId::BankAMgr]->init();
    server[VegasCoordinatorId::BankAMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankAMgr],
        VegasBankA_PANEL);
    childInService[VegasCoordinatorId::BankAMgr] = 1;
    // Bank B
    childRecipient[VegasCoordinatorId::BankBMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankBMgr, this);
    childManager[VegasCoordinatorId::BankBMgr] =
        new VegasManager(vegasChildName[VegasCoordinatorId::BankBMgr], VegasMsg::BankBMgr);
    childManager[VegasCoordinatorId::BankBMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankBMgr]);
    childPanel[VegasCoordinatorId::BankBMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankBMgr]);
    childManager[VegasCoordinatorId::BankBMgr]->init();
    server[VegasCoordinatorId::BankBMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankBMgr],
        VegasBankB_PANEL);
    childInService[VegasCoordinatorId::BankBMgr] = 1;
    // Bank C
    childRecipient[VegasCoordinatorId::BankCMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankCMgr, this);
    childManager[VegasCoordinatorId::BankCMgr] =
        new VegasManager(vegasChildName[VegasCoordinatorId::BankCMgr], VegasMsg::BankCMgr);
    childManager[VegasCoordinatorId::BankCMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankCMgr]);
    childPanel[VegasCoordinatorId::BankCMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankCMgr]);
    childManager[VegasCoordinatorId::BankCMgr]->init();
    server[VegasCoordinatorId::BankCMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankCMgr],
        VegasBankC_PANEL);
    childInService[VegasCoordinatorId::BankCMgr] = 1;
    // Bank D
    childRecipient[VegasCoordinatorId::BankDMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankDMgr, this);
    childManager[VegasCoordinatorId::BankDMgr] =
        new VegasManager(vegasChildName[VegasCoordinatorId::BankDMgr], VegasMsg::BankDMgr);
    childManager[VegasCoordinatorId::BankDMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankDMgr]);
    childPanel[VegasCoordinatorId::BankDMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankDMgr]);
    childManager[VegasCoordinatorId::BankDMgr]->init();
    server[VegasCoordinatorId::BankDMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankDMgr],
        VegasBankD_PANEL);
    childInService[VegasCoordinatorId::BankDMgr] = 1;
    // Bank E
    childRecipient[VegasCoordinatorId::BankEMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankEMgr, this);
    childManager[VegasCoordinatorId::BankEMgr] =
        new VegasManager(vegasChildName[VegasCoordinatorId::BankEMgr], VegasMsg::BankEMgr);
    childManager[VegasCoordinatorId::BankEMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankEMgr]);
    childPanel[VegasCoordinatorId::BankEMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankEMgr]);
    childManager[VegasCoordinatorId::BankEMgr]->init();
    server[VegasCoordinatorId::BankEMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankEMgr],
        VegasBankE_PANEL);
    childInService[VegasCoordinatorId::BankEMgr] = 1;
    // Bank F
    childRecipient[VegasCoordinatorId::BankFMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankFMgr, this);
    childManager[VegasCoordinatorId::BankFMgr] =
        new VegasManager(vegasChildName[VegasCoordinatorId::BankFMgr], VegasMsg::BankFMgr);
    childManager[VegasCoordinatorId::BankFMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankFMgr]);
    childPanel[VegasCoordinatorId::BankFMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankFMgr]);
    childManager[VegasCoordinatorId::BankFMgr]->init();
    server[VegasCoordinatorId::BankFMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankFMgr],
        VegasBankF_PANEL);
    childInService[VegasCoordinatorId::BankFMgr] = 1;
    // Bank G
    childRecipient[VegasCoordinatorId::BankGMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankGMgr, this);
    childManager[VegasCoordinatorId::BankGMgr] =
        new VegasManager(vegasChildName[VegasCoordinatorId::BankGMgr], VegasMsg::BankGMgr);
    childManager[VegasCoordinatorId::BankGMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankGMgr]);
    childPanel[VegasCoordinatorId::BankGMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankGMgr]);
    childManager[VegasCoordinatorId::BankGMgr]->init();
    server[VegasCoordinatorId::BankGMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankGMgr],
        VegasBankG_PANEL);
    childInService[VegasCoordinatorId::BankGMgr] = 1;
    // Bank H
    childRecipient[VegasCoordinatorId::BankHMgr] =
        new CoordinatorRecipient(VegasCoordinatorId::BankHMgr, this);
    childManager[VegasCoordinatorId::BankHMgr] =
        new VegasManager(vegasChildName[VegasCoordinatorId::BankHMgr], VegasMsg::BankHMgr);
    childManager[VegasCoordinatorId::BankHMgr]->setRecipient(
        childRecipient[VegasCoordinatorId::BankHMgr]);
    childPanel[VegasCoordinatorId::BankHMgr] = new PanelLocal(
        childManager[VegasCoordinatorId::BankHMgr]);
    childManager[VegasCoordinatorId::BankHMgr]->init();
    server[VegasCoordinatorId::BankHMgr] = new PanelServer(
        childManager[VegasCoordinatorId::BankHMgr],
        VegasBankH_PANEL);
    childInService[VegasCoordinatorId::BankHMgr] = 1;
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

void
VegasCoordinator::sequence()
{
    for (int i=0; i < VegasCoordinatorId::quadrants; i++)
        if(childManager[i] && childUp(VegasCoordinatorId::BankAMgr + i))
            childManager[i]->sequence();
    Manager::sequence();
}

void
VegasCoordinator::initializeParameters()
{
    //------------------------------//
    // Clock Synthesizer Parameters //
    //------------------------------//
    int flash = 0;
    p[VegasCoordinatorId::flash] = new ControlParameter(
        &flash, sizeof(flash), this,
        (void (Manager::*)(void*))(&VegasCoordinator::flashDep),
        (int (Manager::*)(const void*))(&VegasCoordinator::flashChk),
        (int (Manager::*)(const void*))(&VegasCoordinator::flashAct),
        "flash");

    float frequency = 1000;
    p[VegasCoordinatorId::frequency] = new ControlParameter(
        &frequency, sizeof(frequency), this,
        (void (Manager::*)(void*))(&VegasCoordinator::frequencyDep),
        (int (Manager::*)(const void*))(&VegasCoordinator::frequencyChk),
        (int (Manager::*)(const void*))(&VegasCoordinator::frequencyAct),
        "frequency");

    char label[20] = "";
    p[VegasCoordinatorId::label] = new ControlParameter(
        label, 20 * sizeof(char), this,
        (void (Manager::*)(void*))(&VegasCoordinator::labelDep),
        (int (Manager::*)(const void*))(&VegasCoordinator::labelChk),
        (int (Manager::*)(const void*))(&VegasCoordinator::labelAct),
        "label");

    int ref_freq = 10000000;
    p[VegasCoordinatorId::ref_freq] = new ControlParameter(
        &ref_freq, sizeof(ref_freq), this,
        (void (Manager::*)(void*))(&VegasCoordinator::ref_freqDep),
        (int (Manager::*)(const void*))(&VegasCoordinator::ref_freqChk),
        (int (Manager::*)(const void*))(&VegasCoordinator::ref_freqAct),
        "ref_freq");

    int ref_freq_sel = 1;
    p[VegasCoordinatorId::ref_freq_sel] = new ControlParameter(
        &ref_freq_sel, sizeof(ref_freq_sel), this,
        (void (Manager::*)(void*))(&VegasCoordinator::ref_freq_selDep),
        (int (Manager::*)(const void*))(&VegasCoordinator::ref_freq_selChk),
        (int (Manager::*)(const void*))(&VegasCoordinator::ref_freq_selAct),
        "ref_freq_sel");

    vco_range vcor = {2200, 4400};
    p[VegasCoordinatorId::vco_range] = new ControlParameter(
        &vcor, sizeof(vcor), this,
        (void (Manager::*)(void*))(&VegasCoordinator::vco_rangeDep),
        (int (Manager::*)(const void*))(&VegasCoordinator::vco_rangeChk),
        (int (Manager::*)(const void*))(&VegasCoordinator::vco_rangeAct),
        "vco_range");
}

//------------------------------//
// Clock Synthesizer Parameters //
//------------------------------//
// flash
int
VegasCoordinator::flashAct(const int &flash)
{
    return 1;
}

int
VegasCoordinator::flashChk(const int &flash)
{
    return 1;
}

void
VegasCoordinator::flashDep(int &flash)
{
}

// frequency
int
VegasCoordinator::frequencyAct(const float &frequency)
{
    return 1;
}

int
VegasCoordinator::frequencyChk(const float &frequency)
{
    return 1;
}

void
VegasCoordinator::frequencyDep(float &frequency)
{
}

// label
int
VegasCoordinator::labelAct(const char *label)
{
    return 1;
}

int
VegasCoordinator::labelChk(const char *label)
{
    return 1;
}

void
VegasCoordinator::labelDep(char *label)
{
}

// ref_freq
int
VegasCoordinator::ref_freqAct(const int &ref_freq)
{
    return 1;
}

int
VegasCoordinator::ref_freqChk(const int &ref_freq)
{
    return 1;
}

void
VegasCoordinator::ref_freqDep(int &ref_freq)
{
}

// ref_freq_sel
int
VegasCoordinator::ref_freq_selAct(const int &ref_freq_sel)
{
    return 1;
}

int
VegasCoordinator::ref_freq_selChk(const int &ref_freq_sel)
{
    return 1;
}

void
VegasCoordinator::ref_freq_selDep(int &ref_freq_sel)
{
}

// vco_range
int
VegasCoordinator::vco_rangeAct(const vco_range &vcor)
{
    return 1;
}

int
VegasCoordinator::vco_rangeChk(const vco_range &vcor)
{
    if(vcor.min > vcor.max)
    {
        return 0;
    }
    return 1;
}

void
VegasCoordinator::vco_rangeDep(vco_range &vcor)
{
}
