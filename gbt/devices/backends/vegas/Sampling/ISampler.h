#ifndef TSAMPLER_H
#define TSAMPLER_H

// YGOR
#include <Sampler.h>

class ISampler
{
public:
    virtual ~ISampler();
    void Initialize();
    void Sample();
    void Enable();
    void Disable();

protected:
    ISampler();

    virtual void doInitialize() = 0;
    virtual void doSample() = 0;
    virtual void doEnable() = 0;
    virtual void doDisable() = 0;

protected:
    bool enabled;
    Sampler *sampler;
};

#endif//TSAMPLER_H
