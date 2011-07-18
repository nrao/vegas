//Application
#include "configfilefactory.h"
#include "managername.h"
#include "threadedsamplerfactory.h"
#include "common.h"
#include "cryoled.h"
#include "cryolna.h"
#include "lnadrain.h"
#include "mcbcal.h"
#include "mcblclext.h"
#include "noisecal.h"
#include "noisesrc.h"
#include "idmtype1.h"
#include "idmtype2.h"
#include "calcntrlb0.h"
#include "calcntrlb1.h"

//Standard Library
#include <stdexcept>
#include <vector>

ThreadedSamplerFactory::ThreadedSamplerFactory(IMonCtrlMod* mcm)
                       : monitorControlModule(mcm)
{
}

void ThreadedSamplerFactory::Create(map<unsigned short, ThreadedSampler*>& smap)
{
    createCommonMonitor();
    createCryoLEDMonitor();
    createCryoLNAMonitor();
    createLNADrainMonitor();
    createMCBCalMonitor();
    createMCBLclExtMonitor();
    createNoiseCalMonitor();
    createNoiseSrcMonitor();
    createIDMType1Monitor();
    createIDMType2Monitor();
    createCalCntrlB0Monitor();
    createCalCntrlB1Monitor();

    smap = samplerMap;

    enableMonitors(smap);
    setMonitorRates(smap);
}

void ThreadedSamplerFactory::createCommonMonitor()
{
   CommonMonitor* monitor = new CommonMonitor(monitorControlModule);
   samplerMap[ID_COMMON_MNTR] = new ThreadedSampler(monitor, McTime::tick_10sec); 
}

void ThreadedSamplerFactory::createCryoLEDMonitor()
{
   CryoLEDMonitor* monitor = new CryoLEDMonitor(monitorControlModule);
   samplerMap[ID_CRYOLED_MNTR] = new ThreadedSampler(monitor, McTime::tick_5min); 
}

void ThreadedSamplerFactory::createCryoLNAMonitor()
{
   CryoLNAMonitor* monitor = new CryoLNAMonitor(monitorControlModule);
   samplerMap[ID_CRYOLNABEAM_MNTR] = new ThreadedSampler(monitor, McTime::tick_1min); 
}

void ThreadedSamplerFactory::createLNADrainMonitor()
{
   LNADrainMonitor* monitor = new LNADrainMonitor(monitorControlModule);
   samplerMap[ID_LNADRAIN_MNTR] = new ThreadedSampler(monitor, McTime::tick_1sec); 
}

void ThreadedSamplerFactory::createMCBCalMonitor()
{
   MCBCalMonitor* monitor = new MCBCalMonitor(monitorControlModule);
   samplerMap[ID_MCBCAL_MNTR] = new ThreadedSampler(monitor, McTime::tick_10sec); 
}

void ThreadedSamplerFactory::createMCBLclExtMonitor()
{
   MCBLclExtMonitor* monitor = new MCBLclExtMonitor(monitorControlModule);
   samplerMap[ID_MCBLCLEXT_MNTR] = new ThreadedSampler(monitor, McTime::tick_10sec); 
}

void ThreadedSamplerFactory::createNoiseCalMonitor()
{
   NoiseCalMonitor* monitor = new NoiseCalMonitor(monitorControlModule);
   samplerMap[ID_NOISECAL_MNTR] = new ThreadedSampler(monitor, McTime::tick_1min); 
}

void ThreadedSamplerFactory::createNoiseSrcMonitor()
{
   NoiseSrcMonitor* monitor = new NoiseSrcMonitor(monitorControlModule);
   samplerMap[ID_NOISESRC_MNTR] = new ThreadedSampler(monitor, McTime::tick_1min); 
}

void ThreadedSamplerFactory::createIDMType1Monitor()
{
    vector<unsigned short> beamList(3);
    beamList[0] = 4; //BEAM 5
    beamList[1] = 5; //BEAM 6
    beamList[2] = 6; //BEAM 7
    IDMType1Monitor* monitor = new IDMType1Monitor(monitorControlModule,
	                                          beamList);
    samplerMap[ID_IDMTYPE1_MNTR] = new ThreadedSampler(monitor, McTime::tick_1min); 
}

void ThreadedSamplerFactory::createIDMType2Monitor()
{
    vector<unsigned short> beamList(4);
    beamList[0] = 0; //BEAM 1
    beamList[1] = 1; //BEAM 2
    beamList[2] = 2; //BEAM 3
    beamList[3] = 3; //BEAM 4

    IDMType2Monitor* monitor = new IDMType2Monitor(monitorControlModule,
	                                          beamList);
    samplerMap[ID_IDMTYPE2_MNTR] = new ThreadedSampler(monitor, McTime::tick_1min);
}

void ThreadedSamplerFactory::createCalCntrlB0Monitor()
{
   CalCntrlB0Monitor* monitor = new CalCntrlB0Monitor(monitorControlModule);
   samplerMap[ID_CALCNTRLB0_MNTR] = new ThreadedSampler(monitor, McTime::tick_1min); 
}

void ThreadedSamplerFactory::createCalCntrlB1Monitor()
{
   CalCntrlB1Monitor* monitor = new CalCntrlB1Monitor(monitorControlModule);
   samplerMap[ID_CALCNTRLB1_MNTR] = new ThreadedSampler(monitor, McTime::tick_1min); 
}

void ThreadedSamplerFactory::enableMonitors(map<unsigned short, ThreadedSampler*>& smap)
{
    ConfigFile* configFile = ConfigFileFactory::getConfigFile(MANAGERNAME);

    configFile->SetCurrentSection("Monitor_Enable",false);
    String value;

    configFile->Get("ID_COMMON_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_COMMON_MNTR]->Enable();
    }

    configFile->Get("ID_MCBLCLEXT_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_MCBLCLEXT_MNTR]->Enable();
    }

    configFile->Get("ID_LNADRAIN_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_LNADRAIN_MNTR]->Enable();
    }

    configFile->Get("ID_CRYOLNABEAM_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_CRYOLNABEAM_MNTR]->Enable();
    }

    configFile->Get("ID_CRYOLED_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_CRYOLED_MNTR]->Enable();
    }

    configFile->Get("ID_NOISECAL_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_NOISECAL_MNTR]->Enable();
    }

    configFile->Get("ID_MCBCAL_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_MCBCAL_MNTR]->Enable();
    }

    configFile->Get("ID_NOISESRCBEAM_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_NOISESRC_MNTR]->Enable();
    }
    
    configFile->Get("ID_IDMTYPE1_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_IDMTYPE1_MNTR]->Enable();
    }

    configFile->Get("ID_IDMTYPE2_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_IDMTYPE2_MNTR]->Enable();
    }

    configFile->Get("ID_CALCNTRLB0_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_CALCNTRLB0_MNTR]->Enable();
    }

    configFile->Get("ID_CALCNTRLB1_MNTR", value);
    if( value.compare("TRUE") == 0 )
    {
	smap[ID_CALCNTRLB1_MNTR]->Enable();
    }
}

void ThreadedSamplerFactory::setMonitorRates(map<unsigned short, ThreadedSampler*>& smap) 
{
    ConfigFile* configFile = ConfigFileFactory::getConfigFile(MANAGERNAME);

    configFile->SetCurrentSection("Monitor_Rates", false);
    String value;

    configFile->Get("COMMON_MNTR_RATE", value);
    smap[ID_COMMON_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("MCBLCLEXT_MNTR_RATE", value);
    smap[ID_MCBLCLEXT_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("LNADRAIN_MNTR_RATE", value);
    smap[ID_LNADRAIN_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("CRYOLNABEAM_MNTR_RATE", value);
    smap[ID_CRYOLNABEAM_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("CRYOLED_MNTR_RATE", value);
    smap[ID_CRYOLED_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("NOISECAL_MNTR_RATE", value);
    smap[ID_NOISECAL_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("MCBCAL_MNTR_RATE", value);
    smap[ID_MCBCAL_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("NOISESRCBEAM_MNTR_RATE", value);
    smap[ID_NOISESRC_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("IDMTYPE1_MNTR_RATE", value);
    smap[ID_IDMTYPE1_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("IDMTYPE2_MNTR_RATE", value);
    smap[ID_IDMTYPE2_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("CALCNTRLB0_MNTR_RATE", value);
    smap[ID_CALCNTRLB0_MNTR]->Interval(convertToMonitorRate(value));

    configFile->Get("CALCNTRLB1_MNTR_RATE", value);
    smap[ID_CALCNTRLB1_MNTR]->Interval(convertToMonitorRate(value));
}

McTime::TimeIdent ThreadedSamplerFactory::convertToMonitorRate(String rate)
{
    McTime::TimeIdent timeId;

    if( rate.compare("20ms") == 0 )
    {
	timeId = McTime::tick_20ms;
    }
    else if( rate.compare("40ms") == 0)
    {
	timeId = McTime::tick_40ms;
    }
    else if( rate.compare("60ms") == 0)
    {
	timeId = McTime::tick_60ms;
    }    
    else if( rate.compare("80ms") == 0)
    {
	timeId = McTime::tick_80ms;
    }    
    else if( rate.compare("100ms") == 0)
    {
	timeId = McTime::tick_100ms;
    }    
    else if( rate.compare("200ms") == 0)
    {
	timeId = McTime::tick_200ms;
    }    
    else if( rate.compare("300ms") == 0)
    {
	timeId = McTime::tick_300ms;
    }    
    else if( rate.compare("400ms") == 0)
    {
	timeId = McTime::tick_400ms;
    }    
    else if( rate.compare("500ms") == 0)
    {
	timeId = McTime::tick_500ms;
    }    
    else if( rate.compare("1sec") == 0)
    {
	timeId = McTime::tick_1sec;
    }    
    else if( rate.compare("1_5sec") == 0)
    {
	timeId = McTime::tick_1_5sec;
    }   
    else if( rate.compare("2sec") == 0)
    {
	timeId = McTime::tick_2sec;
    }
    else if( rate.compare("5sec") == 0)
    {
	timeId = McTime::tick_5sec;
    }
    else if( rate.compare("10sec") == 0)
    {
	timeId = McTime::tick_10sec;
    }
    else if( rate.compare("30sec") == 0)
    {
	timeId = McTime::tick_30sec;
    }    
    else if( rate.compare("1min") == 0)
    {
	timeId = McTime::tick_1min;
    }   
    else if( rate.compare("2min") == 0)
    {
	timeId = McTime::tick_2min;
    }    
    else if( rate.compare("5min") == 0)
    {
	timeId = McTime::tick_5min;
    }   
    else if( rate.compare("10min") == 0)
    {
	timeId = McTime::tick_10min;
    }   
    else if( rate.compare("30min") == 0)
    {
	timeId = McTime::tick_30min;
    }   
    else if( rate.compare("1hr") == 0)
    {
	timeId = McTime::tick_1hr;
    }    
    else
    {
       throw invalid_argument("Monitor::ConvertToMonitorRate");	
    }

    return timeId;
}
