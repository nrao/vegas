#ifndef RcvrArray18_26_THREADED_SAMPLER_FACTORY_H
#define RcvrArray18_26_THREADED_SAMPLER_FACTORY_H

//Application:
#include "threadedsampler.h"

//Ygor:
#include "ConfigFile.h"

//Standard Library:
#include <map>

class ThreadedSamplerFactory
{
public:
    virtual ~ThreadedSamplerFactory() {}
    ThreadedSamplerFactory(IMonCtrlMod*);
    virtual void Create(map<unsigned short, ThreadedSampler*>&);

private:
    IMonCtrlMod* monitorControlModule;

private:
    map<unsigned short, ThreadedSampler*> samplerMap;
    void createCommonMonitor();
    void createCryoLEDMonitor();
    void createCryoLNAMonitor();
    void createLNADrainMonitor();
    void createMCBCalMonitor();
    void createMCBLclExtMonitor();
    void createNoiseCalMonitor();
    void createNoiseSrcMonitor();
    void createIDMType1Monitor();
    void createIDMType2Monitor();
    void createCalCntrlB0Monitor();
    void createCalCntrlB1Monitor();

private:
    void enableMonitors(map<unsigned short, ThreadedSampler*>&);
    void setMonitorRates(map<unsigned short, ThreadedSampler*>&); 
    McTime::TimeIdent convertToMonitorRate(String);
};
#endif
