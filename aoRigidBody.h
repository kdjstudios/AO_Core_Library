/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AORIGIDBODY_H
#define AORIGIDBODY_H
#include "aoBodyEntity.h"


namespace ao
{
namespace core
{
//
// RigidBody : bodyentity
// (class template)
// ----------
// ----------
//
class RigidBody:public BodyEntity
{
private:
    float fMass;
    float fInertia;
    float fInertiaInverse;
    //should position get updated into baseentity
    vector3 vPosition;
    //
    vector3 vVelocity;
    vector3 vVelocityBody;
    vector3 vAngularVelocity;

    float fSpeed;
    float fOrientation;
    vector3 vForces;
    vector3 vMoment;

    vector3 CD;
    vector3 CT;
    vector3 CPT;
    vector3 CST;

    float fProjectedArea;
    float fTrustForce;
    vector3 PThrust, SThrust;
    float fWidth;
    float fLength;
public:
    void Start();
    RigidBody();
    virtual ~RigidBody() {}
    void CalcLoads();
    void UpdateBody(double time_elapsed);
    void Render();
    double TimeElapsed();
};
inline RigidBody::RigidBody()
{

}
inline void RigidBody::Start() {}
inline void RigidBody::CalcLoads() {}
//inline void RigidBody::Render();
inline void RigidBody::UpdateBody(double time_elapsed)
{
    //StepSimulation(time_elapsed);
}
}
}
#endif
