//
/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOCLOCK_H
#define AOCLOCK_H
#include "vector3.h"

namespace ao
{
namespace core
{
//
// Clock
// (abstract class template)
// ----------
// + getTime(): float
// + create(): static Clock*
// - Clock(Clock const&):
// + ~Clock():virtual
// - operator=(const Clock&): Clock&
// ----------
// = Clock()
// ----------
//
class Clock
{
public:
    //virtual~Clock()=0{}
    virtual float getTime()const=0;
    static Clock*create();
protected:
    Clock() {}
private:
    Clock(Clock const&) {}
    Clock &operator=(Clock const&)
    {
        return*this;
    }
};

//should be in project settings
//#define USE_RDTSC
#ifdef USE_RDTSC
#include <windows.h>
#endif
//other platform specific includes
#ifdef USE_RDTSC
class ClockRDTSC:public Clock
{
public:
    ClockRDTSC():m_start(0),m_period(0)
    {
        __int64 freq=0;
        ::QueryPerformanceFrequency((LARGE_INTEGER*)&freq);
        m_period=1/(float)freq;
        ::QueryPerformanceCounter((LARGE_INTEGER*)&m_start);
    }
    virtual ~ClockRDTSC() {}
    virtual float getTime()const
    {
        __int64 count=0;
        ::QueryPerformanceCounter((LARGE_INTEGER*)&count);
        return m_period*(float)(count-m_start);
    }
private:
    __int64 m_start;
    float m_period;
};
Clock *Clock::create()
{
    return new ClockRDTSC;
}
#endif

#ifndef AOFPSCOUNTER_H
#define AOFPSCOUNTER_H
class FPSCounter
{
private:
    int frameCount;
    long lCTM;
public:
    float mFPS;
    void step(float secondsElapsed)
    {
        frameCount++;
        if(frameCount>=100)
        {
            long CTM= Clock::create()->getTime();
            frameCount=0;
            if(lCTM>0)
            {
                mFPS=(100.0f/((CTM-lCTM)/100.0f));
                // cout??
            }
            lCTM=CTM;
        }
        this->step(secondsElapsed);
    }
};
#endif
class Timer
{
    clock_t start;
    double elapsed;
public:
    Timer():start(clock()),elapsed(0) {}
    void begin()
    {
        start = clock();
        elapsed = 0;
    }
    double end()
    {
        elapsed=(double) clock()-start;
        elapsed /=CLOCKS_PER_SEC;
        return elapsed;
    }

};
}
}
#endif
