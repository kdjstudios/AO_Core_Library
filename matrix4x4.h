/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOmatrix4_H
#define AOmatrix4_H

#include <cmath>
#include "vector3.h"
#include "vector4.h"
#include "aoMath.h"
namespace ao
{
namespace core
{
class matrix4x4
{
public:
    float xx,xy,xz,xw;
    float yx,yy,yz,yw;
    float zx,zy,zz,zw;
    float wx,wy,wz,ww;
    matrix4x4():xx(1),xy(0),xz(0),xw(0),yx(0),yy(1),yz(0),yw(0),zx(0),zy(0),zz(1),zw(0),wx(0),wy(0),wz(0),ww(1) {}
    matrix4x4(float const&newXX,float const&newXY,float const&newXZ,float const&newXW,float const&newYX,float const&newYY,float const&newYZ,float const&newYW,float const&newZX,float const&newZY,float const&newZZ,float const&newZW,float const&newWX,float const&newWY,float const&newWZ,float const&newWW)
        :xx(newXX),xy(newXY),xz(newXZ),xw(newXW),yx(newYX),yy(newYY),yz(newYZ),yw(newYW),zx(newZX),zy(newZY),zz(newZZ),zw(newZW),wx(newWX),wy(newWY),wz(newWZ),ww(newWW) {}
};

//Matric4x4 operands
//Adds the matrix4x4 objects
inline matrix4x4 operator+(matrix4x4 const&lhs,matrix4x4 const&rhs)
{
    return matrix4x4(
               lhs.xx+rhs.xx,lhs.xy+rhs.xy,lhs.xz+rhs.xz,lhs.xw+rhs.xw,
               lhs.yx+rhs.yx,lhs.yy+rhs.yy,lhs.yz+rhs.yz,lhs.yw+rhs.yw,
               lhs.zx+rhs.zx,lhs.zy+rhs.zy,lhs.zz+rhs.zz,lhs.zw+rhs.zw,
               lhs.wx+rhs.wx,lhs.wy+rhs.wy,lhs.wz+rhs.wz,lhs.ww+rhs.ww);
}
//Subtracts the matrix4x4 objects
inline matrix4x4 operator-(matrix4x4 const&lhs,matrix4x4 const&rhs)
{
    return matrix4x4(
               lhs.xx-rhs.xx,lhs.xy-rhs.xy,lhs.xz-rhs.xz,lhs.xw-rhs.xw,
               lhs.yx-rhs.yx,lhs.yy-rhs.yy,lhs.yz-rhs.yz,lhs.yw-rhs.yw,
               lhs.zx-rhs.zx,lhs.zy-rhs.zy,lhs.zz-rhs.zz,lhs.zw-rhs.zw,
               lhs.wx-rhs.wx,lhs.wy-rhs.wy,lhs.wz-rhs.wz,lhs.ww-rhs.ww);
}
//Multiplies the matrix4x4 objects
inline matrix4x4 operator*(matrix4x4 const&lhs,matrix4x4 const&rhs)
{
    return matrix4x4(
               (lhs.xx*rhs.xx)+(lhs.xy*rhs.yx)+(lhs.xz*rhs.zx)+(lhs.xw*rhs.wx),
               (lhs.xx*rhs.xy)+(lhs.xy*rhs.yy)+(lhs.xz*rhs.zy)+(lhs.xw*rhs.wy),
               (lhs.xx*rhs.xz)+(lhs.xy*rhs.yz)+(lhs.xz*rhs.zz)+(lhs.xw*rhs.wz),
               (lhs.xx*rhs.xw)+(lhs.xy*rhs.yw)+(lhs.xz*rhs.zw)+(lhs.xw*rhs.ww),

               (lhs.yx*rhs.xx)+(lhs.yy*rhs.yx)+(lhs.yz*rhs.zx)+(lhs.yw*rhs.wx),
               (lhs.yx*rhs.xy)+(lhs.yy*rhs.yy)+(lhs.yz*rhs.zy)+(lhs.yw*rhs.wy),
               (lhs.yx*rhs.xz)+(lhs.yy*rhs.yz)+(lhs.yz*rhs.zz)+(lhs.yw*rhs.wz),
               (lhs.yx*rhs.xw)+(lhs.yy*rhs.yw)+(lhs.yz*rhs.zw)+(lhs.yw*rhs.ww),

               (lhs.zx*rhs.xx)+(lhs.zy*rhs.yx)+(lhs.zz*rhs.zx)+(lhs.zw*rhs.wx),
               (lhs.zx*rhs.xy)+(lhs.zy*rhs.yy)+(lhs.zz*rhs.zy)+(lhs.zw*rhs.wy),
               (lhs.zx*rhs.xz)+(lhs.zy*rhs.yz)+(lhs.zz*rhs.zz)+(lhs.zw*rhs.wz),
               (lhs.zx*rhs.xw)+(lhs.zy*rhs.yw)+(lhs.zz*rhs.zw)+(lhs.zw*rhs.ww),

               (lhs.wx*rhs.xx)+(lhs.wy*rhs.yx)+(lhs.wz*rhs.zx)+(lhs.ww*rhs.wx),
               (lhs.wx*rhs.xy)+(lhs.wy*rhs.yy)+(lhs.wz*rhs.zy)+(lhs.ww*rhs.wy),
               (lhs.wx*rhs.xz)+(lhs.wy*rhs.yz)+(lhs.wz*rhs.zz)+(lhs.ww*rhs.wz),
               (lhs.wx*rhs.xw)+(lhs.wy*rhs.yw)+(lhs.wz*rhs.zw)+(lhs.ww*rhs.ww));
}
//excess math for matrix4x4
//Calculates the matrix4x4 "look" from position and orientation
inline matrix4x4 look(vector3 const&eye,vector3 const&target,vector3 const&up)
{
    //
    vector3 zAxis=normalize(eye-target);
    vector3 xAxis=normalize(cross(up,zAxis));
    vector3 yAxis=cross(zAxis,xAxis);
    return matrix4x4(
               xAxis.X,yAxis.X,zAxis.X,0,
               xAxis.Y,yAxis.Y,zAxis.Y,0,
               xAxis.Z,yAxis.Z,zAxis.Z,0,
               -dot(xAxis,eye),-dot(yAxis,eye),-dot(zAxis,eye),1);
}
//Calculates the matrix4x4 "perspective" from feild of view, aspect ratio, close, far
inline matrix4x4 perspective(float fov,float aspect,float znear,float zfar)
{
    //float yScale=::atan(.5*fov);
    float yScale=atan(.5*fov);
    float xScale=yScale/aspect;
    return matrix4x4(
               xScale,0,0,0,
               0,yScale,0,0,
               0,0,zfar/(znear-zfar),-1,
               0,0,znear*zfar/(znear-zfar),0);
}
//Calculates the matrix4x4 translated by vector3
inline matrix4x4 translate(vector3 const&vec)
{
    return matrix4x4(
               1,0,0,0,
               0,1,0,0,
               0,0,1,0,
               vec.X,vec.Y,vec.Z,1);
}
//Calculates the matrix4x4 scaled by vector3
inline matrix4x4 scale(vector3 const&vec)
{
    return matrix4x4(
               vec.X,0,0,0,
               0,vec.Y,0,0,
               0,0,vec.Z,0,
               0,0,0,1);
}
//Calculates a rotation matrix4x4 on X-Axis by theta (degrees)
inline matrix4x4 rotateX(float thetaX)
{
    //float C=cosf(thetaX);
    //float S=sinf(thetaX);
    float C=cos(thetaX);
    float S=sin(thetaX);
    return matrix4x4(
               1,0,0,0,
               0,C,-S,0,
               0,S,C,0,
               0,0,0,1);
}
//Calculates a rotation matrix4x4 on Y-Axis by theta (degrees)
inline matrix4x4 rotateY(float thetaY)
{
    //float C=cosf(thetaY);
    //float S=sinf(thetaY);
    float C=cos(thetaY);
    float S=sin(thetaY);
    return matrix4x4(
               C,0,-S,0,
               0,1,0,0,
               S,0,C,0,
               0,0,0,1);
}
//Calculates a rotation matrix4x4 on Z-Axis by theta (degrees)
inline matrix4x4 rotateZ(float thetaZ)
{
    //float C=cosf(thetaZ);
    //float S=sinf(thetaZ);
    float C=cos(thetaZ);
    float S=sin(thetaZ);
    return matrix4x4(
               C,-S,0,0,
               S,C,0,0,
               0,0,1,0,
               0,0,0,1);
}
//Calculates a rotation matrix4x4 on all Axis; First Y, Second X, Thrid Z (degrees)
inline matrix4x4 rotateYXZ(float pitch,float roll, float yaw)
{
    //x=roll
    //y=pitch
    //z=yaw
    matrix4x4 temp;
    if(!equ(pitch,0.0f))
    {
        temp=rotateY(pitch);
    }
    if(!equ(roll,0.0f))
    {
        temp=temp*rotateX(roll);
    }
    if(!equ(yaw,0.0f))
    {
        temp=temp*rotateZ(yaw);
    }
    return temp;
}
//Returns vector4 of matrix4x4 multiplied by vector4
inline vector4 operator*(vector4 const& lhs,matrix4x4 const&rhs)
{
    return vector4(
               (lhs.x*rhs.xx)+(lhs.y*rhs.yx)+(lhs.z*rhs.zx)+(lhs.w*rhs.wx),
               (lhs.x*rhs.xy)+(lhs.y*rhs.yy)+(lhs.z*rhs.zy)+(lhs.w*rhs.wy),
               (lhs.x*rhs.xz)+(lhs.y*rhs.yz)+(lhs.z*rhs.zz)+(lhs.w*rhs.wz),
               (lhs.x*rhs.xw)+(lhs.y*rhs.yw)+(lhs.z*rhs.zw)+(lhs.w*rhs.ww));
}
//Returns vector3 transformed from matrix4x4 (Vertex)
inline vector3 transform(vector3 const&lhs,matrix4x4 const&rhs)
{
    vector4 result=vector4(lhs.X,lhs.Y,lhs.Z,1)*rhs;
    float coeff=1/result.w;
    return vector3(result.x,result.y,result.z)*coeff;
}
//Output display of values
inline std::ostream& operator<< (std::ostream& os, const matrix4x4& rhs)
{
    std::stringstream stream;
    stream << "XX: " << rhs.xx << ", XY: " << rhs.xy << ", XZ: " << rhs.xz << ", XW: " << rhs.xw << std::endl;
    stream << "YX: " << rhs.yx << ", YY: " << rhs.yy << ", YZ: " << rhs.yz << ", YW: " << rhs.yw << std::endl;
    stream << "ZX: " << rhs.zx << ", ZY: " << rhs.zy << ", ZZ: " << rhs.zz << ", ZW: " << rhs.zw << std::endl;
    stream << "wX: " << rhs.zx << ", WY: " << rhs.zy << ", wZ: " << rhs.zz << ", WW: " << rhs.ww << std::endl;
    os.write(const_cast<char*>(stream.str().c_str()), static_cast<std::streamsize>(stream.str().size() * sizeof(char)) );
    return os;
}

}
}
#endif
