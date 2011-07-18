#ifndef MONITOR_H
#define MONITOR_H

//Application:
#include "samplerfactory.h"
#include "threadedsamplerfactory.h"
//#include "dbgout.h"

//Ygor:
#include "McTime.h"

//Standard:
#include <map>
#include <string>

class IMonitor
{
public:
    virtual ~IMonitor() {}
    virtual void Initialize() = 0;
    virtual void Start() = 0;
    virtual void Stop() = 0;
    virtual void Enable() = 0;
    virtual void Disable() = 0;
    virtual void Sample(unsigned short) = 0;
    virtual void ChangeInterval(unsigned short, McTime::TimeIdent) = 0;
    virtual void Enable(unsigned short) = 0;
    virtual void Disable(unsigned short) = 0;
    
protected:
    IMonitor() {}
};

class Monitor : public IMonitor
{
public:
    Monitor(KFPASamplerFactory&, ThreadedSamplerFactory&);
    virtual ~Monitor();

    void Initialize();
    void Start();
    void Stop();
    void Enable();
    void Disable();
    void Sample(unsigned short);
    void ChangeInterval(unsigned short, McTime::TimeIdent);
    void Enable(unsigned short);
    void Disable(unsigned short);

private:
    map<unsigned short, KFPASampler*> samplerMap;
    map<unsigned short, ThreadedSampler*> threadedSamplerMap;

private:
    void initKFPASamplers();
    void initThreadedSamplers();

private:
    ISampler* findSampler(unsigned short);
    KFPASampler* findKFPASampler(unsigned short);
    ThreadedSampler* findThreadedSampler(unsigned short);

private:
    auto_ptr<Dbgout> dbg;
};

struct MONITOR_PERIOD_T
{
    unsigned short monitorId;
    McTime::TimeIdent monitorRate; 
};

#endif//MONITOR_H
