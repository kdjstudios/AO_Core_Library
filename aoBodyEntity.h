/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOBODYENTITY_H
#define AOBODYENTITY_H
#include "aoEntity.h"

namespace ao
{
namespace graphics
{

class BodyEntity:public BaseEntity
{
protected:
    float t;
    float c;
    float v;
    float m;
    float s;
public:
    BodyEntity();
    virtual ~BodyEntity() {}

    //Functionality
    float  Velocity()const
    {
        return v;
    }
    void      SetVelocity(const float& new_Vel)
    {
        v = new_Vel;
    }

    float     Mass()const
    {
        return m;
    }

    //Vector3 Side()const{return m_Side;}

    double     Thrust()const
    {
        return t;
    }
    void      SetThrust(double new_thrust)
    {
        t = new_thrust;
    }

    double     DragCoefficient()const
    {
        return c;
    }
    void      SetDragCoefficient(double new_dragCoeffiecient)
    {
        c = new_dragCoeffiecient;
    }
    void      StepSimulation(float dt);
    void      StepSimulationAdaptive(float dt);
    void      StepSimulationImproved(float dt);
    void      StepSimulationRunge(float dt);
};
inline BodyEntity::BodyEntity()
{
    s=0;
    t=0;
    v=0;
    c=0;
    m=0;
}
//Physic Stuffs
//Eulers basic method
inline void BodyEntity::StepSimulation(float dt)
{
    //placeholders for calculations
    float F;
    float A;
    float V;
    float S;

    //calculate the total force
    F=(t-(c*v));

    //calculate acceleration
    A = F/m;

    //newVelocity
    V= v+A*dt;

    //update
    v=V;
    s=S;
}
inline void BodyEntity::StepSimulationAdaptive(float dt)
{
    float F;
    float A;
    float V;
    float S;
    float V1;
    float V2;
    float DT;
    float ET;
    //
    float ETO;
    //take one step to estimate
    F=(t-(c*v));
    A = F/m;
    V1= v+A*dt;

    //take two steps to estimate a further approxomation
    F=(t-(c*v));
    A = F/m;
    V2= v+A*(dt/2);
    F=(t-(c*V2));
    A = F/m;
    V2= V2+A*(dt/2);
    //estimate the error difference
    ET=abs(V1-V2);
    //estiamte a new step size
    DT=dt*sqrt(ETO/ET);
    if(DT<dt)
    {
        //Smaller Step
        F=(t-(c*v));
        A = F/m;
        V=v+A*DT;
        S=s+V*DT;
    }
    else
    {
        //Original Step
        V=V1;
        S=s+V*dt;
    }
    v=V;
    s=S;
}
inline void BodyEntity::StepSimulationImproved(float dt)
{
    //placeholders for calculations
    float F;
    float A;
    float V;
    float S;
    float K1;
    float K2;

    F=(t-(c*v));
    A = F/m;
    K1=dt*A;

    F=(t-(c*(v+K1)));
    A = F/m;
    K2=dt*A;

    V=v+(K1+K2)/2;
    S=s+V*dt;

    //update
    v=V;
    s=S;
}
inline void BodyEntity::StepSimulationRunge(float dt)
{
    //placeholders for calculations
    float F;
    float A;
    float V;
    float S;
    float K1;
    float K2;
    float K3;
    float K4;

    F=(t-(c*v));
    A = F/m;
    K1=dt*A;

    F=(t-(c*(v+K1/2)));
    A = F/m;
    K2=dt*A;

    F=(t-(c*(v+K2/2)));
    A = F/m;
    K3=dt*A;

    F=(t-(c*(v+K3)));
    A = F/m;
    K4=dt*A;
    //
    V=v+(K1+2*K2 + 2*K3 + K4)/6;
    S=s+V*dt;

    //update
    v=V;
    s=S;
}
}
}
#endif
