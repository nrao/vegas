#ifndef RcvrArray18_26_KFPA_SAMPLER_H
#define RcvrArray18_26_KFPA_SAMPLER_H

//Application:
#include "comms.h"
#include "ygormsg.h"

//Ygor Sampler:
#include "Sampler.h"
#include "GbtMsg.h"
#include "mgrDDL.h"
#include "DeviceAccessContainer.h"

using namespace std;

class ISampler
{
public:
    virtual ~ISampler() {}
    virtual void Initialize() = 0;
    virtual void Sample() = 0;
    virtual void Enable() = 0;
    virtual void Disable() = 0;

protected:
    ISampler();
    bool enabled;
};

class KFPASampler : public ISampler
{
public:
    virtual ~KFPASampler();
    virtual void Initialize() = 0;
    virtual void Sample();
    void Enable();
    void Disable();

protected:
    virtual void doRequest();
    virtual void doCast() = 0;
    virtual void doCheck() = 0;
    virtual void doSample();

protected:
    KFPASampler(IMonCtrlMod*);
    IMonCtrlMod* monitorControlModule;
    Sampler* sampler;
    MonitorData* monitorData;
    IMessageData* responseData;

protected:
    YgorMessage* ygormsg;

private:
    void sampleImpl(); 
};
#endif
