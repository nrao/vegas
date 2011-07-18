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

#ifndef VEGAS_MANAGER_ID_H
#define VEGAS_MANAGER_ID_H

#include "ManagerId.h"

struct VegasManagerId
{
    enum index
    {
        // Spectrometer control registers
        acc_len = ManagerId::ParameterCnt,
        arm,
        adc_snap0_ctrl,
        adc_snap1_ctrl,
        dest_ip,
        dest_ip_sel,
        dest_port,
        dest_port_sel,
        tint,
        sync_period,
        sync_period_sel,
        ParameterCnt
    };
};

#endif//VEGAS_MANAGER_ID_H
