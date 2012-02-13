/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOVECTOR3_H
#define AOVECTOR3_H

#include <ostream>
#include <sstream>
#include <cmath>
//#include "aoMath.h"
//#include "dimension2d.h"

namespace ao{
namespace core{
class vector3
		{
		public:
			//Members
			float X;
			float Y;
			float Z;
			//Constructors
			vector3();
			explicit vector3(float const&x, float const&y, float const&z);
			//vector3 by vector3 Math
			vector3		operator+(const vector3& vector) const;
			vector3		operator-(const vector3& vector) const;
			vector3		operator*(const vector3& vector) const;
			vector3		operator/(const vector3& vector) const;
			vector3&	operator+=(const vector3& vector);
			vector3&	operator-=(const vector3& vector);
			vector3&	operator*=(const vector3& vector);
			vector3&	operator/=(const vector3& vector);
			//vector3 by Float Math
			vector3		operator-() const;
			vector3		operator+(float const&num) const;
			vector3		operator-(float const&num) const;
			vector3		operator*(float const&num) const;
			vector3		operator/(float const&num) const;
			vector3&	operator+=(float const&num);
			vector3&	operator-=(float const&num);
			vector3&	operator*=(float const&num);
			vector3&	operator/=(float const&num);
			//Boolean Equals Operators
			bool		operator==(const vector3& vector) const;
			bool		operator!=(const vector3& vector) const;
			//Static Predefines
			static const vector3 Zero;
			static const vector3 Left;
			static const vector3 Right;
			static const vector3 Up;
			static const vector3 Down;
			static const vector3 Forward;
			static const vector3 Backward;

			//Print out
			friend std::ostream& operator<< (std::ostream& ofs, const vector3& vector);
		};

		//Constructors
		inline vector3::vector3(){}
		inline vector3::vector3(float const&x, float const&y, float const&z): X( x ), Y( y ), Z( z ){}

		// Math
		inline vector3 vector3::operator+(const vector3& vector) const
		{
			return vector3(X + vector.X, Y + vector.Y, Z + vector.Z);
		}

		inline vector3 vector3::operator-(const vector3& vector) const
		{
			return vector3(X - vector.X, Y - vector.Y, Z - vector.Z);
		}
		inline vector3 vector3::operator*(const vector3& vector) const
		{
			return vector3(X * vector.X, Y * vector.Y, Z * vector.Z);
		}
		inline vector3 vector3::operator/(const vector3& vector) const
		{
			return vector3(X / vector.X, Y / vector.Y, Z / vector.Z);
		}
		inline vector3& vector3::operator+=(const vector3& vector)
		{
			X += vector.X;
			Y += vector.Y;
			Z += vector.Z;
			return *this;
		}

		inline vector3& vector3::operator-=(const vector3& vector)
		{
			X -= vector.X;
			Y -= vector.Y;
			Z -= vector.Z;
			return *this;
		}
		inline vector3& vector3::operator*=(const vector3& vector)
		{
			X *= vector.X;
			Y *= vector.Y;
			Z *= vector.Z;
			return *this;
		}

		inline vector3& vector3::operator/=(const vector3& vector)
		{
			X /= vector.X;
			Y /= vector.Y;
			Z /= vector.Z;
			return *this;
		}

		inline vector3 vector3::operator-() const
		{
			return vector3(-X,-Y,-Z);
		}
		inline vector3 vector3::operator-(float const&num) const
		{
			return vector3(X - num, Y - num, Z - num);
		}
		inline vector3 vector3::operator+(float const&num) const
		{
			return vector3(X + num, Y + num, Z + num);
		}
		inline vector3 vector3::operator*(float const&num) const
		{
			return vector3(X * num, Y * num, Z * num);
		}

		inline vector3 vector3::operator/(float const&num) const
		{
			return vector3(X / num, Y / num, Z / num);
		}
		inline vector3& vector3::operator+=(const float& num)
		{
			X += num;
			Y += num;
			Z += num;
			return *this;
		}

		inline vector3& vector3::operator-=(const float& num)
		{
			X -= num;
			Y -= num;
			Z -= num;
			return *this;
		}
		inline vector3& vector3::operator*=(const float& num)
		{
			X *= num;
			Y *= num;
			Z *= num;
			return *this;
		}

		inline vector3& vector3::operator/=(const float& num)
		{
			X /= num;
			Y /= num;
			Z /= num;
			return *this;
		}
		//Boolean
		inline bool vector3::operator==(const vector3& vector) const
		{
			return X == vector.X && Y == vector.Y && Z == vector.Z;
		}

		inline bool vector3::operator!=(const vector3& vector) const
		{
			return X != vector.X || Y != vector.Y || Z != vector.Z;
		}
		//-----------------------------------------------------------------------------------
		//Fast Static members
		//-----------------------------------------------------------------------------

		const vector3 vector3::Zero = vector3(0,0,0);
		const vector3 vector3::Left = vector3(-1.f, 0.f, 0.f);
		const vector3 vector3::Right = vector3(1.f, 0.f, 0.f);
		const vector3 vector3::Up = vector3(0.f, 1.f, 0.f);
		const vector3 vector3::Down = vector3(0.f, -1.f, 0.f);
		const vector3 vector3::Forward = vector3(0.f, 0.f, 1.f);
		const vector3 vector3::Backward = vector3(0.f, 0.f, -1.f);

		//-----------------------------------------------------------------------------------
		//Fast non-member functions
		//-----------------------------------------------------------------------------

		//Returns (Float) dot product of the two vector3 objects
		inline float dot(vector3 const&vec1,vector3 const&vec2){
			return vec2.X*vec1.X+vec2.Y*vec1.Y+vec2.Z*vec1.Z;
		}
		//Returns (Float) length squared of the vector3 object
		inline float lengthSquared(vector3 const&vector){
			return dot(vector,vector);
		}
		//Returns (Float) magnitude (length) of the vector3 object
		inline float magnitude(vector3 const &vector){
			return sqrt(dot(vector, vector));
		}
		//Returns (Float) distance squared between the two vector3 objects
		inline float distanceSquared(vector3 const&vec1,vector3 const&vec2){
		  double ySeparation = vec1.Y - vec2.Y;
		  double xSeparation = vec1.X - vec2.X;
		  double zSeparation = vec1.Z - vec2.Z;
		  return (float)ySeparation*ySeparation + xSeparation*xSeparation+ zSeparation*zSeparation;
		}
		//Returns (Float) distance between the two vector3 objects
		inline float dist(vector3 const&vec1,vector3 const&vec2){
		  double ySeparation = vec1.Y - vec2.Y;
		  double xSeparation = vec1.X - vec2.X;
		  double zSeparation = vec1.Z - vec2.Z;
		  return sqrtf(ySeparation*ySeparation + xSeparation*xSeparation+ zSeparation*zSeparation);
		}



		//Voids
		inline void setMagnitude(vector3& vec2, float const&num)
		{
			vec2 *= num / magnitude(vec2);
		}
		//Sets
		inline void setLengthSquared(vector3& vector, float const&num)
		{
			float vecLength = lengthSquared(vector);

			if(vecLength == 0)
			{
				return;
			}

			vector *= num / sqrt(vecLength);
		}
		//Returns a normalized vector3 of the vector3 object
		inline vector3 normalize(vector3 const &vector){
			return vector * (1.f /(magnitude(vector)));
		}
		inline void toNormalized(vector3 &vector){
			vector *= (1.f /(magnitude(vector)));
		}
		inline void toPolar(vector3 &vector,float const&x, float const&y, float const&z)
		{
			vector=vector3(
				atan2(y,x),
				sqrt(x * x + y * y),
				z);
		}

		inline void toCartesian(vector3 &vector,float const&radius, float const&angle, float const&z)
		{
			vector= vector3(
				radius * cos(angle),
				radius * sin(angle),
				z);
		}
		inline void toEuler(vector3 &vector,vector3 axis, float const& angle)
		{
			vector3 out = vector3();

			float s = sin(angle);
			float c = cos(angle);
			float t = static_cast<float>(1.0) - c;

			if ((axis.X * axis.Y * t + axis.Z * s) > static_cast<float>(0.998))// north pole singularity detected
			{
				out.Y = static_cast<float>(2.0) * atan2(axis.X * sin(angle / static_cast<float>(2.0)), cos(angle / static_cast<float>(2.0)));
				out.Z = static_cast<float>(1.57079633);//PI/2
				out.X = 0;
				vector= out;
				return;
			}
			if ((axis.X * axis.Y * t + axis.Z * s) < static_cast<float>(-0.998))// south pole singularity detected
			{
				out.Y = static_cast<float>(-2.0) * atan2(axis.X * sin(angle / static_cast<float>(2.0)), cos(angle / static_cast<float>(2.0)));
				out.Z = -static_cast<float>(1.57079633);//PI/2
				out.X = 0;
				vector=out;
				return;
			}
			out.Y = atan2(axis.Y * s - axis.X * axis.Z * t , 1 - (axis.Y * axis.Y + axis.Z * axis.Z ) * t);
			out.Z = asin(axis.X * axis.Y * t + axis.Z * s) ;
			out.X = atan2(axis.X * s - axis.Y * axis.Z * t , 1 - (axis.X * axis.X + axis.Z * axis.Z) * t);
			vector= out;
		}
		//Returns (vector3) cross product of the vector3 objects
		inline vector3 cross(vector3 const &vec2, vector3 const &vec1){
			return vector3(
				vec2.Y * vec1.Z-vec1.Y * vec2.Z,
				-(vec2.X * vec1.Z - vec1.X * vec2.Z),
				vec2.X * vec1.Y -vec1.X * vec2.Y);
		}
		//Returns (vector3) a perpendicular vector3 of the vector3 object
		inline const vector3 perpendicular(vector3 const &vector){
			return vector3(-vector.Z,vector.X,-vector.Y);//right
		}

		//Clamps (vector3) values of the vector3 object to max
		inline void truncate(vector3 &vector,double const& max){
			if (magnitude(vector) > max)
			{
				toNormalized(vector);
				vector *= max;
			}
		}
		//Sets (vector3) values of the vector3 object to zero
		inline void toZero(vector3 &vec2){
			vec2.X=0.0f;
			vec2.Y=0.0f;
			vec2.Z=0.0f;
		}
		//Returns (Boolean) True if the vector3 object is zero else False
		inline const bool isZero(vector3 const&vector){
			return (vector.X*vector.X+vector.Y*vector.Y+vector.Z*vector.Z)<(float)0.000001;//EPSILON
		}
		//TODO:Returns negative or positive (value of one)
		inline const int sign(const vector3& vec1,const vector3& vec2){
			if (vec2.Y*vec1.X > vec2.X*vec1.Y)
		  {
		    return -1;
		  }
		  else
		  {
		    return 1;
		  }
		}
		//Returns (vector3) inverse (negative) of the vector3 object
		inline vector3 negate(vector3 const &vec1){
			return vector3(-vec1.X, -vec1.Y,-vec1.Z);
		}


		//Returns (vector3) of vec1 "Assumed Velocity" reflected over the vec2 "Assumed Normal"  object
		inline vector3 reflect(vector3 const& vec1, const vector3& vec2 )
		{
			vector3 out;
			const float dotProductTimesTwo = dot(vec2,vec1) * 2.0f;
			out.X=vec2.X -(dotProductTimesTwo * vec1.X);
			out.Y=vec2.Y - (dotProductTimesTwo * vec1.Y);
			out.Z=vec2.Z -(dotProductTimesTwo * vec1.Z);
			return out;
		}
		//Returns (vector3) of vec1 linearly interpolated to vec2 with the percent of num
		inline vector3 lerp(vector3 const&vec1, vector3 const&vec2, float const& num)
		{
		     return (vec1 + ((vec2 - vec1)*num));
		}
		//TODO: Clamp value
		//Returns (vector3) of vec1 Spherically interpolated to vec2 with the percent of num
		inline vector3 slerp(vector3 const& vec1, vector3 const&vec2, float const& num)
		{
		     float doot = dot(vec1, vec2);
		     //math.clamp(doot, -1,1);
		     float theta = acos(doot)*num;
		     vector3 RelativeVec = vec2 - vec1*doot;
		     toNormalized(RelativeVec);
		     return ((vec1*cos(theta)) + (RelativeVec*sin(theta)));
		}
		//Returns (vector3) of "Normalized" vec1 interpolated to vec2 with the percent of num
		inline vector3 nlerp(vector3 const& vec1, vector3 const&vec2, float const& num)
		{
		     return normalize(lerp(vec1,vec2,num));
		}

		//Output display of values
		inline std::ostream& operator<< (std::ostream& os, const vector3& vector)
		{
			std::stringstream stream;
			stream << "X: " << vector.X << ", Y: " << vector.Y << ", Z: " << vector.Z;
			os.write(const_cast<char*>(stream.str().c_str()), static_cast<std::streamsize>(stream.str().size() * sizeof(char)) );
			return os;
		}
}
}

#endif
