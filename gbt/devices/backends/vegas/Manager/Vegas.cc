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
#include "Vegas.h"
#include "VegasId.h"


//---------//
// acc_len //
//---------//
void
Vegas::acc_lenDep(int &acc_len)
{
}

int
Vegas::acc_lenChk(const int &acc_len)
{
    return 1;
}

int
Vegas::acc_lenAct(const int &acc_len)
{
    return 1;
}

//-----//
// arm //
//-----//
void
Vegas::armDep(int &arm)
{
}

int
Vegas::armChk(const int &arm)
{
    if((arm < 0) || (arm > 1))
    {
        return 0;
    }
    return 1;
}

int
Vegas::armAct(const int &arm)
{
    return 1;
}

//----------------//
// adc_snap0_ctrl //
//----------------//
void
Vegas::adc_snap0_ctrlDep(int &adc_snap0_ctrl)
{
}

int
Vegas::adc_snap0_ctrlChk(const int &adc_snap0_ctrl)
{
    if((adc_snap0_ctrl < 0) || (adc_snap0_ctrl > 1))
    {
        return 0;
    }
    return 1;
}

int
Vegas::adc_snap0_ctrlAct(const int &adc_snap0_ctrl)
{
    return 1;
}

//----------------//
// adc_snap1_ctrl //
//----------------//
void
Vegas::adc_snap1_ctrlDep(int &adc_snap1_ctrl)
{
}

int
Vegas::adc_snap1_ctrlChk(const int &adc_snap1_ctrl)
{
    if((adc_snap1_ctrl < 0) || (adc_snap1_ctrl > 1))
    {
        return 0;
    }
    return 1;
}

int
Vegas::adc_snap1_ctrlAct(const int &adc_snap1_ctrl)
{
    return 1;
}

//---------//
// dest_ip //
//---------//
void
Vegas::dest_ipDep(int &dest_ip)
{
}

int
Vegas::dest_ipChk(const int &dest_ip)
{
    return 1;
}

int
Vegas::dest_ipAct(const int &dest_ip)
{
    return 1;
}

//-------------//
// dest_ip_sel //
//-------------//
void
Vegas::dest_ip_selDep(int &dest_ip_sel)
{
}

int
Vegas::dest_ip_selChk(const int &dest_ip_sel)
{
    if((dest_ip_sel < 0) || (dest_ip_sel > 1))
    {
        return 0;
    }
    return 1;
}

int
Vegas::dest_ip_selAct(const int &dest_ip_sel)
{
    return 1;
}

//-----------//
// dest_port //
//-----------//
void
Vegas::dest_portDep(int &dest_port)
{
}

int
Vegas::dest_portChk(const int &dest_port)
{
    return 1;
}

int
Vegas::dest_portAct(const int &dest_port)
{
    return 1;
}

//---------------//
// dest_port_sel //
//---------------//
void
Vegas::dest_port_selDep(int &dest_port_sel)
{
}

int
Vegas::dest_port_selChk(const int &dest_port_sel)
{
    if((dest_port_sel < 0) || (dest_port_sel > 1))
    {
        return 0;
    }
    return 1;
}

int
Vegas::dest_port_selAct(const int &dest_port_sel)
{
    return 1;
}

//-------------//
// sync_period //
//-------------//
void
Vegas::sync_periodDep(int &sync_period)
{
}

int
Vegas::sync_periodChk(const int &sync_period)
{
    return 1;
}

int
Vegas::sync_periodAct(const int &sync_period)
{
    return 1;
}

//-----------------//
// sync_period_sel //
//-----------------//
void
Vegas::sync_period_selDep(int &sync_period_sel)
{
}

int
Vegas::sync_period_selChk(const int &sync_period_sel)
{
    if((sync_period_sel < 0) || (sync_period_sel > 1))
    {
        return 0;
    }
    return 1;
}

int
Vegas::sync_period_selAct(const int &sync_period_sel)
{
    return 1;
}

//------//
// tint //
//------//
void
Vegas::tintDep(double &tint)
{
}

int
Vegas::tintChk(const double &tint)
{
    if(tint < 0)
    {
        return 0;
    }
    return 1;
}

int
Vegas::tintAct(const double &tint)
{
    return 1;
}

//-------------------//
// constructSamplers //
//-------------------//
void
Vegas::constructSamplers()
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
Vegas::monitor()
{
}

//-------------//
// Constructor //
//-------------//
Vegas::Vegas()
    :
    ManagerSynchronous(VegasId::ParameterCnt, "Vegas", VegasMsg::Vegas)
{
    setParameter(p[ManagerId::debugLevel], ManagerId::NoDebugLevel);

    // Init parameters

    int success = init();
    if(!success)
    {
        //std::cout << "Vegas init failed" << std::endl;
    }
}

//------------//
// Destructor //
//------------//
Vegas::~Vegas()
{
    for(int i = ManagerId::ParameterCnt; i < pn; ++i)
    {
        delete p[i];
    }
}
