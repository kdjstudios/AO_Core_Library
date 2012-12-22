/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOQUATERNION_H
#define AOQUATERNION_H

#include <ostream>
#include <sstream>
#include <cmath>
#include "aoConstant.h"
//#include "aoMath.h"
//#include "dimension2d.h"

namespace ao
{
namespace core
{

class Quaternion
{
public:
    //Members
    double W,X,Y,Z;
    //Constructors
    Quaternion();
    explicit Quaternion(double const&w,double const&x,double const&y,double const&z);
    //Math
    //Vector3 by Vector3 Math
    Quaternion		operator+(const Quaternion& Quat) const;
    Quaternion		operator-(const Quaternion& Quat) const;
    Quaternion		operator*(const Quaternion& Quat) const;
    Quaternion		operator/(const Quaternion& Quat) const;
    Quaternion&		operator+=(const Quaternion& Quat);
    Quaternion&		operator-=(const Quaternion& Quat);
    Quaternion&		operator*=(const Quaternion& Quat);
    Quaternion&		operator/=(const Quaternion& Quat);
    //Vector3 by double Math
    Quaternion		operator-() const;
    Quaternion		operator+(double const&num) const;
    Quaternion		operator-(double const&num) const;
    Quaternion		operator*(double const&num) const;
    Quaternion		operator/(double const&num) const;
    Quaternion&		operator+=(double const&num);
    Quaternion&		operator-=(double const&num);
    Quaternion&		operator*=(double const&num);
    Quaternion&		operator/=(double const&num);
    //Boolean Equals Operators
    bool		operator==(const Quaternion& Quat) const;
    bool		operator!=(const Quaternion& Quat) const;
    //Static Predefines
    static const Quaternion Zero;
    static const Quaternion One;
    //Print out
    friend std::ostream& operator<< (std::ostream& ofs, const Quaternion& Quat);

};
//double mag(Quaternion const &rhs);
//double dot(Quaternion const &lhs, Quaternion const &rhs);
//double lsq(Quaternion const&rhs);
//Quaternion norm(Quaternion const &lhs);
//Quaternion rotate(double const&lhs,Quaternion const &rhs);

inline Quaternion::Quaternion():W(0),X(0),Y(0),Z(0) {}
inline Quaternion::Quaternion(double const&w,double const&x,double const&y,double const&z):W(w),X(x),Y(y),Z(z) {}
//
const Quaternion Quaternion::Zero=Quaternion(0,0,0,0);
const Quaternion Quaternion::One=Quaternion(1,1,1,1);
//Vector3 by Vector3 Math
inline Quaternion Quaternion::operator+(const Quaternion& Quat) const
{
    return Quaternion(X+Quat.X,Y+Quat.Y,Z+Quat.Z,W+Quat.W);
}
inline Quaternion Quaternion::operator-(const Quaternion& Quat) const
{
    return Quaternion(X-Quat.X,Y-Quat.Y,Z-Quat.Z,W-Quat.W);
}
inline Quaternion Quaternion::operator*(const Quaternion& Quat) const
{
    return Quaternion(
               //---
               (W*Quat.W)-(X*Quat.X)-(Y*Quat.Y)-(Z*Quat.Z),
               //++-
               (W*Quat.W)+(X*Quat.X)+(Y*Quat.Y)-(Z*Quat.Z),
               //-++
               (W*Quat.W)-(X*Quat.X)+(Y*Quat.Y)+(Z*Quat.Z),
               //+-+
               (W*Quat.W)+(X*Quat.X)-(Y*Quat.Y)+(Z*Quat.Z));
}
inline Quaternion Quaternion::operator/(const Quaternion& Quat) const
{
    return Quaternion();
}
//Quanterns (still in testing of functionality)
inline Quaternion Quaternion::operator/(double const&num) const
{
    return Quaternion(W/num,X/num,Y/num,Z/num);
}
inline Quaternion Quaternion::operator*(double const&num) const
{
    Quaternion result;
    result.X=X * num;
    result.Y=Y * num;
    result.Z=Z * num;
    result.W=W * num;
    return result;
}
//
inline void toNormalized(Quaternion & rhs)
{
    double n = sqrt(rhs.X*rhs.X + rhs.Y*rhs.Y + rhs.Z*rhs.Z + rhs.W*rhs.W);
    rhs.X /= n;
    rhs.Y /= n;
    rhs.Z /= n;
    rhs.W /= n;
}
//
inline double dot(Quaternion const&lhs,Quaternion const&rhs)
{
    return lhs.X*rhs.X+lhs.Y*rhs.Y+lhs.Z*rhs.Z+rhs.W*rhs.W;
}
inline double lengthSquared(Quaternion const&rhs)
{
    return dot(rhs,rhs);
}
inline double magnitude(Quaternion const &rhs)
{
    return sqrt(dot(rhs, rhs));
}
inline Quaternion normalize(Quaternion const &lhs)
{
    return lhs * (1.0f /(magnitude(lhs)));
}
inline Quaternion rotate(double const &lhs,Quaternion const &rhs)
{
    //rotation
    Quaternion temp(
        cos(lhs/2),
        rhs.X * sin( lhs/2 ),
        rhs.Y * sin( lhs/2 ),
        rhs.Z * sin( lhs/2 ));
    //use the overide multiplication
    return temp * rhs;
}
/** q1 can be non-normalised quaternion */
inline void toEuler(Quaternion q1)
{
    double sqw = q1.W*q1.W;
    double sqx = q1.X*q1.X;
    double sqy = q1.Y*q1.Y;
    double sqz = q1.Z*q1.Z;
    double unit = sqx + sqy + sqz + sqw; // if normalised is one, otherwise is correction factor
    double test = q1.X*q1.Y + q1.Z*q1.W;
    double heading, attitude, bank;
    if (test > 0.499*unit)   // singularity at north pole
    {
        heading = 2 * atan2(q1.X,q1.W);
        attitude = PI/2;
        bank = 0;
        return;
    }
    if (test < -0.499*unit)   // singularity at south pole
    {
        heading = -2 * atan2(q1.X,q1.W);
        attitude = -PI/2;
        bank = 0;
        return;
    }
    heading = atan2((double) (2*q1.Y*q1.W-2*q1.X*q1.Z) ,(double)( sqx - sqy - sqz + sqw));
    attitude = asin(2*test/unit);
    bank = atan2((double)(2*q1.X*q1.W-2*q1.Y*q1.Z ),(double) (-sqx + sqy - sqz + sqw));
}
//
inline void toAxisAngle(Quaternion &q1)
{
    if (q1.W > 1)
    {
        toNormalized(q1); // if w>1 acos and sqrt will produce errors, this cant happen if quaternion is normalised
    }

    double angle = 2 * acos(q1.W);
    double s = sqrt(1-q1.W*q1.W); // assuming quaternion normalised then w is less than 1, so term always positive.
    if (s < 0.001)   // test to avoid divide by zero, s is always positive due to sqrt
    {
        // if s close to zero then direction of axis not important
        q1.X = q1.X; // if it is important that axis is normalised then replace with x=1; y=z=0;
        q1.Y = q1.Y;
        q1.Z = q1.Z;
    }
    else
    {
        q1.X = q1.X / s; // normalise axis
        q1.Y = q1.Y / s;
        q1.Z = q1.Z / s;
    }
}

//Output display of values
inline std::ostream& operator<< (std::ostream& os, const Quaternion& quat)
{
    std::stringstream stream;
    stream << "X: " << quat.X << ", Y: " << quat.Y << ", Z: " << quat.Z << ", W: " << quat.W ;
    os.write(const_cast<char*>(stream.str().c_str()), static_cast<std::streamsize>(stream.str().size() * sizeof(char)) );
    return os;
}
/*
inline Vector3 rotVec(Quaternion const &lhs,Vector3 const&rhs){
	Quaternion qtemp;
	qtemp.W = (-(lhs.X * rhs.X) - (lhs.Y * rhs.Y) - (lhs.Z * rhs.Z));
	qtemp.X = ( (lhs.W * rhs.X) + (lhs.Y * rhs.Z) - (lhs.Z * rhs.Y));
	qtemp.Y = ( (lhs.W * rhs.Y) - (lhs.X * rhs.Z) + (lhs.Z * rhs.X));
	qtemp.Z = ( (lhs.W * rhs.Z) + (lhs.X * rhs.Y) - (lhs.Y * rhs.X));

	return Vector3(((qtemp.Z * rhs.Y) - (qtemp.W * rhs.X) - (qtemp.Y * rhs.Z)),((qtemp.X * rhs.Z) - (qtemp.W * rhs.Y) - (qtemp.Z * rhs.X)), ((qtemp.Y * rhs.X) - (qtemp.W * rhs.Z) - (qtemp.X * rhs.Y)));
}
*/
}
}
#endif
