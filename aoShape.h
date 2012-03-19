/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOSHAPE_H
#define AOSHAPE_H
#include "vector3.h"
#include "vector2.h"
#include "aoMath.h"
namespace ao
{
namespace core
{

//
// Circle
// (struct template)
// ----------
// + vec : vector2
// + r : float
// + Circle()
// + circle(float,vector2)
// ----------
// + set(vector2) : void
// + set(float) : void
// + set(float, vector2) : float
// + set(int, vector2) : float
// + get(vector2) : float
// + get(float) : float
// + get(float,vector2) : void
// + get(float,float) : void
// ----------
//
struct Circle
{
    vector2 vec;
    float r;
    Circle():r(0),vec(vector2()) {}
    Circle(float const&newR,vector2 const&newVec):r(newR),vec(newVec) {}
    //Excess
    void set(vector2 const&newVec);
    void set(float const&newR);
    void set(float const&newR,vector2 const&newVec);
    void set(int count,vector2 const*vertices);
    void get(vector2 &newVec) const;
    void get(float &newR) const;
    void get(float &newR,vector2 &newVec) const;
    void get(float &newX,float &newY) const ;
};
//
// Sphere
// (struct template)
// ----------
// + vec : vector3
// + r : float
// + Sphere()
// + Sphere(float,vector3)
// ----------
// + set(vector3) : void
// + set(float) : void
// + set(float, vector3) : float
// + set(int, vector3) : float
// + get(vector3) : float
// + get(float) : float
// + get(float,vector3) : void
// + get(float,float,float) : void
// ----------
//
struct Sphere
{
    vector3 vec;
    float r;
    Sphere():r(0),vec(vector3()) {}
    Sphere(float const&newR,vector3 const&newVec):r(newR),vec(newVec) {}
    //Excess
    void set(vector3 const&newVec);
    void set(float const&newR);
    void set(float const&newR,vector3 const&newVec);
    void set(int count,vector3 const*vertices);;
    void get(vector3 &newVec) const;
    void get(float &newR) const;
    void get(float &newR,vector3 &newVec) const;
    void get(float &newX,float &newY,float &newZ) const ;
};
//
// Plane
// (struct template)
// ----------
// + normal : vector3
// + d : float
// + Plane()
// + Plane(vector3,float)
// + Plane(vector3, vector3, vector3)
// ----------
//
struct Plane
{
    vector3 normal;
    float d;
    Plane();
    Plane(vector3 const&,float);
    Plane(vector3 const&a,vector3 const&b,vector3 const&c);
};
//
// Vertex
// (struct template)
// ----------
// + normal : vector3
// + position : vector3
// + texcoord : vector2
// + color : int
// + Vertex()
// + Vertex(int, vector3, vector3,vector2)
// ----------
//
struct Vertex
{
    vector3 position;
    vector2 texcoord;
    vector3 normal;
    unsigned int color;//bits per each value of color
    Vertex();
    Vertex(unsigned int const&newColor,vector3 const&newPosition,vector3 const&newNormal,vector2 const&newTex);
};
//Vertex
inline Vertex::Vertex()
{
    position=vector3();
    texcoord=vector2();
    normal=vector3();
    color=0;
}
inline Vertex::Vertex(unsigned int const&newColor,vector3 const&newPosition,vector3 const&newNormal,vector2 const&newTex)
{
    position=newPosition;
    texcoord=newTex;
    normal=newNormal;
    color=newColor;
}
//Circle
inline void Circle::set(vector2 const&newVec)
{
    vec=newVec;
}
inline void Circle::set(float const&newR)
{
    r=newR;
}
inline void Circle::set(float const&newR,vector2 const&newVec)
{
    set(newR);
    set(newVec);
}
inline void Circle::set(int count,vector2 const *vertices)
{
    for(int index=0; index<count; index++)
    {
        vec=vec+vertices[index];
    }
    vec=vec/count;
    for(int index=0; index<count; index++)
    {
        r=max(r,lengthSquared(vec));
    }
    r=sqrt(r);
}
inline void Circle::get(vector2 &newVec)const
{
    newVec=vec;
}
inline void Circle::get(float &newR) const
{
    newR=r;
}
inline void Circle::get(float &newR,vector2 &newVec) const
{
    get(newR);
    get(newVec);
}
inline void Circle::get(float &newX,float &newY) const
{
    newX=vec.X;
    newY=vec.Y;
}

//Sphere
inline void Sphere::set(vector3 const&newVec)
{
    vec=newVec;
}
inline void Sphere::set(float const&newR)
{
    r=newR;
}
inline void Sphere::set(float const&newR,vector3 const&newVec)
{
    set(newR);
    set(newVec);
}
inline void Sphere::set(int count,vector3 const *vertices)
{
    for(int index=0; index<count; index++)
    {
        vec=vec+vertices[index];
    }
    vec=vec/count;
    for(int index=0; index<count; index++)
    {
        r=max(r,lengthSquared(vec));
    }
    r=sqrt(r);
}
inline void Sphere::get(vector3 &newVec)const
{
    newVec=vec;
}
inline void Sphere::get(float &newR) const
{
    newR=r;
}
inline void Sphere::get(float &newR,vector3 &newVec) const
{
    get(newR);
    get(newVec);
}
inline void Sphere::get(float &newX,float &newY,float &newZ) const
{
    newX=vec.X;
    newY=vec.Y;
    newZ=vec.Z;
}

//Plane Constructors
inline Plane::Plane()
{
    normal=vector3();
    d=0;
}
inline Plane::Plane(vector3 const&newNormal,float newD)
{
    //
    normal=newNormal;
    d=newD;

}
inline Plane::Plane(vector3 const&a,vector3 const&b,vector3 const&c)
{
    //cross product of(b-a) and (c-a)
    normal=cross((b-a),(c-a));
    normal=normalize(normal);
    d=dot(normal,a);
}
}
}
#endif
