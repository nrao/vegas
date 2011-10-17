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

#ifndef VEGAS_MANAGER_H
#define VEGAS_MANAGER_H

// Local
#include "Parameter.h"
#include "VegasManagerId.h"
#include "VegasMsg.h"

class RoachInterface;
//class Sampler;

class VegasManager : public ManagerSynchronous
{
public:
    VegasManager(const char *name, int base);
    ~VegasManager();

    void constructSamplers();
    void monitor();

protected:
    void initializeParameters();

    //----------------------//
    // FITS File Parameters //
    //----------------------//
    int blanking_timeAct(const double &blanking_time);
    int blanking_timeChk(const double &blanking_time);
    void blanking_timeDep(double &blanking_time);

    int calAct(const int &cal);
    int calChk(const int &cal);
    void calDep(int &cal);

    int freq_resolutionAct(const double &freq_resolution);
    int freq_resolutionChk(const double &freq_resolution);
    void freq_resolutionDep(double &freq_resolution);

    int phase_startAct(const double &phase_start);
    int phase_startChk(const double &phase_start);
    void phase_startDep(double &phase_start);

    int polarizationAct(const enum VegasManagerId::polarizationMode &polarization);
    int polarizationChk(const enum VegasManagerId::polarizationMode &polarization);
    void polarizationDep(enum VegasManagerId::polarizationMode &polarization);

    int sigrefAct(const int &sigref);
    int sigrefChk(const int &sigref);
    void sigrefDep(int &sigref);

    int stokes_mode0Act(const int &stokes_mode0);
    int stokes_mode0Chk(const int &stokes_mode0);
    void stokes_mode0Dep(int &stokes_mode0);

    int stokes_mode1Act(const int &stokes_mode1);
    int stokes_mode1Chk(const int &stokes_mode1);
    void stokes_mode1Dep(int &stokes_mode1);

    int stokes_mode2Act(const int &stokes_mode2);
    int stokes_mode2Chk(const int &stokes_mode2);
    void stokes_mode2Dep(int &stokes_mode2);

    int stokes_mode3Act(const int &stokes_mode3);
    int stokes_mode3Chk(const int &stokes_mode3);
    void stokes_mode3Dep(int &stokes_mode3);

    int stokes_mode4Act(const int &stokes_mode4);
    int stokes_mode4Chk(const int &stokes_mode4);
    void stokes_mode4Dep(int &stokes_mode4);

    int stokes_mode5Act(const int &stokes_mode5);
    int stokes_mode5Chk(const int &stokes_mode5);
    void stokes_mode5Dep(int &stokes_mode5);

    int stokes_mode6Act(const int &stokes_mode6);
    int stokes_mode6Chk(const int &stokes_mode6);
    void stokes_mode6Dep(int &stokes_mode6);

    int stokes_mode7Act(const int &stokes_mode7);
    int stokes_mode7Chk(const int &stokes_mode7);
    void stokes_mode7Dep(int &stokes_mode7);

    int switching_sourceAct(const enum VegasManagerId::switchingSource &switching_source);
    int switching_sourceChk(const enum VegasManagerId::switchingSource &switching_source);
    void switching_sourceDep(enum VegasManagerId::switchingSource &switching_source);

    //------------------//
    // KATCP Parameters //
    //------------------//
    int acc_lenAct(const int &acc_len);
    int acc_lenChk(const int &acc_len);
    void acc_lenDep(int &acc_len);

    int acc_len_selAct(const int &acc_len_sel);
    int acc_len_selChk(const int &acc_len_sel);
    void acc_len_selDep(int &acc_len_sel);

    int armAct(const int &arm);
    int armChk(const int &arm);
    void armDep(int &arm);

    int adc_snap0_ctrlAct(const int &adc_snap0_ctrl);
    int adc_snap0_ctrlChk(const int &adc_snap0_ctrl);
    void adc_snap0_ctrlDep(int &adc_snap0_ctrl);

    int adc_snap1_ctrlAct(const int &adc_snap1_ctrl);
    int adc_snap1_ctrlChk(const int &adc_snap1_ctrl);
    void adc_snap1_ctrlDep(int &adc_snap1_ctrl);

    int dest_ipAct(const int &dest_ip);
    int dest_ipChk(const int &dest_ip);
    void dest_ipDep(int &dest_ip);

    int dest_ip_selAct(const int &dest_ip_sel);
    int dest_ip_selChk(const int &dest_ip_sel);
    void dest_ip_selDep(int &dest_ip_sel);

    int dest_portAct(const int &dest_port);
    int dest_portChk(const int &dest_port);
    void dest_portDep(int &dest_port);

    int dest_port_selAct(const int &dest_port_sel);
    int dest_port_selChk(const int &dest_port_sel);
    void dest_port_selDep(int &dest_port_sel);

    int sync_periodAct(const int &sync_period);
    int sync_periodChk(const int &sync_period);
    void sync_periodDep(int &sync_period);

    int sync_period_selAct(const int &sync_period_sel);
    int sync_period_selChk(const int &sync_period_sel);
    void sync_period_selDep(int &sync_period_sel);

    //--------------------------//
    // Shared Memory Parameters //
    //--------------------------//
    int chan_bwAct(const double &chan_bw);
    int chan_bwChk(const double &chan_bw);
    void chan_bwDep(double &chan_bw);

    int datadirAct(const char *datadir);
    int datadirChk(const char *datadir);
    void datadirDep(char *datadir);

    int datahostAct(const char *datahost);
    int datahostChk(const char *datahost);
    void datahostDep(char *datahost);

    int dataportAct(const int &dataport);
    int dataportChk(const int &dataport);
    void dataportDep(int &dataport);

    int exposureAct(const float &exposure);
    int exposureChk(const float &exposure);
    void exposureDep(float &exposure);

    int filenumAct(const int &filenum);
    int filenumChk(const int &filenum);
    void filenumDep(int &filenum);

    int nchanAct(const int &nchan);
    int nchanChk(const int &nchan);
    void nchanDep(int &nchan);

    int npolAct(const int &npol);
    int npolChk(const int &npol);
    void npolDep(int &npol);

    int nsubbandAct(const int &nsubband);
    int nsubbandChk(const int &nsubband);
    void nsubbandDep(int &nsubband);

    int pfb_rateAct(const float &pfb_rate);
    int pfb_rateChk(const float &pfb_rate);
    void pfb_rateDep(float &pfb_rate);

    int pkt_fmtAct(const char *pkt_fmt);
    int pkt_fmtChk(const char *pkt_fmt);
    void pkt_fmtDep(char *pkt_fmt);

    int sub0_freqAct(const double &sub0_freq);
    int sub0_freqChk(const double &sub0_freq);
    void sub0_freqDep(double &sub0_freq);

    int sub1_freqAct(const double &sub1_freq);
    int sub1_freqChk(const double &sub1_freq);
    void sub1_freqDep(double &sub1_freq);

    int sub2_freqAct(const double &sub2_freq);
    int sub2_freqChk(const double &sub2_freq);
    void sub2_freqDep(double &sub2_freq);

    int sub3_freqAct(const double &sub3_freq);
    int sub3_freqChk(const double &sub3_freq);
    void sub3_freqDep(double &sub3_freq);

    int sub4_freqAct(const double &sub4_freq);
    int sub4_freqChk(const double &sub4_freq);
    void sub4_freqDep(double &sub4_freq);

    int sub5_freqAct(const double &sub5_freq);
    int sub5_freqChk(const double &sub5_freq);
    void sub5_freqDep(double &sub5_freq);

    int sub6_freqAct(const double &sub6_freq);
    int sub6_freqChk(const double &sub6_freq);
    void sub6_freqDep(double &sub6_freq);

    int sub7_freqAct(const double &sub7_freq);
    int sub7_freqChk(const double &sub7_freq);
    void sub7_freqDep(double &sub7_freq);

    // ?
    // int tintAct(const double &tint);
    // int tintChk(const double &tint);
    // void tintDep(double &tint);

    // int Act(const &);
    // int Chk(const &);
    // void Dep( &);

private:
    RoachInterface *ri;
    //ProposedStartTime sampleEstimatedStartTime();

    // Samplers?
};

#endif//VEGAS_MANAGER_H
