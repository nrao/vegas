//Application:
#include "monitor.h"

//Standard Library:
#include <stdexcept>

namespace gbt_devices_receivers_RcvrArray18_26
{

Monitor::Monitor(KFPASamplerFactory& samplerFactory,
	         ThreadedSamplerFactory& threadedSamplerFactory)
{ 
    dbg.reset( Dbgout::Instance() );
    samplerFactory.Create(samplerMap);
    threadedSamplerFactory.Create(threadedSamplerMap);
}

Monitor::~Monitor()
{
    dbg.release();
    samplerMap.clear();
    threadedSamplerMap.clear();
}

void Monitor::Initialize()
{
    initKFPASamplers();
    initThreadedSamplers();
}

void Monitor::initKFPASamplers()
{
    map<unsigned short, KFPASampler*>::iterator it;

    for(it  = samplerMap.begin(); 
	it != samplerMap.end() ;
	it++)
    {
	it->second->Initialize();
    }
}

void Monitor::initThreadedSamplers()
{
    map<unsigned short, ThreadedSampler*>::iterator it;

    for(it  = threadedSamplerMap.begin(); 
	it != threadedSamplerMap.end() ;
	it++)
    {
	it->second->Initialize();
    }
}

void Monitor::Sample(unsigned short id)
{
    KFPASampler* sampler = findKFPASampler(id);
    if( sampler != 0 )
    {
	sampler->Sample();
    }
    else
    {
	throw runtime_error("Monitor::Sample unknown id");
    }
}

KFPASampler* Monitor::findKFPASampler(unsigned short id)
{
    KFPASampler* sampler = 0;
    map<unsigned short, KFPASampler*>::iterator it;

    it = samplerMap.find(id);

    if( it != samplerMap.end())
    {
	sampler = it->second;
    }

    return sampler;
}

void Monitor::Start()
{
    dbg->Write( Dbgout::COUT, "Monitor::Start" );

    map<unsigned short, ThreadedSampler*>::iterator it;

    for(it = threadedSamplerMap.begin(); 
	it != threadedSamplerMap.end() ;
	it++)
    {
	it->second->Start();
    }
}

void Monitor::Stop()
{
    dbg->Write( Dbgout::COUT, "Monitor::Stop" );

    map<unsigned short, ThreadedSampler*>::iterator it;

    for(it = threadedSamplerMap.begin(); 
	it != threadedSamplerMap.end() ;
	it++)
    {
	it->second->Stop();
    }
}

void Monitor::Enable()
{
    dbg->Write( Dbgout::COUT, "Monitor::Enable" );

    map<unsigned short, ThreadedSampler*>::iterator it;

    for(it = threadedSamplerMap.begin(); 
	it != threadedSamplerMap.end() ;
	it++)
    {
	it->second->Enable();
    }
}

void Monitor::Disable()
{
    dbg->Write( Dbgout::COUT, "Monitor::Disable" );

    map<unsigned short, ThreadedSampler*>::iterator it;

    for(it = threadedSamplerMap.begin(); 
	it != threadedSamplerMap.end() ;
	it++)
    {
	it->second->Disable();
    }
}

void Monitor::ChangeInterval(unsigned short id, 
	                     McTime::TimeIdent timeId)
{
    ThreadedSampler* sampler = findThreadedSampler(id);
    if( sampler != 0 )
    {
        sampler->Interval(timeId);
    }
    else
    {
	throw runtime_error("Monitor::ChangeInterval unknown id");
    }
}

ThreadedSampler* Monitor::findThreadedSampler(unsigned short id)
{
    ThreadedSampler* sampler = 0;
    map<unsigned short, ThreadedSampler*>::iterator it;

    it = threadedSamplerMap.find(id);

    if( it != threadedSamplerMap.end())
    {
	sampler = it->second;
    }

    return sampler;
}

void Monitor::Enable(unsigned short id)
{
    ISampler* sampler = findSampler(id);

    if( sampler != 0 )
    {
	sampler->Enable();
    }
    else
    {
	throw runtime_error("Monitor::Enable unknown id");
    }
}

void Monitor::Disable(unsigned short id)
{
    ISampler* sampler = findSampler(id);

    if( sampler != 0 )
    {
	sampler->Disable();
    }
    else
    {
	throw runtime_error("Monitor::Disable unknown id");
    }
}

ISampler* Monitor::findSampler(unsigned short id)
{
    ISampler* sampler = findKFPASampler(id);

    if( sampler == 0 )
    {
	sampler = findThreadedSampler(id);
    }

    return sampler;
}

} //end of namespace gbt.devices.receivers.RcvrArray18_26
