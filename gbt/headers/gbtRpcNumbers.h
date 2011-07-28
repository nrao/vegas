/*
// Copyright (C) 1993 Associated Universities, Inc. Washington DC, USA.
// 
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
// 
// This program is distributed in the hope that it will be useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the GNU
// General Public License for more details.
// 
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software
// Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.
// 
// Correspondence concerning GBT software should be addressed as follows:
//	GBT Operations
//	National Radio Astronomy Observatory
//	P. O. Box 2
//	Green Bank, WV 24944-0002 USA
// $Id: gbtRpcNumbers.h,v 1.35 2008/03/31 18:20:07 ashelton Exp $
*/
#ifndef GBT_RPC_NUMBERS
#define GBT_RPC_NUMBERS

#include "gbRpcNumbers.h"


/* The GBT is allocated 0x1000 (4096) numbers to use, plus these 4 
RSI defined numbers.  If you need more, go back and define another
block of 0x1000 numbers.

*/

/* RSI/PCD Servo Control Program Numbers */
const long CmdProgramNumber 			= RSIGbtRpcBase + 0x02;
const long StatusProgramNumber 			= RSIGbtRpcBase + 0x03;
const long LoadRecallProgramNumber 		= RSIGbtRpcBase + 0x04;
const long PositionProgramNumber 		= RSIGbtRpcBase + 0x05;


const int DBM_WINDOW_RPC_PROG 			= gbtRpcBase + 0x02;

const int ActiveSurfaceBase			= gbtRpcBase + 0x100;
const int AS_RPC_PROG 				= ActiveSurfaceBase + 0;	
const int AS_RPC_TEST 				= ActiveSurfaceBase + 1;
const int ActiveSurfaceMgr_PANEL		= ActiveSurfaceBase + 2;
const int ActiveSurfaceServo_PANEL              = ActiveSurfaceBase + 3;

/*0x29000200 - 0x290002ff Antenna and Pointing prognums*/
const int AntennaProgramBase 			= gbtRpcBase + 0x200;
const int AntennaMgrPanel     			= AntennaProgramBase + 0x0;
const int AntennaMgrRecip   			= AntennaProgramBase + 0x1;
const int AntennaCoordPanel			= AntennaProgramBase + 0x2;
const int AntennaCoordRecip			= AntennaProgramBase + 0x3;
const int AdderProgram           		= AntennaProgramBase + 0x10;
/* Corrector Related Program Numbers */
const int FocusTrackProgram      		= AntennaProgramBase + 0x20;
const int FocusTrackPanel     			= FocusTrackProgram + 1;
const int FocusTrackRecip   				= FocusTrackProgram + 2;
const int BasicModelProgram      		= AntennaProgramBase + 0x30;
const int BasicModelPanel     			= BasicModelProgram + 1;
const int BasicModelRecip   				= BasicModelProgram + 2;
const int GroundRefProgram       		= AntennaProgramBase + 0x40;
const int GroundRefPanel      			= GroundRefProgram + 1;
const int MetrologyProgram             = AntennaProgramBase + 0x50;
const int MetrologyEtc                 = MetrologyProgram + 1;

/* The following is a family of managers for the quadrant detector.
   The first one is the data collection manager.  At least one more is
   on the drawing boards.
*/
const int QuadrantDetector            = AntennaProgramBase + 0x60;
const int QDDataAcquisitionMgrPanel      = QuadrantDetector + 1;


/*0x29000300 - 0x290003ff M&C misc prognums*/
const int MiscProgramNumBase 			= gbtRpcBase + 0x300;
const int SIB_PANEL_RPC_PROG 			= MiscProgramNumBase + 0;

/******** OVLBI_RTPM_RPC_PROG is hard coded since the OVLBI project uses */
/* it but can't access this file, do not change its value!!!! */
/*const int OVLBI_RTPM_RPC_PROG 			= 0x29000301; */

const int MC_GET_TIME_RPC 			= MiscProgramNumBase + 2;
const int ScanIndexer                           = MiscProgramNumBase + 3;

/* Servers needed for Spectrometer to balance its inputs. */
const int AnalogFilterRackReadPower             = MiscProgramNumBase + 4;
const int ConverterRackSetAttenuator            = MiscProgramNumBase + 5;

/* MCB Server */
const int MCBServerRPCNumTTYS0                  = MiscProgramNumBase + 6;
const int MCBServerRPCNumTTYS1                  = MiscProgramNumBase + 7;
const int MCBServerRPCNumTTYS2                  = MiscProgramNumBase + 8;
const int MCBServerRPCNumTTYS3                  = MiscProgramNumBase + 9;

/* Panel prognums */
/* 0x29000400 - 0x290005ff */
const int PanelNumBase  			= gbtRpcBase + 0x400;
const int RC40_52_PANEL 			= PanelNumBase + 0x0;
const int IFRack_PANEL				= PanelNumBase + 0x1;
const int SpRackA_PANEL 			= PanelNumBase + 0x2;
const int ActuatorCal_PANEL			= PanelNumBase + 0x3;
const int SpRackB_PANEL 			= PanelNumBase + 0x4;
const int IFRackRouter_PANEL			= PanelNumBase + 0x5;
const int ScanCoord_PANEL			= PanelNumBase + 0x6;
const int IFRackNoise_PANEL			= PanelNumBase + 0x7;
const int RC18_26_PANEL 			= PanelNumBase + 0x8;
const int ConverterRack_PANEL			= PanelNumBase + 0x9;
const int SpStoragePANEL 			= PanelNumBase + 0xa;
const int RC1_2_PANEL 				= PanelNumBase + 0xb;	
const int SPLO_PANEL				= PanelNumBase + 0xc;
const int G1_PANEL				= PanelNumBase + 0xd;
const int Measurements_PANEL		 	= PanelNumBase + 0xe;
const int G2_PANEL			 	= PanelNumBase + 0xf;
const int G3_PANEL 		 		= PanelNumBase + 0x11;
const int G4_PANEL		 		= PanelNumBase + 0x13;
const int SpSpA_PANEL 				= PanelNumBase + 0x14;
const int CM1_PANEL 				= PanelNumBase + 0x15;
const int SpSpB_PANEL 				= PanelNumBase + 0x16;
const int CM2_PANEL 				= PanelNumBase + 0x17;
const int SpSp_PANEL 				= PanelNumBase + 0x18;
const int available_1				= PanelNumBase + 0x19;
const int ConverterAttenuatorServerProgNum	= PanelNumBase + 0x1b;
const int RC12_18_PANEL 			= PanelNumBase + 0x1e;
const int RCPF1_PANEL	 			= PanelNumBase + 0x1f;
const int RC08_10_PANEL 			= PanelNumBase + 0x20;
const int RegistryCoordinatorPANEL     		= PanelNumBase + 0x24;
const int ResetBoxPANEL                         = PanelNumBase + 0x25;
const int gbtrba_PANEL                          = PanelNumBase + 0x26;
const int gbtrbas_PANEL                         = PanelNumBase + 0x27;
const int gbtrbeq_PANEL                         = PanelNumBase + 0x28;
const int gbtrbrc_PANEL                         = PanelNumBase + 0x29;
const int DataMgr_PANEL                		= PanelNumBase + 0x2c;
const int Dcr_PANEL 				= PanelNumBase + 0x2f;
const int LO1Router_PANEL			= PanelNumBase + 0x30;
const int LO1Counter_PANEL 			= PanelNumBase + 0x34;
const int HolographyPANEL			= PanelNumBase + 0x35;
const int HoloTransporter			= PanelNumBase + 0x36;
const int LO1Coordinator_PANEL			= PanelNumBase + 0x37;
const int LO1A_PANEL				= PanelNumBase + 0x39;
const int LO1B_PANEL				= PanelNumBase + 0x3a;
const int CM3_PANEL				= PanelNumBase + 0x3b;
const int SwitchingSignalSelector_PANEL     	= PanelNumBase + 0x3e;
const int RC4_6_PANEL 				= PanelNumBase + 0x3f;

// For the analog filter rack hardware
const int SG1_PANEL                   = PanelNumBase + 0x40;
const int SG2_PANEL                   = PanelNumBase + 0x41;
const int SG3_PANEL                   = PanelNumBase + 0x42;
const int SG4_PANEL                   = PanelNumBase + 0x43;
const int SG5_PANEL                   = PanelNumBase + 0x44;
const int SG6_PANEL                   = PanelNumBase + 0x45;
const int SG7_PANEL                   = PanelNumBase + 0x46;
const int SG8_PANEL                   = PanelNumBase + 0x47;
const int CF1_PANEL                   = PanelNumBase + 0x48;
const int CF2_PANEL                   = PanelNumBase + 0x49;
const int CF3_PANEL                   = PanelNumBase + 0x4a;
const int CF4_PANEL                   = PanelNumBase + 0x4b;
const int CF5_PANEL                   = PanelNumBase + 0x4c;
const int CF6_PANEL                   = PanelNumBase + 0x4d;
const int CF7_PANEL                   = PanelNumBase + 0x4e;
const int CF8_PANEL                   = PanelNumBase + 0x4f;
const int CF9_PANEL                   = PanelNumBase + 0x50;
const int CF10_PANEL                  = PanelNumBase + 0x51;
const int CF11_PANEL                  = PanelNumBase + 0x52;
const int CF12_PANEL                  = PanelNumBase + 0x53;
const int CF13_PANEL                  = PanelNumBase + 0x54;
const int CF14_PANEL                  = PanelNumBase + 0x55;
const int CF15_PANEL                  = PanelNumBase + 0x56;
const int CF16_PANEL                  = PanelNumBase + 0x57;
const int AnalogFilterRack_PANEL      = PanelNumBase + 0x58;

//Converter Rack stuff
// The rest of these are spread out among the above numbers to fill
// in the unused_XX entries

const int CM4_PANEL				= PanelNumBase + 0x5a;
const int CM5_PANEL				= PanelNumBase + 0x5b;
const int CM6_PANEL				= PanelNumBase + 0x5c;
const int CM7_PANEL				= PanelNumBase + 0x5d;
const int CM8_PANEL				= PanelNumBase + 0x5e;
const int CM9_PANEL				= PanelNumBase + 0x5f;
const int CM10_PANEL				= PanelNumBase + 0x60;
const int CM11_PANEL				= PanelNumBase + 0x61;
const int CM12_PANEL				= PanelNumBase + 0x62;
const int CM13_PANEL				= PanelNumBase + 0x63;
const int CM14_PANEL				= PanelNumBase + 0x64;
const int CM15_PANEL				= PanelNumBase + 0x65;
const int CM16_PANEL				= PanelNumBase + 0x66;

// Gigatronics 
const int G5_PANEL				= PanelNumBase + 0x67;
const int G6_PANEL				= PanelNumBase + 0x68;
const int G7_PANEL				= PanelNumBase + 0x69;
const int G8_PANEL				= PanelNumBase + 0x6a;

// ****
// **** note this uses 8 prognums ****
// ***
const int IFRackDriverBase_PANEL	= PanelNumBase + 0x6b;
const int IFRackDriverBase_foo2		= PanelNumBase + 0x6c;
const int IFRackDriverBase_foo3		= PanelNumBase + 0x6d;
const int IFRackDriverBase_foo4		= PanelNumBase + 0x6e;
const int IFRackDriverBase_foo5		= PanelNumBase + 0x6f;
const int IFRackDriverBase_foo6		= PanelNumBase + 0x70;
const int IFRackDriverBase_foo7		= PanelNumBase + 0x71;
const int IFRackDriverBase_foo8		= PanelNumBase + 0x72;

const int PMTest_PANEL                  = PanelNumBase + 0x73;

// Accelerometer manager and 6 submanagers
const int Accelerometer_PANEL           = PanelNumBase + 0x74;
const int Accelerometer1_PANEL          = PanelNumBase + 0x75;
const int Accelerometer2_PANEL          = PanelNumBase + 0x76;
const int Accelerometer3_PANEL          = PanelNumBase + 0x77;
const int Accelerometer4_PANEL          = PanelNumBase + 0x78;
const int Accelerometer5_PANEL          = PanelNumBase + 0x79;
const int Accelerometer6_PANEL          = PanelNumBase + 0x7a;
const int Accelerometer7_PANEL          = PanelNumBase + 0x7b;

const int VacuumControl_PANEL           = PanelNumBase + 0x7c;
const int RC2_3_PANEL                   = PanelNumBase + 0x7d;
const int MotorRack_PANEL               = PanelNumBase + 0x7e;
const int FeedDefroster_PANEL           = PanelNumBase + 0x7f;
const int RefrigPwr_A_PANEL             = PanelNumBase + 0x80;
const int RefrigPwr_B_PANEL             = PanelNumBase + 0x81;
const int RefrigPwr_C_PANEL             = PanelNumBase + 0x82;
const int RefrigPwr_D_PANEL             = PanelNumBase + 0x83;
const int RefrigPwr_E_PANEL             = PanelNumBase + 0x84;
const int ServoMonitor_PANEL		= PanelNumBase + 0x85;
const int Hvac_PANEL			= PanelNumBase + 0x86;
const int Spectrometer_PANEL		= PanelNumBase + 0x87;
const int SpectrometerTesting_PANEL	= PanelNumBase + 0x88;
const int SpectrometerBankA_PANEL	= PanelNumBase + 0x89;
const int SpectrometerBankB_PANEL	= PanelNumBase + 0x8a;
const int SpectrometerBankC_PANEL	= PanelNumBase + 0x8b;
const int SpectrometerBankD_PANEL	= PanelNumBase + 0x8c;
const int SpectrometerPulsar_PANEL	= PanelNumBase + 0x8d;
const int SpectrometerBankCommon_PANEL	= PanelNumBase + 0x8e;
const int PF_SupportRack_PANEL		= PanelNumBase + 0x8f;
const int IFCOND_PANEL                  = PanelNumBase + 0x90;
const int TEMP_CTRL_A_PANEL             = PanelNumBase + 0x91;
const int TEMP_CTRL_B_PANEL             = PanelNumBase + 0x92;
const int RC3_4_PANEL                   = PanelNumBase + 0x93;
const int RC6_8_PANEL                   = PanelNumBase + 0x94;
const int RC10_12_PANEL                 = PanelNumBase + 0x95;
const int RC15_18_PANEL                 = PanelNumBase + 0x96;
const int RC26_40_PANEL                 = PanelNumBase + 0x97;
const int OpcPANEL                      = PanelNumBase + 0x98;

const int BCPM_PANEL                    = PanelNumBase + 0x99;
const int BCPM1_PANEL                   = PanelNumBase + 0x9a;
const int BCPM2_PANEL                   = PanelNumBase + 0x9b;

const int RCPF2_PANEL                   = PanelNumBase + 0x9c;	 

const int AntennaCharacterization_PANEL = PanelNumBase + 0x9d;
const int StructureTemperature_PANEL    = PanelNumBase + 0x9e;
const int AirTemperature_PANEL          = PanelNumBase + 0x9f;
const int AVAILABLE_a0                  = PanelNumBase + 0xa0;  

const int Inclinometer_PANEL            = PanelNumBase + 0xa1;
const int MMConverter1_PANEL            = PanelNumBase + 0xa2;
const int MMConverter2_PANEL            = PanelNumBase + 0xa3;
const int MMConverter3_PANEL            = PanelNumBase + 0xa4;
const int MMConverter4_PANEL            = PanelNumBase + 0xa5;
const int MMConverterCrd_PANEL          = PanelNumBase + 0xa6;
const int RC_PA_PANEL                   = PanelNumBase + 0xa7;

// Lab Spectrometer
const int LabSpectrometer_PANEL		= PanelNumBase + 0xa8;
const int LabSpectrometerTesting_PANEL	= PanelNumBase + 0xa9;
const int LabSpectrometerBankA_PANEL	= PanelNumBase + 0xaa;
const int LabSpectrometerBankCommon_PANEL = PanelNumBase + 0xab;

const int CCB26_40_PANEL                = PanelNumBase + 0xac;  
const int CCB68_92_PANEL                = PanelNumBase + 0xad;  
const int RC68_92_PANEL                 = PanelNumBase + 0xae;
const int Zpectrometer_PANEL            = PanelNumBase + 0xaf;
const int QuadrantDetector_PANEL        = PanelNumBase + 0xb0;
const int GUPPI_PANEL                   = PanelNumBase + 0xb1;
const int RC_ARRAY18_26_PANEL           = PanelNumBase + 0xb2;

// Vegas 
const int VegasCoordinator_PANEL        = PanelNumBase + 0xb3;
const int VegasBankA_PANEL              = PanelNumBase + 0xb4;
const int VegasBankB_PANEL              = PanelNumBase + 0xb5;
const int VegasBankC_PANEL              = PanelNumBase + 0xb6;
const int VegasBankD_PANEL              = PanelNumBase + 0xb7;
const int VegasBankE_PANEL              = PanelNumBase + 0xb8;
const int VegasBankF_PANEL              = PanelNumBase + 0xb9;
const int VegasBankG_PANEL              = PanelNumBase + 0xba;
const int VegasBankH_PANEL              = PanelNumBase + 0xbb;

const int firstUnusedPanelNum           = PanelNumBase + 0xbc;

/* DCR prognums */
/* 0x29000800 - 0x290008ff */
const int DCRBase                       = gbtRpcBase + 0x800;
const int DCR_TRANSPORTER		= DCRBase + 0;

/* Holography prognums */
/* 0x29000900 - 0x290009ff */
const int HolographyBase		= gbtRpcBase + 0x900;
const int HOLO_TRANSPORTER		= HolographyBase + 0;
/* Optical Pointing Camera */
const int OPCBase                       = gbtRpcBase + 0xA00;


/******************* RPC ADDRESS ALLOCATIONS AND DEFINITIONS **/

#endif
