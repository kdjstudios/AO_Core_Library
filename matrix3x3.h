/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOmatrix3_H
#define AOmatrix3_H
#include "quaternion.h"
namespace ao
{
namespace core
{

class matrix3x3
{
public:
    float xx,xy,xz;
    float yx,yy,yz;
    float zx,zy,zz;
    matrix3x3():xx(1),xy(0),xz(0),yx(0),yy(1),yz(0),zx(0),zy(0),zz(1) {}
    matrix3x3(float const&newXX,float const&newXY,float const&newXZ,float const&newYX,float const&newYY,float const&newYZ,float const&newZX,float const&newZY,float const&newZZ)
        :xx(newXX),xy(newXY),xz(newXZ),yx(newYX),yy(newYY),yz(newYZ),zx(newZX),zy(newZY),zz(newZZ) {}
};

//Matric3x3 operands
//Adds the matrix3x3 objects
inline matrix3x3 operator+(matrix3x3 const&lhs,matrix3x3 const&rhs)
{
    return matrix3x3(
               lhs.xx+rhs.xx,lhs.xy+rhs.xy,lhs.xz+rhs.xz,
               lhs.yx+rhs.yx,lhs.yy+rhs.yy,lhs.yz+rhs.yz,
               lhs.zx+rhs.zx,lhs.zy+rhs.zy,lhs.zz+rhs.zz);
}
//Subtracts the matrix3x3 objects
inline matrix3x3 operator-(matrix3x3 const&lhs,matrix3x3 const&rhs)
{
    return matrix3x3(
               lhs.xx-rhs.xx,lhs.xy-rhs.xy,lhs.xz-rhs.xz,
               lhs.yx-rhs.yx,lhs.yy-rhs.yy,lhs.yz-rhs.yz,
               lhs.zx-rhs.zx,lhs.zy-rhs.zy,lhs.zz-rhs.zz);
}
//Multiplies the matrix3x3 objects
inline matrix3x3 operator*(matrix3x3 const&lhs,matrix3x3 const&rhs)
{
    return matrix3x3(
               (lhs.xx*rhs.xx)+(lhs.xy*rhs.yx)+(lhs.xz*rhs.zx),(lhs.xx*rhs.xy)+(lhs.xy*rhs.yy)+(lhs.xz*rhs.zy),(lhs.xx*rhs.xz)+(lhs.xy*rhs.yz)+(lhs.xz*rhs.zz),
               (lhs.yx*rhs.xx)+(lhs.yy*rhs.yx)+(lhs.yz*rhs.zx),(lhs.yx*rhs.xy)+(lhs.yy*rhs.yy)+(lhs.yz*rhs.zy),(lhs.yx*rhs.xz)+(lhs.xy*rhs.yz)+(lhs.yz*rhs.zz),
               (lhs.zx*rhs.xx)+(lhs.zy*rhs.yx)+(lhs.zz*rhs.zx),(lhs.zx*rhs.xy)+(lhs.zy*rhs.yy)+(lhs.zz*rhs.zy),(lhs.zx*rhs.xz)+(lhs.zy*rhs.yz)+(lhs.zz*rhs.zz));
}
//
inline Quaternion toQuaternion(matrix3x3 m1)
{
    Quaternion ret;
    ret.W = sqrt(1.0 + m1.xx + m1.yy + m1.zz) / 2.0;
    double w4 = (4.0 * ret.W);
    ret.X = (m1.zy - m1.yz) / w4 ;
    ret.Y = (m1.xz - m1.zx) / w4 ;
    ret.Z = (m1.yx - m1.xy) / w4 ;
    return ret;
}
//
inline matrix3x3 quatToMatrix(Quaternion q)
{
    matrix3x3 ret;
    double sqw = q.W*q.W;
    double sqx = q.X*q.X;
    double sqy = q.Y*q.Y;
    double sqz = q.Z*q.Z;

    // invs (inverse square length) is only required if quaternion is not already normalised
    double invs = 1 / (sqx + sqy + sqz + sqw);
    ret.xx = ( sqx - sqy - sqz + sqw)*invs ; // since sqw + sqx + sqy + sqz =1/invs*invs
    ret.yy = (-sqx + sqy - sqz + sqw)*invs ;
    ret.zz = (-sqx - sqy + sqz + sqw)*invs ;

    double tmp1 = q.X*q.Y;
    double tmp2 = q.Z*q.W;
    ret.yx = 2.0 * (tmp1 + tmp2)*invs ;
    ret.xy = 2.0 * (tmp1 - tmp2)*invs ;

    tmp1 = q.X*q.Z;
    tmp2 = q.Y*q.W;
    ret.zx = 2.0 * (tmp1 - tmp2)*invs ;
    ret.xz = 2.0 * (tmp1 + tmp2)*invs ;
    tmp1 = q.Y*q.Z;
    tmp2 = q.X*q.W;
    ret.zy = 2.0 * (tmp1 + tmp2)*invs ;
    ret.yz = 2.0 * (tmp1 - tmp2)*invs ;
    return ret;
}
//Output display of values
inline std::ostream& operator<< (std::ostream& os, const matrix3x3& rhs)
{
    std::stringstream stream;
    stream << "XX: " << rhs.xx << ", XY: " << rhs.xy << ", XZ: " << rhs.xz << std::endl;
    stream << "YX: " << rhs.yx << ", YY: " << rhs.yy << ", YZ: " << rhs.yz << std::endl;
    stream << "ZX: " << rhs.zx << ", ZY: " << rhs.zy << ", ZZ: " << rhs.zz << std::endl;
    os.write(const_cast<char*>(stream.str().c_str()), static_cast<std::streamsize>(stream.str().size() * sizeof(char)) );
    return os;
}
}
}
#endif
