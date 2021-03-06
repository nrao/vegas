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

#ifndef VEGASMSG_H
#define VEGASMSG_H

#include "GbtMsg.h"

struct VegasMsg
{
    enum
    {
        //!!! Need to edit GbtMsg to add this value
      Vegas    = GbtMsg::Vegas + 1*MsgDef::Subdevice,
      BankAMgr = GbtMsg::Vegas + 2*MsgDef::Subdevice,
      BankBMgr = GbtMsg::Vegas + 3*MsgDef::Subdevice,
      BankCMgr = GbtMsg::Vegas + 4*MsgDef::Subdevice,
      BankDMgr = GbtMsg::Vegas + 5*MsgDef::Subdevice,
      BankEMgr = GbtMsg::Vegas + 6*MsgDef::Subdevice,
      BankFMgr = GbtMsg::Vegas + 7*MsgDef::Subdevice,
      BankGMgr = GbtMsg::Vegas + 8*MsgDef::Subdevice,
      BankHMgr = GbtMsg::Vegas + 9*MsgDef::Subdevice,
    };
};

#endif//VEGASMSG_H
