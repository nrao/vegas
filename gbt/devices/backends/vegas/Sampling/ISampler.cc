#include "TSample.h"

ISampler::ISampler()
    :
    enable(true)
{
}

ISampler::~ISampler()
{
}

void
ISampler::Initialize()
{
    doInitialize();
}

void
ISampler::Sample()
{
    if(enabled)
    {
        doSample();
    }
}

void
ISampler::Enable()
{
    enabled = true;
}

void
ISampler::Disable()
{
    enabled = false;
}
