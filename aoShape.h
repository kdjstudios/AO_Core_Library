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
// + r : double
// + Circle()
// + circle(double,vector2)
// ----------
// + set(vector2) : void
// + set(double) : void
// + set(double, vector2) : double
// + set(int, vector2) : double
// + get(vector2) : double
// + get(double) : double
// + get(double,vector2) : void
// + get(double,double) : void
// ----------
//
struct Circle
{
    vector2 vec;
    double r;
    Circle():r(0),vec(vector2()) {}
    Circle(double const&newR,vector2 const&newVec):r(newR),vec(newVec) {}
    //Excess
    void set(vector2 const&newVec);
    void set(double const&newR);
    void set(double const&newR,vector2 const&newVec);
    void set(int count,vector2 const*vertices);
    void get(vector2 &newVec) const;
    void get(double &newR) const;
    void get(double &newR,vector2 &newVec) const;
    void get(double &newX,double &newY) const ;
};
//
// Sphere
// (struct template)
// ----------
// + vec : vector3
// + r : double
// + Sphere()
// + Sphere(double,vector3)
// ----------
// + set(vector3) : void
// + set(double) : void
// + set(double, vector3) : double
// + set(int, vector3) : double
// + get(vector3) : double
// + get(double) : double
// + get(double,vector3) : void
// + get(double,double,double) : void
// ----------
//
struct Sphere
{
    vector3 vec;
    double r;
    Sphere():r(0),vec(vector3()) {}
    Sphere(double const&newR,vector3 const&newVec):r(newR),vec(newVec) {}
    //Excess
    void set(vector3 const&newVec);
    void set(double const&newR);
    void set(double const&newR,vector3 const&newVec);
    void set(int count,vector3 const*vertices);;
    void get(vector3 &newVec) const;
    void get(double &newR) const;
    void get(double &newR,vector3 &newVec) const;
    void get(double &newX,double &newY,double &newZ) const ;
};
//
// Plane
// (struct template)
// ----------
// + normal : vector3
// + d : double
// + Plane()
// + Plane(vector3,double)
// + Plane(vector3, vector3, vector3)
// ----------
//
struct Plane
{
    vector3 normal;
    double d;
    Plane();
    Plane(vector3 const&,double);
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
inline void Circle::set(double const&newR)
{
    r=newR;
}
inline void Circle::set(double const&newR,vector2 const&newVec)
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
inline void Circle::get(double &newR) const
{
    newR=r;
}
inline void Circle::get(double &newR,vector2 &newVec) const
{
    get(newR);
    get(newVec);
}
inline void Circle::get(double &newX,double &newY) const
{
    newX=vec.X;
    newY=vec.Y;
}

//Sphere
inline void Sphere::set(vector3 const&newVec)
{
    vec=newVec;
}
inline void Sphere::set(double const&newR)
{
    r=newR;
}
inline void Sphere::set(double const&newR,vector3 const&newVec)
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
inline void Sphere::get(double &newR) const
{
    newR=r;
}
inline void Sphere::get(double &newR,vector3 &newVec) const
{
    get(newR);
    get(newVec);
}
inline void Sphere::get(double &newX,double &newY,double &newZ) const
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
inline Plane::Plane(vector3 const&newNormal,double newD)
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
