//Application:
#include "threadedsampler.h"

//Standard Library:
#include <stdexcept>

template <typename SamplerClass>
ThreadedSampler<SamplerClass>::ThreadedSampler(SamplerClass *s,
                                               McTime::TimeIdent interval)
    :
    sampleInterval(interval),
    stopCondition(false),
    monitor_mct(0),
    task(this, &ThreadedSampler::taskProc),
    kfpaSampler(s)
{
    monitor_mct = McTime::factory(sampleInterval);
    // ygormsg = YgorMessage::Instance();
    // dbg = Dbgout::Instance();
}

template <typename SamplerClass>
void
ThreadedSampler<SamplerClass>::Initialize()
{
    if( task.running() == false )
    {
        sampler->Initialize(); 
    }
}

template <typename SamplerClass>
void
ThreadedSampler<SamplerClass>::Enable()
{
    
    // if(!task.running())
    // {
    //     sampler->Enable();
    // }
    sampler->Enable();
}

template <typename SamplerClass>
void
ThreadedSampler<SamplerClass>::Disable()
{    
    // if(task.running())
    // {
    //     this->Stop();
    // }
    sampler->Disable();
}

template <typename SamplerClass>
void
ThreadedSampler<SamplerClass>::Start()
{
    if(task.running())
    {
	return;
    }

    McTime::change_period(monitor_mct, sampleInterval);
    stopCondition.set_value(false);
    task.start();
}

template <typename SamplerClass>
void
ThreadedSampler<SamplerClass>::Stop()
{
    if(task.running())
    {
	stopCondition.signal(true);
	McTime::change_period(monitor_mct, McTime::tick_20ms);
	task.stop_without_cancel();
    }
}

template <typename SamplerClass>
void
ThreadedSampler<SamplerClass>::Sample()
{
    //!!! What is the intent here? That nobody call this method (pure virtual)
    //!!! is it not needed (delete it)?
    //throw runtime_error("ThreadedSampler::Sample not implemented");
}

template <typename SamplerClass>
void
ThreadedSampler<SamplerClass>::Interval(McTime::TimeIdent interval)
{
    sampleInterval = interval;
    McTime::change_period(monitor_mct, interval); 
}

template <typename SamplerClass>
McTime::TimeIdent
ThreadedSampler<SamplerClass>::Interval()
{
    return sampleInterval;
}

template <typename SamplerClass>
void
ThreadedSampler<SamplerClass>::taskProc()
{
    while(!stopCondition.wait(true, 1000))
    {
	monitor_mct->wait();

	if(stopCondition.value())
	{
            break;
	}

	try
	{
	    sampler->Sample();
	}
	catch(exception& e)
	{
	    // dbg->Write(Dbgout::CERR, 
	    //            "ThreadedSampler::taskProc %s", 
	    //            e.what());

	    // ygormsg->Set(YgorMessage::MONITORERROR, e.what());
	}
    }
}
