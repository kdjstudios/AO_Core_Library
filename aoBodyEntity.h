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
    double t;
    double c;
    double v;
    double m;
    double s;
public:
    BodyEntity();
    virtual ~BodyEntity() {}

    //Functionality
    double  Velocity()const
    {
        return v;
    }
    void      SetVelocity(const double& new_Vel)
    {
        v = new_Vel;
    }

    double     Mass()const
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
    void      StepSimulation(double dt);
    void      StepSimulationAdaptive(double dt);
    void      StepSimulationImproved(double dt);
    void      StepSimulationRunge(double dt);
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
inline void BodyEntity::StepSimulation(double dt)
{
    //placeholders for calculations
    double F;
    double A;
    double V;
    double S;

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
inline void BodyEntity::StepSimulationAdaptive(double dt)
{
    double F;
    double A;
    double V;
    double S;
    double V1;
    double V2;
    double DT;
    double ET;
    //
    double ETO;
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
inline void BodyEntity::StepSimulationImproved(double dt)
{
    //placeholders for calculations
    double F;
    double A;
    double V;
    double S;
    double K1;
    double K2;

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
inline void BodyEntity::StepSimulationRunge(double dt)
{
    //placeholders for calculations
    double F;
    double A;
    double V;
    double S;
    double K1;
    double K2;
    double K3;
    double K4;

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
