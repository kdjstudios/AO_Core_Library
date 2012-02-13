
//
/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOMATRIX2_H
#define AOMATRIX2_H
#include "vector2.h"

namespace ao{
    namespace core{

    class matrix2x2
		{
		public:
            float xx,xy;
            float yx,yy;
            matrix2x2():xx(1),xy(0),yx(0),yy(1){}
            matrix2x2(float const&newXX,float const&newXY,float const&newYX,float const&newYY):xx(newXX),xy(newXY),yx(newYX),yy(newYY){}
            //
            matrix2x2 operator+(matrix2x2 const&rhs);
            matrix2x2 operator-(matrix2x2 const&rhs);
            matrix2x2 operator*(matrix2x2 const&rhs);
            vector2 operator*(vector2 const&rhs);
            //
            static const matrix2x2 Zero;
            static const matrix2x2 One;
            //Print out
			friend std::ostream& operator<< (std::ostream& ofs, const vector2& vector);
        };

        const matrix2x2 Zero = matrix2x2(0,0,0,0);
        const matrix2x2 One = matrix2x2(1,1,1,1);
        //matrix2x2 operands
        //Adds the matrix2x2 objects
        inline matrix2x2 matrix2x2::operator+(matrix2x2 const&rhs){
            return matrix2x2(xx+rhs.xx,xy+rhs.xy,yx+rhs.yx,yy+rhs.yy);
        }
        //Subtracts the matrix2x2 objects
        inline matrix2x2 matrix2x2::operator-(matrix2x2 const&rhs){
            return matrix2x2(xx-rhs.xx,xy-rhs.xy,yx-rhs.yx,yy-rhs.yy);
        }
        //Multiplies the matrix2x2 objects
        inline matrix2x2 matrix2x2::operator*(matrix2x2 const&rhs){
            return matrix2x2(
                (xx*rhs.xx)+(xy*rhs.yx),(xx*rhs.xy)+(xy*rhs.yy),
                (yx*rhs.xx)+(yy*rhs.yx),(yx*rhs.xy)+(yy*rhs.yy));
        }
        //excess math for matrix2x2
        //Returns a rotation matrix2x2  for theta (degrees)
        inline matrix2x2 rotation2d(float theta){
            //float C=cosf(theta);
            //float S=sinf(theta);
            float C=cos(theta);
            float S=sin(theta);
            return matrix2x2(C,-S,S,C);
        }
        //Returns Vector2 multiplied by the matrix2x2 object
        inline vector2 matrix2x2::operator*(vector2 const&rhs){
            //
            return vector2((xx*rhs.X)+(xy*rhs.Y),(yx*rhs.X)+(yy*rhs.Y));
        }
        //Output display of values
		inline std::ostream& operator<< (std::ostream& os, const matrix2x2& rhs)
		{
			std::stringstream stream;
			stream << "XX: " << rhs.xx << ", XY: " << rhs.xy << ", YX: " << rhs.yx << ", YY: " << rhs.yy;
			os.write(const_cast<char*>(stream.str().c_str()), static_cast<std::streamsize>(stream.str().size() * sizeof(char)) );
			return os;
		}

}
}
#endif
