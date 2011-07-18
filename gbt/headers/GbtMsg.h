//# Copyright (C) 1996 Associated Universities, Inc. Washington DC, USA.
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

//# $Id: GbtMsg.h,v 1.24 2008/03/31 18:20:07 ashelton Exp $

#ifndef GbtMsg_h
#define GbtMsg_h

// <summary>
// a struct for paritioning the Message identifiers across all systems
// </summary>

// <use visibility=export>

// <prerequisite>
// Message.h
// </prerequisite>

// <synopsis>
// This struct partitions the Message identifiers by subsystem to insure that
// each message in the system has a unique id with 131072 messages allowed
// per device.  The 32-bit id space is divided with 256 devices containing
// up to 32 subdevices.  Each subdevice may have 4096 messages and 128
// message containing libraries.  Using IP addresss nomenclature, the
// identifier of any given message is device.subdevice.library.message
// where the possible sizes are 256.32.128.4096.
// <Pre>
// The current mask partitioning is:
//    3          2         1         0
//    10987654321098765432109876543210
//    DDDDDDDDSSSSSLLLLLLLMMMMMMMMMMMM
// Top 8 bits for devices               (255)
// Next 5 bits for device-subsystems    (31)
// Next 7 bits for system libraries     (127)
// Remaining 12 bits for messageOffsets (4095)
// </Pre>

// <H1>Message Id Rules</H1>
// <UL>
// <LI>Legal Device numbers are 0..255 	(see Note 1)</LI>
// <LI>Legal Subdevice numbers are 0..31 (see Note 2)</LI>
// <LI>Legal Library Numbers are 1..127, This field must be zero for
//     application messages.</LI>
// <LI>Legal Message Numbers are 1..4095.</LI>
// </UL>
//
// <H3>Note 1:</H3>
// Device number zero can be used only under certain conditions:
// <OL>
//      <LI>The message is in a library. e.g. The library Number != 0</LI>
//      <LI>The messages are transient in nature.</LI>
//      <LI>The messages are "anonymous". That is they are not associated
// 			with a system.</LI>
//      <LI>Anonymous messages are cleared by ANY systemUp/Down message
//          from the computer.</LI>
// </OL>
// If at all possible, avoid using "anonymous" messages.
//
// <H3>Note 2:</H3>
// Subdevice number zero, can be used, although the programmer should be
// aware that a systemUp/Down message from Device[N].Subdevice[0], will result
// in the clearing of all messages in all subdevices of Device[N], on the
// same machine. This is because the message system treats zero's in the
// systemUp/Down message-mask as wildcards.
//

// </synopsis>

// <example>
// <srcblock>
// #ifndef SPECTRALPROCESSORMSG_H
// #define SPECTRALPROCESSORMSG_H
//
// #include "GbtMsg.h"
// #include "ControlMsg.h"
//
// // This file contains the message enumerations for the Spectral Processor
// // as used by the Message library.
//
// struct SpectralProcessorMsg
// {
// 	// duplicated messages, i.e., used twice, once for each rack
// 	enum
// 	{
// 		// spectral processor rack
// 		lateStart = 1,
// 		BOMEMOVFLER,
// 		BOMEMSYNCERR,
// 		// etc
//
// 		// spectral processor
// 		SourceIllegal,
// 		activePhaseStateIllegal,
// 		actualBandwidthIllegal,
// 		// etc
//
// 		RackMsgCnt
// 	};
//
// 	// Total Messge domain for entire Spectral Processor
// 	enum
// 	{
// 		// Subsystems
// 		Sp	= GbtMsg::SpectralProcessor + 1*MsgDef::Subdevice,
// 		SpA	= GbtMsg::SpectralProcessor + 2*MsgDef::Subdevice,
// 		SpB	= GbtMsg::SpectralProcessor + 3*MsgDef::Subdevice,
// 		SpArack	= GbtMsg::SpectralProcessor + 4*MsgDef::Subdevice,
// 		SpBrack	= GbtMsg::SpectralProcessor + 5*MsgDef::Subdevice,
// 		SpSt	= GbtMsg::SpectralProcessor + 6*MsgDef::Subdevice,
//
// 		flushBuffer	= GbtMsg::SpectralProcessor + 1,
// 		diskFull,
// 		PolycoFileAccess,
// 		// etc
//
// 		MessageCnt
// 	};
// };
// </srcblock>
// </example>

#include "GbMsg.h"

struct GbtMsg
{
    enum
    {
        // Devices
        Antenna			= GbMsg::GBT + 0*MsgDef::Device,
        SpectralProcessor	= GbMsg::GBT + 1*MsgDef::Device,
        Dcr			= GbMsg::GBT + 2*MsgDef::Device,
        IFRack			= GbMsg::GBT + 3*MsgDef::Device,
        Spectrometer		= GbMsg::GBT + 4*MsgDef::Device,
        ActiveSurface		= GbMsg::GBT + 5*MsgDef::Device,
        Metrology		= GbMsg::GBT + 6*MsgDef::Device,
        Holography		= GbMsg::GBT + 7*MsgDef::Device,
        LO1			= GbMsg::GBT + 8*MsgDef::Device,
        SCCU_Simulator		= GbMsg::GBT + 9*MsgDef::Device,
        SwitchingSignalSelector	= GbMsg::GBT + 10*MsgDef::Device,
        AnalogFilterRack	= GbMsg::GBT + 11*MsgDef::Device,
        ConverterRack		= GbMsg::GBT + 12*MsgDef::Device,
        ActuatorCal		= GbMsg::GBT + 13*MsgDef::Device,
        Accelerometer		= GbMsg::GBT + 14*MsgDef::Device,
        Test			= GbMsg::GBT + 15*MsgDef::Device,
        MotorRack		= GbMsg::GBT + 16*MsgDef::Device,
        ServoMonitor		= GbMsg::GBT + 17*MsgDef::Device,
        Hvac			= GbMsg::GBT + 18*MsgDef::Device,
        PF_SupportRack		= GbMsg::GBT + 19*MsgDef::Device,
        RcvrPF_1		= GbMsg::GBT + 20*MsgDef::Device,
        RcvrPF_2		= GbMsg::GBT + 21*MsgDef::Device,
        Rcvr1_2			= GbMsg::GBT + 22*MsgDef::Device,
        Rcvr2_3			= GbMsg::GBT + 23*MsgDef::Device,
        Rcvr4_6			= GbMsg::GBT + 24*MsgDef::Device,
        Rcvr8_10		= GbMsg::GBT + 25*MsgDef::Device,
        Rcvr12_18		= GbMsg::GBT + 26*MsgDef::Device,
        Rcvr18_26		= GbMsg::GBT + 27*MsgDef::Device,
        Rcvr40_52		= GbMsg::GBT + 28*MsgDef::Device,
        Opc     		= GbMsg::GBT + 29*MsgDef::Device,
        ResetBox                = GbMsg::GBT + 30*MsgDef::Device,
        Measurements            = GbMsg::GBT + 31*MsgDef::Device,
        BCPM                    = GbMsg::GBT + 32*MsgDef::Device,
        QuadrantDetector        = GbMsg::GBT + 33*MsgDef::Device,
        AntennaCharacterization	= GbMsg::GBT + 34*MsgDef::Device,
        Rcvr26_40               = GbMsg::GBT + 35*MsgDef::Device,
        AVAILABLE               = GbMsg::GBT + 36*MsgDef::Device,
        Inclinometer            = GbMsg::GBT + 37*MsgDef::Device,
        MMConverter             = GbMsg::GBT + 38*MsgDef::Device,
        Rcvr_PAR                = GbMsg::GBT + 39*MsgDef::Device,
        LabSpectrometer         = GbMsg::GBT + 40*MsgDef::Device,
        CCB26_40                = GbMsg::GBT + 41*MsgDef::Device,
        CCB68_92                = GbMsg::GBT + 42*MsgDef::Device,
        Rcvr68_92               = GbMsg::GBT + 43*MsgDef::Device,
        Zpectrometer            = GbMsg::GBT + 44*MsgDef::Device,
        Guppi                   = GbMsg::GBT + 45*MsgDef::Device,
        Vegas                   = GbMsg::GBT + 46*MsgDef::Device,
    };
};

#endif
