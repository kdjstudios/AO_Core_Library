/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOMOVEENTITY_H
#define AOMOVEENTITY_H
#include "aoEntity.h"

namespace ao
{
namespace graphics
{

//TODO: maybe this should be bodyentity?
class MovingEntity:public BaseEntity
{
protected:
    vector3 m_Velocity;
    vector3 m_Heading;
    vector3 m_Side;
    //Physics used with RigidBodys and GeneralApplyForces
    double m_Mass;
    double m_MaxSpeed;
    double m_MaxForce;
    double m_MaxTurnRate;
public:
    MovingEntity(vector3 position,vector3 heading,vector3 scale, vector3 velocity,double radius,
                 double max_speed, double mass, double turn_rate,
                 double max_force):BaseEntity((int)0, position, radius, scale),
        m_Heading(heading),
        m_Velocity(velocity),
        m_Mass(mass),
        m_Side(perpendicular(m_Heading)),
        m_MaxSpeed(max_speed),
        m_MaxTurnRate(turn_rate),
        m_MaxForce(max_force)
    {}
    MovingEntity() {}
    virtual ~MovingEntity() {}

    //Functionality
    vector3  Velocity()const
    {
        return m_Velocity;
    }
    void      SetVelocity(const vector3& NewVel)
    {
        m_Velocity = NewVel;
    }

    double     Mass()const
    {
        return m_Mass;
    }

    vector3 Side()const
    {
        return m_Side;
    }

    double     MaxSpeed()const
    {
        return m_MaxSpeed;
    }
    void      SetMaxSpeed(double new_speed)
    {
        m_MaxSpeed = new_speed;
    }

    double     MaxForce()const
    {
        return m_MaxForce;
    }
    void      SetMaxForce(double maxforce)
    {
        m_MaxForce = maxforce;
    }

    bool      IsSpeedMaxedOut()const
    {
        return m_MaxSpeed*m_MaxSpeed >= lengthSquared(m_Velocity);
    }
    double     Speed()const
    {
        return magnitude(m_Velocity);
    }
    double     SpeedSq()const
    {
        return lengthSquared(m_Velocity);
    }

    vector3  Heading()const
    {
        return m_Heading;
    }

//--------------------------- RotateHeadingToFacePosition ---------------------
//
//  given a target position, this method rotates the entity's heading and
//  side vectors by an amount not greater than m_dMaxTurnRate until it
//  directly faces the target.
//
//  returns true when the heading is facing in the desired direction
//-----------------------------------------------------------------------------
    bool RotateHeadingToFacePosition(vector3 target)
    {
        vector3 toTarget = normalize(target - m_Position);

        double mdot = dot(m_Heading,toTarget);

        //some compilers lose acurracy so the value is clamped to ensure it
        //remains valid for the acos
        //Clamp(mdot, -1, 1);

        //first determine the angle between the heading vector and the target
        double angle = acos(mdot);

        //return true if the player is facing the target
        if (angle < 0.00001) return true;

        //clamp the amount to turn to the max turn rate
        if (angle > m_MaxTurnRate) angle = m_MaxTurnRate;

        //The next few lines use a rotation matrix to rotate the player's heading
        //vector accordingly
        matrix2x2 RotationMatrix;

        //notice how the direction of rotation has to be determined when creating
        //the rotation matrix
//	RotationMatrix.Rotate(angle * m_vHeading.Sign(toTarget));
//  RotationMatrix.Transformvector2s(m_vHeading);
//  RotationMatrix.Transformvector2s(m_vVelocity);

        //finally recreate m_vSide
        m_Side = perpendicular(m_Heading);

        return false;
    }


//------------------------- SetHeading ----------------------------------------
//
//  first checks that the given heading is not a vector of zero length. If the
//  new heading is valid this fumction sets the entity's heading and side
//  vectors accordingly
//-----------------------------------------------------------------------------
    void SetHeading(vector3 new_heading)
    {
        assert( (lengthSquared(new_heading) - 1.0) < 0.00001);

        m_Heading = new_heading;

        //the side vector must always be perpendicular to the heading
        m_Side = perpendicular(m_Heading);
    }

    double     MaxTurnRate()const
    {
        return m_MaxTurnRate;
    }
    void      SetMaxTurnRate(double val)
    {
        m_MaxTurnRate = val;
    }

};
}
}
#endif
