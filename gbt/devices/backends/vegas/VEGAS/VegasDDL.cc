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

#include "VegasDDL.h"
#include "VegasId.h"

VegasMonitorDDL::VegasMonitorDDL(int base) : DataDescList()
{
    //DataDescriptionBranch *ddb;
    DataDescription *dd;

    //--------------------------------//
    // Spectrometer Monitor Registers //
    //--------------------------------//
    dd = new DataDescription(
        "actel_temp",
        "Actel chip temperature",
        base + actel_temp,
        BasicType::Float,
        BasicUnit::Celsius);
    addDescriptor(dd);

    dd = new DataDescription(
        "fpga_temp",
        "FPGA chip temperature",
        base + fpga_temp,
        BasicType::Float,
        BasicUnit::Celsius);
    addDescriptor(dd);

    dd = new DataDescription(
        "ppc_temp",
        "PowerPC temperature",
        base + ppc_temp,
        BasicType::Float,
        BasicUnit::Celsius);
    addDescriptor(dd);

    dd = new DataDescription(
        "1V",
        "1V voltage",
        base + p1v,
        BasicType::Float,
        BasicUnit::Volts);
    addDescriptor(dd);

    dd = new DataDescription(
        "1V Aux",
        "1V aux voltage",
        base + p1v_aux,
        BasicType::Float,
        BasicUnit::Volts);
    addDescriptor(dd);

    dd = new DataDescription(
        "1.5V",
        "1.5V voltage",
        base + p1v5,
        BasicType::Float,
        BasicUnit::Volts);
    addDescriptor(dd);

    dd = new DataDescription(
        "1.8V",
        "1.8V voltage",
        base + p1v8,
        BasicType::Float,
        BasicUnit::Volts);
    addDescriptor(dd);

    dd = new DataDescription(
        "2.5V",
        "2.5V voltage",
        base + p2v5,
        BasicType::Float,
        BasicUnit::Volts);
    addDescriptor(dd);

    dd = new DataDescription(
        "3.3V",
        "3.3V voltage",
        base + p3v3,
        BasicType::Float,
        BasicUnit::Volts);
    addDescriptor(dd);

    dd = new DataDescription(
        "5V",
        "5V voltage",
        base + p5v,
        BasicType::Float,
        BasicUnit::Volts);
    addDescriptor(dd);

    dd = new DataDescription(
        "12V",
        "12V voltage",
        base + p12v,
        BasicType::Float,
        BasicUnit::Volts);
    addDescriptor(dd);

}

VegasControlDDL::VegasControlDDL(unsigned long base) : ManagerDDL(base)
{
    //DataDescriptionBranch *ddb;
    DataDescription *dd;

    //--------------------------------//
    // Spectrometer Control Registers //
    //--------------------------------//
    dd = new DataDescription(
        "acc_len",
        "Number of spectra added in hardware accumulator",
        VegasId::acc_len,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "arm",
        "Resets hardware on next sync pulse",
        VegasId::arm,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "adc_snap0_ctrl",
        "Toggles a dump of raw ADC0 values",
        VegasId::adc_snap0_ctrl,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "adc_snap1_ctrl",
        "Toggles a dump of raw ADC1 values",
        VegasId::adc_snap1_ctrl,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "dest_ip",
        "Sets non-default destination IP address",
        VegasId::dest_ip,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "dest_ip_sel",
        "Toggles default or custom destination IP address",
        VegasId::dest_ip_sel,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "dest_port",
        "Sets non-default destination port",
        VegasId::dest_port,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "dest_port_sel",
        "Toggles default or custom destination port",
        VegasId::dest_port_sel,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "tint",
        "Spectra integration time",
        VegasId::tint,
        BasicType::Double,
        BasicUnit::MicroSeconds);
    addDescriptor(dd);

    dd = new DataDescription(
        "sync_period",
        "Sets the non-default sync period",
        VegasId::sync_period,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "sync_period_sel",
        "Toggles default or custom sync period",
        VegasId::sync_period_sel,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    // Shared memory parameters
    // dd = new DataDescription(
    //     "",
    //     "",
    //     VegasId::ID,
    //     BasicType::TYPE,
    //     BasicUnit::UNIT);
    // addDescriptor(dd);
}
