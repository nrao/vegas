//# Copyright (C) 1998 Associated Universities, Inc. Washington DC, USA.
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

#include "CoordinatorDDL.h"
#include "VegasCoordinatorId.h"

CoordinatorMonitorDDL::CoordinatorMonitorDDL(int base) : DataDescList()
{
    // DataDescriptionBranch *ddb;
    // DataDescription *dd;
}

CoordinatorControlDDL::CoordinatorControlDDL(unsigned long base)
    		      : ManagerDDL(base)
{
    DataDescriptionBranch *ddb;
    DataDescription *dd;

    //------------------------------//
    // Clock Synthesizer Parameters //
    //------------------------------//
    dd = new DataDescription(
        "flash",
        "Flashes the current synthesizer settings to non-volatile memory",
        VegasCoordinatorId::flash,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "frequency",
        "Sets the synthesizer frequency",
        VegasCoordinatorId::frequency,
        BasicType::Float,
        BasicUnit::MegaHertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "label",
        "Sets the synthesizer label",
        VegasCoordinatorId::label,
        STRINGOF(20),
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "ref_freq",
        "Sets the synthesizer reference frequency (internal value, does not directly affect hardware)",
        VegasCoordinatorId::ref_freq,
        BasicType::Int,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "ref_freq_sel",
        "Toggles internal or external reference source",
        VegasCoordinatorId::ref_freq_sel,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    ddb = new DataDescriptionBranch(
        "vco_range",
        "Sets the output range of the synthesizer");
    ddb->addField(
        "vco_min",
        "Minimum VCO output (internal value, does not directly affect hardware)",
        BasicType::Short,
        BasicUnit::MegaHertz);
    ddb->addField(
        "vco_max",
        "Maximum VCO output (internal value, does not directly affect hardware)",
        BasicType::Short,
        BasicUnit::MegaHertz);
    dd = new DataDescription(
        "vco_range",
        "Sets the output range of the synthesizer",
        VegasCoordinatorId::vco_range,
        ddb);
    addDescriptor(dd);

    // TODO: Options
    // TODO: VCO min/max

}
