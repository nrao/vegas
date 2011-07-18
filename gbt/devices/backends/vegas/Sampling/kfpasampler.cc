//Application:
#include "kfpasampler.h"

//Standard Library:
#include <stdexcept>

ISampler::ISampler()
         : enabled(false)
{
}

KFPASampler::KFPASampler(IMonCtrlMod* mcm)
	    : monitorControlModule(mcm),
	      sampler(0),
	      monitorData(0),
	      responseData(0)
{
    ygormsg = YgorMessage::Instance();
}

KFPASampler::~KFPASampler()
{
    if( monitorData != 0 )
    {
	delete monitorData;
        monitorData = 0;
    }

    if( responseData != 0 )
    {
	delete responseData;
        responseData = 0;
    }
}

void KFPASampler::Sample()
{
    this->sampleImpl();
}

void KFPASampler::sampleImpl()
{
    if( enabled == false )
    {
	return;
    }

    doRequest();
    doCast();
    doCheck();
    doSample();
}

void KFPASampler::Enable()
{
    enabled = true;
}

void KFPASampler::Disable()
{
    enabled = false;
}

void KFPASampler::doRequest()
{
    if( monitorData == 0 )
    {
	throw runtime_error("IKFPASampler::doRequest: null pointer");
    }

    monitorControlModule->Execute(monitorData, 
				  responseData); 
}

void KFPASampler::doSample()
{
    if( sampler == 0 )
    {
	throw runtime_error("IKFPASampler::doSample: null pointer");
    }

    sampler->sample();
}
