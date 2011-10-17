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

// Local
#include "VegasManager.h"
#include "VegasManagerId.h"

void VegasManager::initializeParameters()
{
    //---------------------//
    // FITS File Paramters //
    //---------------------//
    double blanking_time = 0.25;
    p[VegasManagerId::blanking_time] = new ControlParameter(
        &blanking_time, sizeof(blanking_time), this,
        (void (Manager::*)(void*))(&VegasManager::blanking_timeDep),
        (int (Manager::*)(const void*))(&VegasManager::blanking_timeChk),
        (int (Manager::*)(const void*))(&VegasManager::blanking_timeAct),
        "blanking_time");

    int cal = 0;
    p[VegasManagerId::cal] = new ControlParameter(
        &cal, sizeof(cal), this,
        (void (Manager::*)(void*))(&VegasManager::calDep),
        (int (Manager::*)(const void*))(&VegasManager::calChk),
        (int (Manager::*)(const void*))(&VegasManager::calAct),
        "cal");

    double freq_resolution = 0;
    p[VegasManagerId::freq_resolution] = new ControlParameter(
        &freq_resolution, sizeof(freq_resolution), this,
        (void (Manager::*)(void*))(&VegasManager::freq_resolutionDep),
        (int (Manager::*)(const void*))(&VegasManager::freq_resolutionChk),
        (int (Manager::*)(const void*))(&VegasManager::freq_resolutionAct),
        "freq_resolution");

    double phase_start = 0;
    p[VegasManagerId::phase_start] = new ControlParameter(
        &phase_start, sizeof(phase_start), this,
        (void (Manager::*)(void*))(&VegasManager::phase_startDep),
        (int (Manager::*)(const void*))(&VegasManager::phase_startChk),
        (int (Manager::*)(const void*))(&VegasManager::phase_startAct),
        "phase_start");

    enum VegasManagerId::polarizationMode polarization = VegasManagerId::self;
    p[VegasManagerId::polarization] = new ControlParameter(
        &polarization, sizeof(polarization), this,
        (void (Manager::*)(void*))(&VegasManager::polarizationDep),
        (int (Manager::*)(const void*))(&VegasManager::polarizationChk),
        (int (Manager::*)(const void*))(&VegasManager::polarizationAct),
        "polarization");

    int sigref = 0;
    p[VegasManagerId::sigref] = new ControlParameter(
        &sigref, sizeof(sigref), this,
        (void (Manager::*)(void*))(&VegasManager::sigrefDep),
        (int (Manager::*)(const void*))(&VegasManager::sigrefChk),
        (int (Manager::*)(const void*))(&VegasManager::sigrefAct),
        "sigref");

    int stokes_mode0 = 0;
    p[VegasManagerId::stokes_mode0] = new ControlParameter(
        &stokes_mode0, sizeof(stokes_mode0), this,
        (void (Manager::*)(void*))(&VegasManager::stokes_mode0Dep),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode0Chk),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode0Act),
        "stokes_mode0");

    int stokes_mode1 = 0;
    p[VegasManagerId::stokes_mode1] = new ControlParameter(
        &stokes_mode1, sizeof(stokes_mode1), this,
        (void (Manager::*)(void*))(&VegasManager::stokes_mode1Dep),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode1Chk),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode1Act),
        "stokes_mode1");

    int stokes_mode2 = 0;
    p[VegasManagerId::stokes_mode2] = new ControlParameter(
        &stokes_mode2, sizeof(stokes_mode2), this,
        (void (Manager::*)(void*))(&VegasManager::stokes_mode2Dep),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode2Chk),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode2Act),
        "stokes_mode2");

    int stokes_mode3 = 0;
    p[VegasManagerId::stokes_mode3] = new ControlParameter(
        &stokes_mode3, sizeof(stokes_mode3), this,
        (void (Manager::*)(void*))(&VegasManager::stokes_mode3Dep),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode3Chk),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode3Act),
        "stokes_mode3");

    int stokes_mode4 = 0;
    p[VegasManagerId::stokes_mode4] = new ControlParameter(
        &stokes_mode4, sizeof(stokes_mode4), this,
        (void (Manager::*)(void*))(&VegasManager::stokes_mode4Dep),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode4Chk),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode4Act),
        "stokes_mode4");

    int stokes_mode5 = 0;
    p[VegasManagerId::stokes_mode5] = new ControlParameter(
        &stokes_mode5, sizeof(stokes_mode5), this,
        (void (Manager::*)(void*))(&VegasManager::stokes_mode5Dep),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode5Chk),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode5Act),
        "stokes_mode5");

    int stokes_mode6 = 0;
    p[VegasManagerId::stokes_mode6] = new ControlParameter(
        &stokes_mode6, sizeof(stokes_mode6), this,
        (void (Manager::*)(void*))(&VegasManager::stokes_mode6Dep),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode6Chk),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode6Act),
        "stokes_mode6");

    int stokes_mode7 = 0;
    p[VegasManagerId::stokes_mode7] = new ControlParameter(
        &stokes_mode7, sizeof(stokes_mode7), this,
        (void (Manager::*)(void*))(&VegasManager::stokes_mode7Dep),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode7Chk),
        (int (Manager::*)(const void*))(&VegasManager::stokes_mode7Act),
        "stokes_mode7");

    int switching_source = 0;
    p[VegasManagerId::switching_source] = new ControlParameter(
        &switching_source, sizeof(switching_source), this,
        (void (Manager::*)(void*))(&VegasManager::switching_sourceDep),
        (int (Manager::*)(const void*))(&VegasManager::switching_sourceChk),
        (int (Manager::*)(const void*))(&VegasManager::switching_sourceAct),
        "switching_source");

    //------------------//
    // KATCP Parameters //
    //------------------//
    int acc_len = 0;
    p[VegasManagerId::acc_len] = new ControlParameter(
        &acc_len, sizeof(acc_len), this,
        (void (Manager::*)(void*))(&VegasManager::acc_lenDep),
        (int (Manager::*)(const void*))(&VegasManager::acc_lenChk),
        (int (Manager::*)(const void*))(&VegasManager::acc_lenAct),
        "acc_len");

    int acc_len_sel = 0;
    p[VegasManagerId::acc_len_sel] = new ControlParameter(
        &acc_len_sel, sizeof(acc_len_sel), this,
        (void (Manager::*)(void*))(&VegasManager::acc_len_selDep),
        (int (Manager::*)(const void*))(&VegasManager::acc_len_selChk),
        (int (Manager::*)(const void*))(&VegasManager::acc_len_selAct),
        "acc_len_sel");

    int arm = 0;
    p[VegasManagerId::arm] = new ControlParameter(
        &arm, sizeof(arm), this,
        (void (Manager::*)(void*))(&VegasManager::armDep),
        (int (Manager::*)(const void*))(&VegasManager::armChk),
        (int (Manager::*)(const void*))(&VegasManager::armAct),
        "arm");
    
    int adc_snap0_ctrl = 0;
    p[VegasManagerId::adc_snap0_ctrl] = new ControlParameter(
        &adc_snap0_ctrl , sizeof(adc_snap0_ctrl), this,
        (void (Manager::*)(void*))(&VegasManager::adc_snap0_ctrlDep),
        (int (Manager::*)(const void*))(&VegasManager::adc_snap0_ctrlChk),
        (int (Manager::*)(const void*))(&VegasManager::adc_snap0_ctrlAct),
        "adc_snap0_ctrl");

    int adc_snap1_ctrl = 0;
    p[VegasManagerId::adc_snap1_ctrl] = new ControlParameter(
        &adc_snap1_ctrl , sizeof(adc_snap1_ctrl), this,
        (void (Manager::*)(void*))(&VegasManager::adc_snap1_ctrlDep),
        (int (Manager::*)(const void*))(&VegasManager::adc_snap1_ctrlChk),
        (int (Manager::*)(const void*))(&VegasManager::adc_snap1_ctrlAct),
        "adc_snap1_ctrl");

    int dest_ip = 0;
    p[VegasManagerId::dest_ip] = new ControlParameter(
        &dest_ip, sizeof(dest_ip), this,
        (void (Manager::*)(void*))(&VegasManager::dest_ipDep),
        (int (Manager::*)(const void*))(&VegasManager::dest_ipChk),
        (int (Manager::*)(const void*))(&VegasManager::dest_ipAct),
        "dest_ip");

    int dest_ip_sel = 0;
    p[VegasManagerId::dest_ip_sel] = new ControlParameter(
        &dest_ip_sel, sizeof(dest_ip_sel), this,
        (void (Manager::*)(void*))(&VegasManager::dest_ip_selDep),
        (int (Manager::*)(const void*))(&VegasManager::dest_ip_selChk),
        (int (Manager::*)(const void*))(&VegasManager::dest_ip_selAct),
        "dest_ip_sel");

    int dest_port = 0;
    p[VegasManagerId::dest_port] = new ControlParameter(
        &dest_port, sizeof(dest_port), this,
        (void (Manager::*)(void*))(&VegasManager::dest_portDep),
        (int (Manager::*)(const void*))(&VegasManager::dest_portChk),
        (int (Manager::*)(const void*))(&VegasManager::dest_portAct),
        "dest_port");

    int dest_port_sel = 0;
    p[VegasManagerId::dest_port_sel] = new ControlParameter(
        &dest_port_sel, sizeof(dest_port_sel), this,
        (void (Manager::*)(void*))(&VegasManager::dest_port_selDep),
        (int (Manager::*)(const void*))(&VegasManager::dest_port_selChk),
        (int (Manager::*)(const void*))(&VegasManager::dest_port_selAct),
        "dest_port_sel");

    int sync_period = 0;
    p[VegasManagerId::sync_period] = new ControlParameter(
        &sync_period, sizeof(sync_period), this,
        (void (Manager::*)(void*))(&VegasManager::sync_periodDep),
        (int (Manager::*)(const void*))(&VegasManager::sync_periodChk),
        (int (Manager::*)(const void*))(&VegasManager::sync_periodAct),
        "sync_period");

    int sync_period_sel = 0;
    p[VegasManagerId::sync_period_sel] = new ControlParameter(
        &sync_period_sel, sizeof(sync_period_sel), this,
        (void (Manager::*)(void*))(&VegasManager::sync_period_selDep),
        (int (Manager::*)(const void*))(&VegasManager::sync_period_selChk),
        (int (Manager::*)(const void*))(&VegasManager::sync_period_selAct),
        "sync_period_sel");

    //--------------------------//
    // Shared Memory Parameters //
    //--------------------------//
    double chan_bw = 0;
    p[VegasManagerId::chan_bw] = new ControlParameter(
        &chan_bw, sizeof(chan_bw), this,
        (void (Manager::*)(void*))(&VegasManager::chan_bwDep),
        (int (Manager::*)(const void*))(&VegasManager::chan_bwChk),
        (int (Manager::*)(const void*))(&VegasManager::chan_bwAct),
        "chan_bw");

    char datadir[64] = "";
    p[VegasManagerId::datadir] = new ControlParameter(
        datadir, 64 * sizeof(char), this,
        (void (Manager::*)(void*))(&VegasManager::datadirDep),
        (int (Manager::*)(const void*))(&VegasManager::datadirChk),
        (int (Manager::*)(const void*))(&VegasManager::datadirAct),
        "datadir");

    char datahost[32] = "";
    p[VegasManagerId::datahost] = new ControlParameter(
        datahost, 32 * sizeof(char), this,
        (void (Manager::*)(void*))(&VegasManager::datahostDep),
        (int (Manager::*)(const void*))(&VegasManager::datahostChk),
        (int (Manager::*)(const void*))(&VegasManager::datahostAct),
        "datahost");

    int dataport = 0;
    p[VegasManagerId::dataport] = new ControlParameter(
        &dataport, sizeof(dataport), this,
        (void (Manager::*)(void*))(&VegasManager::dataportDep),
        (int (Manager::*)(const void*))(&VegasManager::dataportChk),
        (int (Manager::*)(const void*))(&VegasManager::dataportAct),
        "dataport");

    float exposure = 0;
    p[VegasManagerId::exposure] = new ControlParameter(
        &exposure, sizeof(exposure), this,
        (void (Manager::*)(void*))(&VegasManager::exposureDep),
        (int (Manager::*)(const void*))(&VegasManager::exposureChk),
        (int (Manager::*)(const void*))(&VegasManager::exposureAct),
        "exposure");

    int filenum = 0;
    p[VegasManagerId::filenum] = new ControlParameter(
        &filenum, sizeof(filenum), this,
        (void (Manager::*)(void*))(&VegasManager::filenumDep),
        (int (Manager::*)(const void*))(&VegasManager::filenumChk),
        (int (Manager::*)(const void*))(&VegasManager::filenumAct),
        "filenum");

    int nchan = 0;
    p[VegasManagerId::nchan] = new ControlParameter(
        &nchan, sizeof(nchan), this,
        (void (Manager::*)(void*))(&VegasManager::nchanDep),
        (int (Manager::*)(const void*))(&VegasManager::nchanChk),
        (int (Manager::*)(const void*))(&VegasManager::nchanAct),
        "nchan");

    int npol = 2;
    p[VegasManagerId::npol] = new ControlParameter(
        &npol, sizeof(npol), this,
        (void (Manager::*)(void*))(&VegasManager::npolDep),
        (int (Manager::*)(const void*))(&VegasManager::npolChk),
        (int (Manager::*)(const void*))(&VegasManager::npolAct),
        "npol");

    int nsubband = 1;
    p[VegasManagerId::nsubband] = new ControlParameter(
        &nsubband, sizeof(nsubband), this,
        (void (Manager::*)(void*))(&VegasManager::nsubbandDep),
        (int (Manager::*)(const void*))(&VegasManager::nsubbandChk),
        (int (Manager::*)(const void*))(&VegasManager::nsubbandAct),
        "nsubband");

    float pfb_rate = 0;
    p[VegasManagerId::pfb_rate] = new ControlParameter(
        &pfb_rate, sizeof(pfb_rate), this,
        (void (Manager::*)(void*))(&VegasManager::pfb_rateDep),
        (int (Manager::*)(const void*))(&VegasManager::pfb_rateChk),
        (int (Manager::*)(const void*))(&VegasManager::pfb_rateAct),
        "pfb_rate");

    char pkt_fmt[32] = "SPEAD";
    p[VegasManagerId::pkt_fmt] = new ControlParameter(
        pkt_fmt, 32 * sizeof(char), this,
        (void (Manager::*)(void*))(&VegasManager::pkt_fmtDep),
        (int (Manager::*)(const void*))(&VegasManager::pkt_fmtChk),
        (int (Manager::*)(const void*))(&VegasManager::pkt_fmtAct),
        "pkt_fmt");

    double sub0_freq = 0;
    p[VegasManagerId::sub0_freq] = new ControlParameter(
        &sub0_freq, sizeof(sub0_freq), this,
        (void (Manager::*)(void*))(&VegasManager::sub0_freqDep),
        (int (Manager::*)(const void*))(&VegasManager::sub0_freqChk),
        (int (Manager::*)(const void*))(&VegasManager::sub0_freqAct),
        "sub0_freq");

    double sub1_freq = 0;
    p[VegasManagerId::sub1_freq] = new ControlParameter(
        &sub1_freq, sizeof(sub1_freq), this,
        (void (Manager::*)(void*))(&VegasManager::sub1_freqDep),
        (int (Manager::*)(const void*))(&VegasManager::sub1_freqChk),
        (int (Manager::*)(const void*))(&VegasManager::sub1_freqAct),
        "sub1_freq");

    double sub2_freq = 0;
    p[VegasManagerId::sub2_freq] = new ControlParameter(
        &sub2_freq, sizeof(sub2_freq), this,
        (void (Manager::*)(void*))(&VegasManager::sub2_freqDep),
        (int (Manager::*)(const void*))(&VegasManager::sub2_freqChk),
        (int (Manager::*)(const void*))(&VegasManager::sub2_freqAct),
        "sub2_freq");

    double sub3_freq = 0;
    p[VegasManagerId::sub3_freq] = new ControlParameter(
        &sub3_freq, sizeof(sub3_freq), this,
        (void (Manager::*)(void*))(&VegasManager::sub3_freqDep),
        (int (Manager::*)(const void*))(&VegasManager::sub3_freqChk),
        (int (Manager::*)(const void*))(&VegasManager::sub3_freqAct),
        "sub3_freq");

    double sub4_freq = 0;
    p[VegasManagerId::sub4_freq] = new ControlParameter(
        &sub4_freq, sizeof(sub4_freq), this,
        (void (Manager::*)(void*))(&VegasManager::sub4_freqDep),
        (int (Manager::*)(const void*))(&VegasManager::sub4_freqChk),
        (int (Manager::*)(const void*))(&VegasManager::sub4_freqAct),
        "sub4_freq");

    double sub5_freq = 0;
    p[VegasManagerId::sub5_freq] = new ControlParameter(
        &sub5_freq, sizeof(sub5_freq), this,
        (void (Manager::*)(void*))(&VegasManager::sub5_freqDep),
        (int (Manager::*)(const void*))(&VegasManager::sub5_freqChk),
        (int (Manager::*)(const void*))(&VegasManager::sub5_freqAct),
        "sub5_freq");

    double sub6_freq = 0;
    p[VegasManagerId::sub6_freq] = new ControlParameter(
        &sub6_freq, sizeof(sub6_freq), this,
        (void (Manager::*)(void*))(&VegasManager::sub6_freqDep),
        (int (Manager::*)(const void*))(&VegasManager::sub6_freqChk),
        (int (Manager::*)(const void*))(&VegasManager::sub6_freqAct),
        "sub6_freq");

    double sub7_freq = 0;
    p[VegasManagerId::sub7_freq] = new ControlParameter(
        &sub7_freq, sizeof(sub7_freq), this,
        (void (Manager::*)(void*))(&VegasManager::sub7_freqDep),
        (int (Manager::*)(const void*))(&VegasManager::sub7_freqChk),
        (int (Manager::*)(const void*))(&VegasManager::sub7_freqAct),
        "sub7_freq");

    // ?
    // double tint = 0;
    // p[VegasManagerId::tint] = new ControlParameter(
    //     &tint, sizeof(tint), this,
    //     (void (Manager::*)(void*))(&VegasManager::tintDep),
    //     (int (Manager::*)(const void*))(&VegasManager::tintChk),
    //     (int (Manager::*)(const void*))(&VegasManager::tintAct),
    //     "tint");
}

//----------------------//
// FITS File Parameters //
//----------------------//
// blanking_time
int
VegasManager::blanking_timeAct(const double &blanking_time)
{
    return 1;
}

int
VegasManager::blanking_timeChk(const double &blanking_time)
{
    return 1;
}

void
VegasManager::blanking_timeDep(double &blanking_time)
{
}

// cal
int
VegasManager::calAct(const int &cal)
{
    return 1;
}

int
VegasManager::calChk(const int &cal)
{
    if((cal < 0) || (cal > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::calDep(int &cal)
{
}

// freq_resolution
int
VegasManager::freq_resolutionAct(const double &freq_resolution)
{
    return 1;
}

int
VegasManager::freq_resolutionChk(const double &freq_resolution)
{
    if(freq_resolution < 0)
    {
        return 0;
    }
    return 1;
}

void
VegasManager::freq_resolutionDep(double &freq_resolution)
{
}

// phase_start
int
VegasManager::phase_startAct(const double &phase_start)
{
    return 1;
}

int
VegasManager::phase_startChk(const double &phase_start)
{
    if((phase_start < 0) || (phase_start > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::phase_startDep(double &phase_start)
{
}

// polarization
int
VegasManager::polarizationAct(
    const enum VegasManagerId::polarizationMode &polarization)
{
    return 1;
}

int
VegasManager::polarizationChk(
    const enum VegasManagerId::polarizationMode &polarization)
{
    if((polarization != VegasManagerId::self) &&
       (polarization != VegasManagerId::cross))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::polarizationDep(
    enum VegasManagerId::polarizationMode &polarization)
{
}

// sigref
int
VegasManager::sigrefAct(const int &sigref)
{
    return 1;
}

int
VegasManager::sigrefChk(const int &sigref)
{
    if((sigref < 0) || (sigref > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::sigrefDep(int &sigref)
{
}

// stokes_mode0
int
VegasManager::stokes_mode0Act(const int &stokes_mode0)
{
    return 1;
}

int
VegasManager::stokes_mode0Chk(const int &stokes_mode0)
{
    if((stokes_mode0 < 0) || (stokes_mode0 > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::stokes_mode0Dep(int &stokes_mode0)
{
}

// stokes_mode1
int
VegasManager::stokes_mode1Act(const int &stokes_mode1)
{
    return 1;
}

int
VegasManager::stokes_mode1Chk(const int &stokes_mode1)
{
    if((stokes_mode1 < 0) || (stokes_mode1 > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::stokes_mode1Dep(int &stokes_mode1)
{
}

// stokes_mode2
int
VegasManager::stokes_mode2Act(const int &stokes_mode2)
{
    return 1;
}

int
VegasManager::stokes_mode2Chk(const int &stokes_mode2)
{
    if((stokes_mode2 < 0) || (stokes_mode2 > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::stokes_mode2Dep(int &stokes_mode2)
{
}

// stokes_mode3
int
VegasManager::stokes_mode3Act(const int &stokes_mode3)
{
    return 1;
}

int
VegasManager::stokes_mode3Chk(const int &stokes_mode3)
{
    if((stokes_mode3 < 0) || (stokes_mode3 > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::stokes_mode3Dep(int &stokes_mode3)
{
}

// stokes_mode4
int
VegasManager::stokes_mode4Act(const int &stokes_mode4)
{
    return 1;
}

int
VegasManager::stokes_mode4Chk(const int &stokes_mode4)
{
    if((stokes_mode4 < 0) || (stokes_mode4 > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::stokes_mode4Dep(int &stokes_mode4)
{
}

// stokes_mode5
int
VegasManager::stokes_mode5Act(const int &stokes_mode5)
{
    return 1;
}

int
VegasManager::stokes_mode5Chk(const int &stokes_mode5)
{
    if((stokes_mode5 < 0) || (stokes_mode5 > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::stokes_mode5Dep(int &stokes_mode5)
{
}

// stokes_mode6
int
VegasManager::stokes_mode6Act(const int &stokes_mode6)
{
    return 1;
}

int
VegasManager::stokes_mode6Chk(const int &stokes_mode6)
{
    if((stokes_mode6 < 0) || (stokes_mode6 > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::stokes_mode6Dep(int &stokes_mode6)
{
}

// stokes_mode7
int
VegasManager::stokes_mode7Act(const int &stokes_mode7)
{
    return 1;
}

int
VegasManager::stokes_mode7Chk(const int &stokes_mode7)
{
    if((stokes_mode7 < 0) || (stokes_mode7 > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::stokes_mode7Dep(int &stokes_mode7)
{
}

// switching_source
int
VegasManager::switching_sourceAct(
    const enum VegasManagerId::switchingSource &switching_source)
{
    return 1;
}

int
VegasManager::switching_sourceChk(
    const enum VegasManagerId::switchingSource &switching_source)
{
    if((switching_source != VegasManagerId::internal) &&
       (switching_source != VegasManagerId::external))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::switching_sourceDep(
    enum VegasManagerId::switchingSource &switching_source)
{
}

//------------------//
// KATCP Parameters //
//------------------//
// acc_len
int
VegasManager::acc_lenAct(const int &acc_len)
{
    std::ostringstream parse;
    parse << acc_len;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "acc_len", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::acc_lenChk(const int &acc_len)
{
    return 1;
}

void
VegasManager::acc_lenDep(int &acc_len)
{
}

// acc_len_sel
int
VegasManager::acc_len_selAct(const int &acc_len_sel)
{
    std::ostringstream parse;
    parse << acc_len_sel;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "acc_len_sel", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::acc_len_selChk(const int &acc_len_sel)
{
    if((acc_len_sel < 0) || (acc_len_sel > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::acc_len_selDep(int &acc_len_sel)
{
}

// arm
int
VegasManager::armAct(const int &arm)
{
    std::ostringstream parse;
    parse << arm;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "arm", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::armChk(const int &arm)
{
    if((arm < 0) || (arm > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::armDep(int &arm)
{
}

// adc_snap0_ctrl
int
VegasManager::adc_snap0_ctrlAct(const int &adc_snap0_ctrl)
{
    std::ostringstream parse;
    parse << adc_snap0_ctrl;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "adc_snap0_ctrl", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::adc_snap0_ctrlChk(const int &adc_snap0_ctrl)
{
    if((adc_snap0_ctrl < 0) || (adc_snap0_ctrl > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::adc_snap0_ctrlDep(int &adc_snap0_ctrl)
{
}

// adc_snap1_ctrl
int
VegasManager::adc_snap1_ctrlAct(const int &adc_snap1_ctrl)
{
    std::ostringstream parse;
    parse << adc_snap1_ctrl;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "adc_snap1_ctrl", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::adc_snap1_ctrlChk(const int &adc_snap1_ctrl)
{
    if((adc_snap1_ctrl < 0) || (adc_snap1_ctrl > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::adc_snap1_ctrlDep(int &adc_snap1_ctrl)
{
}

// dest_ip
int
VegasManager::dest_ipAct(const int &dest_ip)
{
    std::ostringstream parse;
    parse << dest_ip;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "dest_ip", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::dest_ipChk(const int &dest_ip)
{
    return 1;
}

void
VegasManager::dest_ipDep(int &dest_ip)
{
}

// dest_ip_sel
int
VegasManager::dest_ip_selAct(const int &dest_ip_sel)
{
    std::ostringstream parse;
    parse << dest_ip_sel;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "dest_ip_sel", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::dest_ip_selChk(const int &dest_ip_sel)
{
    if((dest_ip_sel < 0) || (dest_ip_sel > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::dest_ip_selDep(int &dest_ip_sel)
{
}

// dest_port
int
VegasManager::dest_portAct(const int &dest_port)
{
    std::ostringstream parse;
    parse << dest_port;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "dest_port", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::dest_portChk(const int &dest_port)
{
    return 1;
}

void
VegasManager::dest_portDep(int &dest_port)
{
}

// dest_port_sel
int
VegasManager::dest_port_selAct(const int &dest_port_sel)
{
    std::ostringstream parse;
    parse << dest_port_sel;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "dest_port_sel", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::dest_port_selChk(const int &dest_port_sel)
{
    if((dest_port_sel < 0) || (dest_port_sel > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::dest_port_selDep(int &dest_port_sel)
{
}

// sync_period
int
VegasManager::sync_periodAct(const int &sync_period)
{
    std::ostringstream parse;
    parse << sync_period;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "sync_period", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::sync_periodChk(const int &sync_period)
{
    return 1;
}

void
VegasManager::sync_periodDep(int &sync_period)
{
}

// sync_period_sel
int
VegasManager::sync_period_selAct(const int &sync_period_sel)
{
    std::ostringstream parse;
    parse << sync_period_sel;
    ri->sendMessage(KatcpType::REQUEST, "wordwrite",
                    "sync_period_sel", "0", parse.str().c_str());
    
    // TBF: This is potentially a bad idea; if the ROACH fails to generate
    // an appropriate message, the manager hangs.
    KatcpMessage reply;
    do
    {
        reply = ri.recvMessage();
    } while((reply.type() != KatcpType::REPLY) &&
            (reply.name() != "wordwrite"));
    return reply.args()[0] == Katcp::success;
}

int
VegasManager::sync_period_selChk(const int &sync_period_sel)
{
    if((sync_period_sel < 0) || (sync_period_sel > 1))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::sync_period_selDep(int &sync_period_sel)
{
}

//--------------------------//
// Shared Memory Parameters //
//--------------------------//
// chan_bw
int
VegasManager::chan_bwAct(const double &chan_bw)
{
    return 1;
}

int
VegasManager::chan_bwChk(const double &chan_bw)
{
    return 1;
}

void
VegasManager::chan_bwDep(double &chan_bw)
{
}

// datadir
int
VegasManager::datadirAct(const char *datadir)
{
    return 1;
}

int
VegasManager::datadirChk(const char *datadir)
{
    if(!datadir)
    {
        return 0;
    }
    return 1;
}

void
VegasManager::datadirDep(char *datadir)
{
}

// datahost
int
VegasManager::datahostAct(const char *datahost)
{
    return 1;
}

int
VegasManager::datahostChk(const char *datahost)
{
    if(!datahost)
    {
        return 0;
    }
    return 1;
}

void
VegasManager::datahostDep(char *datahost)
{
}

// dataport
int
VegasManager::dataportAct(const int &dataport)
{
    return 1;
}

int
VegasManager::dataportChk(const int &dataport)
{
    return 1;
}

void
VegasManager::dataportDep(int &dataport)
{
}

// exposure
int
VegasManager::exposureAct(const float &exposure)
{
    return 1;
}

int
VegasManager::exposureChk(const float &exposure)
{
    return 1;
}

void
VegasManager::exposureDep(float &exposure)
{
}

// filenum
int
VegasManager::filenumAct(const int &filenum)
{
    return 1;
}

int
VegasManager::filenumChk(const int &filenum)
{
    return 1;
}

void
VegasManager::filenumDep(int &filenum)
{
}

// nchan
int
VegasManager::nchanAct(const int &nchan)
{
    return 1;
}

int
VegasManager::nchanChk(const int &nchan)
{
    return 1;
}

void
VegasManager::nchanDep(int &nchan)
{
}

// npol
int
VegasManager::npolAct(const int &npol)
{
    return 1;
}

int
VegasManager::npolChk(const int &npol)
{
    if(npol != 2)
    {
        return 0;
    }
    return 1;
}

void
VegasManager::npolDep(int &npol)
{
}

// nsubband
int
VegasManager::nsubbandAct(const int &nsubband)
{
    return 1;
}

int
VegasManager::nsubbandChk(const int &nsubband)
{
    if((nsubband != 1) && (nsubband != 8))
    {
        return 0;
    }
    return 1;
}

void
VegasManager::nsubbandDep(int &nsubband)
{
}

// pfb_rate
int
VegasManager::pfb_rateAct(const float &pfb_rate)
{
    return 1;
}

int
VegasManager::pfb_rateChk(const float &pfb_rate)
{
    return 1;
}

void
VegasManager::pfb_rateDep(float &pfb_rate)
{
}

// pkt_fmt
int
VegasManager::pkt_fmtAct(const char *pkt_fmt)
{
    return 1;
}

int
VegasManager::pkt_fmtChk(const char *pkt_fmt)
{
    if(!pkt_fmt)
    {
        return 0;
    }
    return 1;
}

void
VegasManager::pkt_fmtDep(char *pkt_fmt)
{
}

// sub0_freq
int
VegasManager::sub0_freqAct(const double &sub0_freq)
{
    return 1;
}

int
VegasManager::sub0_freqChk(const double &sub0_freq)
{
    return 1;
}

void
VegasManager::sub0_freqDep(double &sub0_freq)
{
}

// sub1_freq
int
VegasManager::sub1_freqAct(const double &sub1_freq)
{
    return 1;
}

int
VegasManager::sub1_freqChk(const double &sub1_freq)
{
    return 1;
}

void
VegasManager::sub1_freqDep(double &sub1_freq)
{
}

// sub2_freq
int
VegasManager::sub2_freqAct(const double &sub2_freq)
{
    return 1;
}

int
VegasManager::sub2_freqChk(const double &sub2_freq)
{
    return 1;
}

void
VegasManager::sub2_freqDep(double &sub2_freq)
{
}

// sub3_freq
int
VegasManager::sub3_freqAct(const double &sub3_freq)
{
    return 1;
}

int
VegasManager::sub3_freqChk(const double &sub3_freq)
{
    return 1;
}

void
VegasManager::sub3_freqDep(double &sub3_freq)
{
}

// sub4_freq
int
VegasManager::sub4_freqAct(const double &sub4_freq)
{
    return 1;
}

int
VegasManager::sub4_freqChk(const double &sub4_freq)
{
    return 1;
}

void
VegasManager::sub4_freqDep(double &sub4_freq)
{
}

// sub5_freq
int
VegasManager::sub5_freqAct(const double &sub5_freq)
{
    return 1;
}

int
VegasManager::sub5_freqChk(const double &sub5_freq)
{
    return 1;
}

void
VegasManager::sub5_freqDep(double &sub5_freq)
{
}

// sub6_freq
int
VegasManager::sub6_freqAct(const double &sub6_freq)
{
    return 1;
}

int
VegasManager::sub6_freqChk(const double &sub6_freq)
{
    return 1;
}

void
VegasManager::sub6_freqDep(double &sub6_freq)
{
}

// sub7_freq
int
VegasManager::sub7_freqAct(const double &sub7_freq)
{
    return 1;
}

int
VegasManager::sub7_freqChk(const double &sub7_freq)
{
    return 1;
}

void
VegasManager::sub7_freqDep(double &sub7_freq)
{
}


//-------------------//
// constructSamplers //
//-------------------//
void
VegasManager::constructSamplers()
{
    // DeviceAccessContainer *dac = DeviceAccessContainer::instance("VEGAS");
    // float actel_temp;
    // actel_temp = dac->construct_Sampler_by_Id(
    //     GbtMsg::Vegas + VegasMonitorDDL::actel_temp, &actel_temp, 2);
}

//---------//
// monitor //
//---------//
void
VegasManager::monitor()
{
}

//-------------//
// Constructor //
//-------------//
VegasManager::VegasManager(const char *name, int base)
    :
    ManagerSynchronous(VegasManagerId::ParameterCnt, name, base),
    ri(0)
{
    setParameter(p[ManagerId::debugLevel], ManagerId::NoDebugLevel);

    // Init parameters
    initializeParameters();
    int success = init();
    if(!success)
    {
        std::cout << "Bank initialization failed" << std::endl;
    }

    //TDF: Pull roach details out of config file
    ri = new RoachInterface("", 7147);
}

//------------//
// Destructor //
//------------//
VegasManager::~VegasManager()
{
    for(int i = ManagerId::ParameterCnt; i < pn; ++i)
    {
        delete p[i];
    }
}
