/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOvector4_H
#define AOvector4_H

namespace ao{
namespace core{
    class vector4{
        public:
        float x,y,z,w;
        vector4():x(0),y(0),z(0),w(0){}
        vector4(float const&newX,float const&newY,float const&newZ,float const&newW):x(newX),y(newY),z(newZ),w(newW){}
        //

    };

    //vector4 operands
    //Subtracts the vector4 objects
    inline vector4 operator-(vector4 const&lhs,vector4 const&rhs){
        return vector4(lhs.x-rhs.x,lhs.y-rhs.y,lhs.z-rhs.z,lhs.w-rhs.w);
    }
    //Adds the vector4 objects
    inline vector4 operator+(vector4 const&lhs,vector4 const&rhs){
        return vector4(lhs.x+rhs.x,lhs.y+rhs.y,lhs.z+rhs.z,lhs.w+rhs.w);
    }
    //Divides the vector4 objects
    inline vector4 operator/(vector4 const&lhs,float const&rhs){
        return vector4(lhs.x/rhs,lhs.y/rhs,lhs.z/rhs,lhs.w/rhs);
    }
    //Multiplies the vector4 objects
    inline vector4 operator*(vector4 const &lhs,float rhs){
        vector4 result;
        result.x=lhs.x * rhs;
        result.y=lhs.y * rhs;
        result.z=lhs.z * rhs;
        return result;
    }
    //Multiplies the vector4 object by float
    inline vector4 operator*(float lhs,vector4 const &rhs){
        vector4 result;
        result.x=rhs.x * lhs;
        result.y=rhs.y * lhs;
        result.z=rhs.z * lhs;
        return result;
    }
    //Returns dot product of the vector4 objects
    inline float dot(vector4 const&lhs,vector4 const&rhs){
        //return lhs.x*rhs.x+lhs.y*rhs.y+lhs.z*rhs.z;
        return lhs.x*rhs.x+lhs.y*rhs.y+lhs.z*rhs.z+rhs.w*rhs.w;
    }
    //Returns length squared of the vector4 object
    inline float lengthSquared(vector4 const&rhs){
        return dot(rhs,rhs);
    }
    //Returns magnitude (length) of the vector4 object
    inline float magnitude(vector4 const &rhs){
        return sqrt(dot(rhs, rhs));
    }
    //Returns nomalized vector4 of the vector4 object
    inline vector4 normalize(vector4 const &lhs){
        return lhs * (1.f /(magnitude(lhs)));
    }
//Output display of values
		inline std::ostream& operator<< (std::ostream& os, const vector4& vector)
		{
			std::stringstream stream;
			stream << "X: " << vector.x << ", Y: " << vector.y << ", Z: " << vector.z <<", W: " << vector.w;
			os.write(const_cast<char*>(stream.str().c_str()), static_cast<std::streamsize>(stream.str().size() * sizeof(char)) );
			return os;
		}
}
}
#endif
