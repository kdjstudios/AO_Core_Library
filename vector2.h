/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOVECTOR2_H
#define AOVECTOR2_H

#include <ostream>
#include <sstream>
#include <cmath>
//#include "aoMath.h"
//#include "dimension2d.h"

namespace ao
{
namespace core
{

class vector2
{
public:
    //Members
    float X;
    float Y;
    //Constructors
    vector2();
    explicit vector2(float const&newX,float const&newY);
    //vector2d() : X(0), Y(0) {}
    //vector2d(float nx, float ny) : X(nx), Y(ny) {}
    //explicit vector2d(float n) : X(n), Y(n) {}
    //vector2d(const vector2d& other) : X(other.X), Y(other.Y) {}
    //vector2d(const dimension2d& other) : X(other.Width), Y(other.Height) {}
    //Math
    //Vector3 by Vector3 Math
    vector2		operator+(const vector2& vector) const;
    vector2		operator-(const vector2& vector) const;
    vector2		operator*(const vector2& vector) const;
    vector2		operator/(const vector2& vector) const;
    vector2&	operator+=(const vector2& vector);
    vector2&	operator-=(const vector2& vector);
    vector2&	operator*=(const vector2& vector);
    vector2&	operator/=(const vector2& vector);
    //Vector3 by Float Math
    vector2		operator-() const;
    vector2		operator+(float const&num) const;
    vector2		operator-(float const&num) const;
    vector2		operator*(float const&num) const;
    vector2		operator/(float const&num) const;
    vector2&	operator+=(float const&num);
    vector2&	operator-=(float const&num);
    vector2&	operator*=(float const&num);
    vector2&	operator/=(float const&num);
    //Boolean Equals Operators
    bool		operator==(const vector2& vector) const;
    bool		operator!=(const vector2& vector) const;
    //Static Predefines
    static const vector2 Zero;
    static const vector2 One;
    //Print out
    friend std::ostream& operator<< (std::ostream& ofs, const vector2& vector);
};

//Constructors
inline vector2::vector2() {}
inline vector2::vector2(float const&x, float const&y): X( x ), Y( y ) {}

// Math
inline vector2 vector2::operator+(const vector2& vector) const
{
    return vector2(X + vector.X, Y + vector.Y);
}

inline vector2 vector2::operator-(const vector2& vector) const
{
    return vector2(X - vector.X, Y - vector.Y);
}
inline vector2 vector2::operator*(const vector2& vector) const
{
    return vector2(X * vector.X, Y * vector.Y);
}
inline vector2 vector2::operator/(const vector2& vector) const
{
    return vector2(X / vector.X, Y / vector.Y);
}
inline vector2& vector2::operator+=(const vector2& vector)
{
    X += vector.X;
    Y += vector.Y;
    return *this;
}

inline vector2& vector2::operator-=(const vector2& vector)
{
    X -= vector.X;
    Y -= vector.Y;
    return *this;
}
inline vector2& vector2::operator*=(const vector2& vector)
{
    X *= vector.X;
    Y *= vector.Y;
    return *this;
}

inline vector2& vector2::operator/=(const vector2& vector)
{
    X /= vector.X;
    Y /= vector.Y;
    return *this;
}

inline vector2 vector2::operator-() const
{
    return vector2(-X,-Y);
}
inline vector2 vector2::operator-(float const&num) const
{
    return vector2(X - num, Y - num);
}
inline vector2 vector2::operator+(float const&num) const
{
    return vector2(X + num, Y + num);
}
inline vector2 vector2::operator*(float const&num) const
{
    return vector2(X * num, Y * num);
}

inline vector2 vector2::operator/(float const&num) const
{
    return vector2(X / num, Y / num);
}
inline vector2& vector2::operator+=(const float& num)
{
    X += num;
    Y += num;
    return *this;
}

inline vector2& vector2::operator-=(const float& num)
{
    X -= num;
    Y -= num;
    return *this;
}
inline vector2& vector2::operator*=(const float& num)
{
    X *= num;
    Y *= num;
    return *this;
}

inline vector2& vector2::operator/=(const float& num)
{
    X /= num;
    Y /= num;
    return *this;
}
//Boolean
inline bool vector2::operator==(const vector2& vector) const
{
    return X == vector.X && Y == vector.Y;
}

inline bool vector2::operator!=(const vector2& vector) const
{
    return X != vector.X || Y != vector.Y;
}
//-----------------------------------------------------------------------------------
//Fast Static members
//-----------------------------------------------------------------------------
const vector2 vector2::Zero = vector2(0,0);
const vector2 vector2::One = vector2(1,1);
/*
//Subtractes the two vector2 objects
inline const vector2 operator-(vector2 const&lhs,vector2 const&rhs){
	return vector2(lhs.X-rhs.X,lhs.Y-rhs.Y);
}
//Adds the two vector2 objects
inline const vector2 operator+(vector2 const&lhs,vector2 const&rhs){
	return vector2(lhs.X+rhs.X,lhs.Y+rhs.Y);
}
//divides the two vector2 objects
inline const vector2 operator/(vector2 const&lhs,float const&rhs){
	return vector2(lhs.X/rhs,lhs.Y/rhs);
}
//Multiplies the two vector2 objects
inline const vector2 operator*(float lhs,vector2 const &rhs){
	vector2 result;
	result.X=rhs.X * lhs;
	result.Y=rhs.Y * lhs;
	return result;
}
//Subtractes the two vector2 objects
inline const vector2& operator-=(vector2 &lhs,const vector2 &rhs){
	lhs.X-=rhs.X;
	lhs.Y-=rhs.Y;
	return lhs;
}
//Adds the two vector2 objects
inline const vector2& operator+=(vector2 &lhs,const vector2 &rhs){
	lhs.X+=rhs.X;
	lhs.Y+=rhs.Y;
	return  lhs;
}
//Divides the two vector2 objects
inline const vector2& operator/=(vector2 &lhs,const vector2 &rhs){
	lhs.X/=rhs.X;
	lhs.Y/=rhs.Y;
	return  lhs;
}
//Multiplies the two vector2 objects
inline const vector2& operator*=(vector2 &lhs,const vector2 &rhs){
	lhs.X*=rhs.X;
	lhs.Y*=rhs.Y;
	return  lhs;
}
//Multiplies the vector2 object by a float
inline const vector2& operator*=(vector2 &lhs,const float &rhs){
	lhs.X*=rhs;
	lhs.Y*=rhs;
	return  lhs;
}
//Compares the two vector2 objects and returns (true) if they are not equal
inline const bool operator!=(vector2 const&lhs,vector2 const&rhs){
	return (lhs.X != rhs.X) || (lhs.Y != rhs.Y);
 }
//Compares the two vector2 objects and returns (true) if they are equal
inline const bool operator==(vector2 const&lhs,vector2 const&rhs){
  return ((lhs.X * rhs.X<(float)0.000001) && (lhs.Y * rhs.Y<(float)0.000001) );
}
*/

//Sets the vector2 with zero values
inline void zero(vector2 &lhs)
{
    lhs.X=0.0f;
    lhs.Y=0.0f;
}
//Returns if the vector2 is zero
inline const bool isZero(vector2 const&lhs)
{
    return (lhs.X*lhs.X+lhs.Y*lhs.Y)<(float)0.000001;//EPSILON
}
//Returns dot product
inline const float dot(vector2 const&lhs,vector2 const&rhs)
{
    return lhs.X*rhs.X+lhs.Y*rhs.Y;
}
//Returns length squared
inline const float lengthSquared(vector2 const&rhs)
{
    return dot(rhs,rhs);
}
//Returns magnitude (length)
inline const float magnitude(vector2 const &rhs)
{
    //return sqrtf(dot(rhs, rhs));
    return sqrt(dot(rhs, rhs));
}
//Returns normalized vector2
inline vector2 normalize(vector2 const &lhs)
{
    return lhs*(1.f /(magnitude(lhs)));
}
//Normalizes
inline void toNormalized(vector2 &vector)
{
    vector = vector*(1.f /(magnitude(vector)));
}
//Returns cross product for vector2
inline float cross(vector2 const &lhs, vector2 const &rhs)
{
    return (lhs.X * rhs.Y - lhs.Y * rhs.X);
}
//Returns (Vector2) cross product of the Vector2 objects
inline vector2 crossVec(vector2 const &vec2, vector2 const &vec1)
{
    return vector2(
               vec2.Y * vec1.X-vec1.Y * vec2.X,
               vec2.X * vec1.Y -vec1.X * vec2.Y);
}
//Returns Negative or Positive (value of one)
inline const int sign(const vector2& lhs,const vector2& rhs)
{
    if (lhs.Y*rhs.X > lhs.X*rhs.Y)
    {
        return -1;
    }
    else
    {
        return 1;
    }
}
//Returns perpendicular vector2
inline const vector2 perpendicular(vector2 const &rhs)
{
    return vector2(-rhs.Y, rhs.X);
}
//Clamps vector2 values to max
inline void truncate(vector2 &rhs,float const& max)
{
    if (magnitude(rhs) > max)
    {
        normalize(rhs);
        rhs =rhs* max;
    }
}
//Returns inverse (negative) vector2
inline vector2 negate(vector2 const &rhs)
{
    return vector2(-rhs.X, -rhs.Y);
}
//Returns distance between the vector2's
inline double dist(vector2 const&lhs,vector2 const&rhs)
{
    double ySeparation = rhs.Y - lhs.Y;
    double xSeparation = rhs.X - lhs.X;

    //return sqrtf(ySeparation*ySeparation + xSeparation*xSeparation);
    return sqrt(ySeparation*ySeparation + xSeparation*xSeparation);
}
//Returns squared distance between the vector2's
inline double distanceSquared(vector2 const&lhs,vector2 const&rhs)
{
    double ySeparation = rhs.Y - lhs.Y;
    double xSeparation = rhs.X - lhs.X;

    return ySeparation*ySeparation + xSeparation*xSeparation;
}
//Returns the lhs vector2 reflected over the rhs vector2
inline vector2 reflect(vector2 const&lhs,vector2 const&rhs)
{
    vector2 out;
    const float dotProductTimesTwo = dot(rhs,lhs) * 2.0f;
    out.X=rhs.X -(dotProductTimesTwo * lhs.X);
    out.Y=rhs.Y - (dotProductTimesTwo * lhs.Y);
    return out;
}
//Output display of values
inline std::ostream& operator<< (std::ostream& os, const vector2& vector)
{
    std::stringstream stream;
    stream << "X: " << vector.X << ", Y: " << vector.Y ;
    os.write(const_cast<char*>(stream.str().c_str()), static_cast<std::streamsize>(stream.str().size() * sizeof(char)) );
    return os;
}


}
}
#endif
