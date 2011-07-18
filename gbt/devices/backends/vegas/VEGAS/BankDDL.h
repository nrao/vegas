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

#ifndef BANK_DDL_H
#define BANK_DDL_H

#include "DataDesc.h"
#include "ManagerDDL.h"

class BankMonitorDDL : public DataDescList
{
public:
    enum
    {
        actel_temp,
        // adc_snap0_bram_msb,
        // adc_snap0_bram_lsb,
        // adc_snap1_bram_msb,
        // adc_snap1_bram_lsb,
        fpga_temp,
        ppc_temp,
        p1v,
        p1v_aux,
        p1v5,
        p1v8,
        p2v5,
        p3v3,
        p5v,
        p12v,
        ParameterCnt
    };

    BankMonitorDDL(int base);
};

class BankControlDDL : public ManagerDDL
{
public:
    BankControlDDL(unsigned long base);
};

#endif//BANK_DDL_H
