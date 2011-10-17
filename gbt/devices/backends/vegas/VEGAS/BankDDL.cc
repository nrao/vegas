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

#include "BankDDL.h"
#include "VegasManagerId.h"

BankMonitorDDL::BankMonitorDDL(int base) : DataDescList()
{
    //--------------------------------//
    // Spectrometer Monitor Registers //
    //--------------------------------//
    
    // DataDescriptionBranch *ddb;
    DataDescription *dd;

    //----------------//
    // KATCP Monitors //
    //----------------//
    dd = new DataDescription(
        "spectra_ctr",
        "Number of accumulations sine last sync pulse",
        base + spectra_ctr,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "sync_ctr",
        "Number of syncs since last reset",
        base + sync_ctr,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    //------------------------//
    // Shared Memory Monitors //
    //------------------------//
    dd = new DataDescription(
        "acc_stat",
        "Status of CPU accumulator thread",
        base + acc_stat,
        STRINGOF(32),
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "disk_stat",
        "Status of disk thread",
        base + disk_stat,
        STRINGOF(32),
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "drop_avg",
        "Current packet drop rate",
        base + drop_avg,
        BasicType::Double,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "drop_tot",
        "Overall packet drop rate",
        base + drop_tot,
        BasicType::Double,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "gpu_stat",
        "Status of GPU thread",
        base + gpu_stat,
        STRINGOF(32),
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "ndrop",
        "Number of packets dropped",
        base + ndrop,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "net_stat",
        "Status of network thread",
        base + net_stat,
        STRINGOF(32),
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "npkt",
        "Number of packets received from ROACH",
        base + npkt,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "stt_imjd",
        "Measured observation start time (days)",
        base + stt_imjd,
        BasicType::Int,
        BasicUnit::Days);
    addDescriptor(dd);

    dd = new DataDescription(
        "stt_smjd",
        "Measured observation start time (seconds)",
        base + stt_smjd,
        BasicType::Int,
        BasicUnit::Seconds);
    addDescriptor(dd);

    dd = new DataDescription(
        "stt_offs",
        "Measured observation start time (partial seconds)",
        base + sync_ctr,
        BasicType::Double,
        BasicUnit::MicroSeconds); //!!! units?
    addDescriptor(dd);
}

BankControlDDL::BankControlDDL(unsigned long base) : ManagerDDL(base)
{
    // DataDescriptionBranch *ddb;
    DataDescription *dd;

    //----------------------//
    // FITS File Parameters //
    //----------------------//
    dd = new DataDescription(
        "blanking_time",
        "The blanking time in seconds",
        VegasManagerId::blanking_time,
        BasicType::Double,
        BasicUnit::Seconds);
    addDescriptor(dd);

    dd = new DataDescription(
        "cal",
        "Specifies whether cal switching is used",
        VegasManagerId::cal,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "freq_resolution",
        "TBD", //!!! ?
        VegasManagerId::freq_resolution,
        BasicType::Double,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "phase_start",
        "Specifies the duration of each switching state",
        VegasManagerId::phase_start,
        BasicType::Double,
        BasicUnit::Seconds);
    addDescriptor(dd);

    dd = new DataDescription(
        "polarization",
        "Selects whether cross polarization is computed",
        VegasManagerId::polarization,
        BasicType::Enum,
        BasicUnit::none,
        0,
        0,
        "polarization ( self, cross )");
    addDescriptor(dd);

    dd = new DataDescription(
        "sigref",
        "Specifies whether sigref switching is used",
        VegasManagerId::sigref,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "stokes_mode0",
        "Selects either total power or full stokes for sub-band 0",
        VegasManagerId::stokes_mode0,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "stokes_mode1",
        "Selects either total power or full stokes for sub-band 1",
        VegasManagerId::stokes_mode1,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "stokes_mode2",
        "Selects either total power or full stokes for sub-band 2",
        VegasManagerId::stokes_mode2,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "stokes_mode3",
        "Selects either total power or full stokes for sub-band 3",
        VegasManagerId::stokes_mode3,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "stokes_mode4",
        "Selects either total power or full stokes for sub-band 4",
        VegasManagerId::stokes_mode4,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "stokes_mode5",
        "Selects either total power or full stokes for sub-band 5",
        VegasManagerId::stokes_mode5,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "stokes_mode6",
        "Selects either total power or full stokes for sub-band 6",
        VegasManagerId::stokes_mode6,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "stokes_mode7",
        "Selects either total power or full stokes for sub-band 7",
        VegasManagerId::stokes_mode7,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "switching_source",
        "Selects either internally or externally generated switching signals",
        VegasManagerId::switching_source,
        BasicType::Enum,
        BasicUnit::none,
        0,
        0,
        "switching_source ( internal, external )");
    addDescriptor(dd);

    //------------------//
    // KATCP Parameters //
    //------------------//
    dd = new DataDescription(
        "acc_len",
        "Number of spectra added in hardware accumulator",
        VegasManagerId::acc_len,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "acc_len_sel",
        "Toggles default of custom accumulation length",
        VegasManagerId::acc_len_sel,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "arm",
        "Resets hardware on next sync pulse",
        VegasManagerId::arm,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "adc_snap0_ctrl",
        "Toggles a dump of raw ADC0 values",
        VegasManagerId::adc_snap0_ctrl,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "adc_snap1_ctrl",
        "Toggles a dump of raw ADC1 values",
        VegasManagerId::adc_snap1_ctrl,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "dest_ip",
        "Sets non-default destination IP address",
        VegasManagerId::dest_ip,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "dest_ip_sel",
        "Toggles default or custom destination IP address",
        VegasManagerId::dest_ip_sel,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "dest_port",
        "Sets non-default destination port",
        VegasManagerId::dest_port,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "dest_port_sel",
        "Toggles default or custom destination port",
        VegasManagerId::dest_port_sel,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "sync_period",
        "Sets the non-default sync period",
        VegasManagerId::sync_period,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "sync_period_sel",
        "Toggles default or custom sync period",
        VegasManagerId::sync_period_sel,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    //--------------------------//
    // Shared memory parameters //
    //--------------------------//
    dd = new DataDescription(
        "chan_bw",
        "Bandwidth of each spectral channel",
        VegasManagerId::chan_bw,
        BasicType::Double,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "datadir",
        "FITS output directory (only used when disk thread is running)",
        VegasManagerId::datadir,
        STRINGOF(64),
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "datahost",
        "Hostname of ROACH board",
        VegasManagerId::datahost,
        STRINGOF(32),
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "dataport",
        "UDP port to which ROACH board transmits packets",
        VegasManagerId::dataport,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "exposure",
        "Required integration time",
        VegasManagerId::exposure, //!!! tint?
        BasicType::Float,
        BasicUnit::Seconds);
    addDescriptor(dd);

    dd = new DataDescription(
        "filenum",
        "File number in multi-file scan (starts at 0 for each scan)",
        VegasManagerId::filenum,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "nchan",
        "Number of frequency channels per sub-band",
        VegasManagerId::nchan,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "npol",
        "Number of polarizations",
        VegasManagerId::npol,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "nsubband",
        "Number of sub-bands",
        VegasManagerId::nsubband,
        BasicType::Int,
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "pfb_rate",
        "Rate at which spectra are outputted from the PFB",
        VegasManagerId::pfb_rate,
        BasicType::Float,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "pkt_fmt",
        "TBD", //!!! ?
        VegasManagerId::pkt_fmt,
        STRINGOF(32),
        BasicUnit::none);
    addDescriptor(dd);

    dd = new DataDescription(
        "sub0_freq",
        "Center frequency of sub-band 0",
        VegasManagerId::sub0_freq,
        BasicType::Double,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "sub1_freq",
        "Center frequency of sub-band 1",
        VegasManagerId::sub1_freq,
        BasicType::Double,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "sub2_freq",
        "Center frequency of sub-band 2",
        VegasManagerId::sub2_freq,
        BasicType::Double,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "sub3_freq",
        "Center frequency of sub-band 3",
        VegasManagerId::sub3_freq,
        BasicType::Double,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "sub4_freq",
        "Center frequency of sub-band 4",
        VegasManagerId::sub4_freq,
        BasicType::Double,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "sub5_freq",
        "Center frequency of sub-band 5",
        VegasManagerId::sub5_freq,
        BasicType::Double,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "sub6_freq",
        "Center frequency of sub-band 6",
        VegasManagerId::sub6_freq,
        BasicType::Double,
        BasicUnit::Hertz);
    addDescriptor(dd);

    dd = new DataDescription(
        "sub7_freq",
        "Center frequency of sub-band 7",
        VegasManagerId::sub7_freq,
        BasicType::Double,
        BasicUnit::Hertz);
    addDescriptor(dd);

    //---//
    // ? //
    //---//
    // dd = new DataDescription(
    //     "tint",
    //     "Spectra integration time",
    //     VegasManagerId::tint,
    //     BasicType::Double,
    //     BasicUnit::MicroSeconds);
    // addDescriptor(dd);
}
