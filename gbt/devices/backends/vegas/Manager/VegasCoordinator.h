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

#ifndef VEGAS_COORDINATOR_H
#define VEGAS_COORDINATOR_H

// Local
#include "VegasCoordinatorId.h"
// YGOR
#include "Control.h"

class Synthesizer;

class VegasCoordinator : public Coordinator
{
public:
    VegasCoordinator();
    ~VegasCoordinator();

    void sequence();

protected:
    void initializeParameters();

    //------------------------------//
    // Clock Synthesizer Parameters //
    //------------------------------//
    int flashAct(const int &flash);
    int flashChk(const int &flash);
    void flashDep(int &flash);

    int frequencyAct(const float &frequency);
    int frequencyChk(const float &frequency);
    void frequencyDep(float &frequency);

    int labelAct(const char *label);
    int labelChk(const char *label);
    void labelDep(char *label);

    int ref_freqAct(const int &ref_freq);
    int ref_freqChk(const int &ref_freq);
    void ref_freqDep(int &ref_freq);

    int ref_freq_selAct(const int &ref_freq_sel);
    int ref_freq_selChk(const int &ref_freq_sel);
    void ref_freq_selDep(int &ref_freq_sel);

    int vco_rangeAct(const vco_range &vcor);
    int vco_rangeChk(const vco_range &vcor);
    void vco_rangeDep(vco_range &vcor);

private:
    PanelServer *server[VegasCoordinatorId::childCount];
    Manager *childManager[VegasCoordinatorId::childCount];

    Synthesizer *m_clk;
};

#endif//VEGAS_COORDINATOR_H
