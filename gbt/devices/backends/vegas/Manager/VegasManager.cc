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

void VegasManager::initialize_parameters()
{
    int acc_len = 0;
    p[VegasManagerId::acc_len] = new ControlParameter(
    &acc_len, sizeof(acc_len), this,
    (void (Manager::*)(void*))(&VegasManager::acc_lenDep),
    (int (Manager::*)(const void*))(&VegasManager::acc_lenChk),
    (int (Manager::*)(const void*))(&VegasManager::acc_lenAct),
    "acc_len");

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

    double tint = 0;
    p[VegasManagerId::tint] = new ControlParameter(
    &tint, sizeof(tint), this,
    (void (Manager::*)(void*))(&VegasManager::tintDep),
    (int (Manager::*)(const void*))(&VegasManager::tintChk),
    (int (Manager::*)(const void*))(&VegasManager::tintAct),
    "tint");

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
}

//---------//
// acc_len //
//---------//
void
VegasManager::acc_lenDep(int &acc_len)
{
}

int
VegasManager::acc_lenChk(const int &acc_len)
{
    return 1;
}

int
VegasManager::acc_lenAct(const int &acc_len)
{
    return 1;
}

//-----//
// arm //
//-----//
void
VegasManager::armDep(int &arm)
{
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

int
VegasManager::armAct(const int &arm)
{
    return 1;
}

//----------------//
// adc_snap0_ctrl //
//----------------//
void
VegasManager::adc_snap0_ctrlDep(int &adc_snap0_ctrl)
{
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

int
VegasManager::adc_snap0_ctrlAct(const int &adc_snap0_ctrl)
{
    return 1;
}

//----------------//
// adc_snap1_ctrl //
//----------------//
void
VegasManager::adc_snap1_ctrlDep(int &adc_snap1_ctrl)
{
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

int
VegasManager::adc_snap1_ctrlAct(const int &adc_snap1_ctrl)
{
    return 1;
}

//---------//
// dest_ip //
//---------//
void
VegasManager::dest_ipDep(int &dest_ip)
{
}

int
VegasManager::dest_ipChk(const int &dest_ip)
{
    return 1;
}

int
VegasManager::dest_ipAct(const int &dest_ip)
{
    return 1;
}

//-------------//
// dest_ip_sel //
//-------------//
void
VegasManager::dest_ip_selDep(int &dest_ip_sel)
{
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

int
VegasManager::dest_ip_selAct(const int &dest_ip_sel)
{
    return 1;
}

//-----------//
// dest_port //
//-----------//
void
VegasManager::dest_portDep(int &dest_port)
{
}

int
VegasManager::dest_portChk(const int &dest_port)
{
    return 1;
}

int
VegasManager::dest_portAct(const int &dest_port)
{
    return 1;
}

//---------------//
// dest_port_sel //
//---------------//
void
VegasManager::dest_port_selDep(int &dest_port_sel)
{
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

int
VegasManager::dest_port_selAct(const int &dest_port_sel)
{
    return 1;
}

//-------------//
// sync_period //
//-------------//
void
VegasManager::sync_periodDep(int &sync_period)
{
}

int
VegasManager::sync_periodChk(const int &sync_period)
{
    return 1;
}

int
VegasManager::sync_periodAct(const int &sync_period)
{
    return 1;
}

//-----------------//
// sync_period_sel //
//-----------------//
void
VegasManager::sync_period_selDep(int &sync_period_sel)
{
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

int
VegasManager::sync_period_selAct(const int &sync_period_sel)
{
    return 1;
}

//------//
// tint //
//------//
void
VegasManager::tintDep(double &tint)
{
}

int
VegasManager::tintChk(const double &tint)
{
    if(tint < 0)
    {
        return 0;
    }
    return 1;
}

int
VegasManager::tintAct(const double &tint)
{
    return 1;
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
VegasManager::VegasManager()
    :
    ManagerSynchronous(VegasManagerId::ParameterCnt, "Vegas", VegasMsg::Vegas)
{
    setParameter(p[ManagerId::debugLevel], ManagerId::NoDebugLevel);

    // Init parameters

    initialize_parameters();
    int success = init();
    if(!success)
    {
        //std::cout << "Vegas init failed" << std::endl;
    }
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
