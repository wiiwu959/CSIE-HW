// alarm.cc
//	Routines to use a hardware timer device to provide a
//	software alarm clock.  For now, we just provide time-slicing.
//
//	Not completely implemented.
//
// Copyright (c) 1992-1996 The Regents of the University of California.
// All rights reserved.  See copyright.h for copyright notice and limitation 
// of liability and disclaimer of warranty provisions.

#include "copyright.h"
#include "alarm.h"
#include "main.h"
#include "interrupt.h"

//----------------------------------------------------------------------
// Alarm::Alarm
//      Initialize a software alarm clock.  Start up a timer device
//
//      "doRandom" -- if true, arrange for the hardware interrupts to 
//		occur at random, instead of fixed, intervals.
//----------------------------------------------------------------------

Alarm::Alarm(bool doRandom)
{
    timer = new Timer(doRandom, this);
}

//----------------------------------------------------------------------
// Alarm::CallBack
//	Software interrupt handler for the timer device. The timer device is
//	set up to interrupt the CPU periodically (once every TimerTicks).
//	This routine is called each time there is a timer interrupt,
//	with interrupts disabled.
//
//	Note that instead of calling Yield() directly (which would
//	suspend the interrupt handler, not the interrupted thread
//	which is what we wanted to context switch), we set a flag
//	so that once the interrupt handler is done, it will appear as 
//	if the interrupted thread called Yield at the point it is 
//	was interrupted.
//
//	For now, just provide time-slicing.  Only need to time slice 
//      if we're currently running something (in other words, not idle).
//	Also, to keep from looping forever, we check if there's
//	nothing on the ready list, and there are no other pending
//	interrupts.  In this case, we can safely halt.
//----------------------------------------------------------------------

void 
Alarm::CallBack() 
{
    Interrupt *interrupt = kernel->interrupt;
    MachineStatus status = interrupt->getStatus();

    kernel->currentThread->setPriority(kernel->currentThread->getPriority() - 1);

    // this line is add for systemcall sleep 
    bool woken = sleepList.PutToReady();

    if (status == IdleMode && !woken && sleepList.IsEmpty()) {	// is it time to quit?
        if (!interrupt->AnyFutureInterrupts()) {
	    timer->Disable();	// turn off the timer
	}
    } else {			// there's someone to preempt
        if(kernel->scheduler->getSchedulerType() == RR ||
            kernel->scheduler->getSchedulerType() == Priority) {
		interrupt->YieldOnReturn();
	}
    }
}


////////////////////////////////////////////////////////////////////////
// implement WaitUntil function.
void 
Alarm::WaitUntil(int x)
{
    // save previous setting as oldLevel and disable interrupt.	
    IntStatus oldLevel = kernel->interrupt->SetLevel(IntOff);
    Thread* t = kernel->currentThread;
    sleepList.PutToSleep(t, x);	// put current thread to sleep list.
    kernel->interrupt->SetLevel(oldLevel);	// recover old interrupt state.
}

// check if there is still thread sleeping
bool SleepList::IsEmpty()
{
    return threadlist.size() == 0;
}

// put the thread into sleep list
void SleepList::PutToSleep(Thread*t, int x)
{
    IntStatus oldLevel = kernel->interrupt->SetLevel(IntOff);
    ASSERT(kernel->interrupt->getLevel() == IntOff);		  // check if it cannot be interrupt.
    threadlist.push_back(SleepThread(t, counter + x)); // put into the list
    if(kernel->scheduler->getSchedulerType()!=SRTF){
    	t->Sleep(false);
    }
    kernel->interrupt->SetLevel(oldLevel);
}

// will be call in callback
bool SleepList::PutToReady()
{
    IntStatus oldLevel = kernel->interrupt->SetLevel(IntOff);
    bool woken = false;
    counter ++;

    // check all thread in the list if there are thread already finish sleeping
    for(std::list<SleepThread>::iterator it = threadlist.begin();
        it != threadlist.end(); )
    {
        // 'when' is time the thread should wake up
        // if counter >= when, this thread will be ready to run.
        if(counter >= it->when)
        {
            woken = true;
            kernel->scheduler->ReadyToRun(it->sleeper);
            it = threadlist.erase(it);
        }
        // if the thread is not ready to run, keep checking next thread in the list.
        else
        {
            it++;
        }
    }
    kernel->interrupt->SetLevel(oldLevel);
    return woken;
}
