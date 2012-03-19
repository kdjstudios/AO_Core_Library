/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOLINE_H
#define AOLINE_H
#include "vector3.h"
#include "vector2.h"
namespace ao
{
namespace core
{
//
// Line
// (struct template)
// ----------
// + m : float
// + b : float
// + Line()
// + Line(float,float)
// + Line(float,float, float,float)
// ----------
// + compute : void
// + compute : void
// + setM : void
// + setB : void
// + getM : float
// + getB : float
// + getX : float
// + getY : float
// ----------
//
struct Line
{
    float M,B;
    Line();
    Line(float const&newM,float const&newB);
    Line(vector2 const&V1,vector2 const&V2);
    Line(float const&xOne,float const&yOne,float const&xTwo,float const&yTwo);
    //Excess
    void compute(float const&xOne,float const&yOne,float const&xTwo,float const&yTwo);
    void compute(vector2 const&V1,vector2 const&V2);
    void setM(float const&newM);
    void setB(float const&newB);
    float getY(float const&X);
    float getX(float const&Y);
    float getM();
    float getB();
};

//line
inline Line::Line()
{
    M=0;
    B=0;
}
inline Line::Line(float const& newM,float const&newB)
{
    M=newM;
    B=newB;
}
inline Line::Line(float const&xOne,float const&yOne,float const&xTwo,float const&yTwo)
{
    //compute(xOne,yOne,xTwo,yTwo);
    M=(yOne-yTwo)/(xOne-xTwo);
    B=yOne-(M*xOne);
}
inline Line::Line(vector2 const&V1,vector2 const&V2)
{
    //compute(V1,V2);
    M=(V1.Y-V2.Y)/(V1.X-V2.X);
    B=V1.Y-(M*V1.X);
}

//Line
inline void Line::compute(float const&xOne,float const&yOne,float const&xTwo,float const&yTwo)
{
    M=(yOne-yTwo)/(xOne-xTwo);
    B=yOne-(M*xOne);
}
inline void Line::compute(vector2 const&V1,vector2 const&V2)
{
    compute(V1.X,V1.Y,V2.X,V2.Y);
}
inline void Line::setM(float const&newM)
{
    M=newM;
}
inline void Line::setB(float const&newB)
{
    B=newB;
}
inline float Line::getY(float const&X)
{
    return (M*X)+B;
}
inline float Line::getX(float const&Y)
{
    //y=M*x+B
    return 0;
}
inline float Line::getM()
{
    return M;
}
inline float Line::getB()
{
    return B;
}

//line2d
class line2d
{
protected:

    vector2    m_vA,
    m_vB,
    m_vN;

    void CalculateNormal()
    {
        vector2 temp = normalize(m_vB - m_vA);

        m_vN.X = -temp.Y;
        m_vN.Y = temp.X;
    }

public:

    line2d() {}

    line2d(vector2 A, vector2 B):m_vA(A), m_vB(B)
    {
        CalculateNormal();
    }

    line2d(vector2 A, vector2 B, vector2 N):m_vA(A), m_vB(B), m_vN(N)
    { }

    //line2d(std::ifstream& in){Read(in);}

    vector2 From()const
    {
        return m_vA;
    }
    void     SetFrom(vector2 v)
    {
        m_vA = v;
        CalculateNormal();
    }

    vector2 To()const
    {
        return m_vB;
    }
    void     SetTo(vector2 v)
    {
        m_vB = v;
        CalculateNormal();
    }

    vector2 Normal()const
    {
        return m_vN;
    }
    void     SetNormal(vector2 n)
    {
        m_vN = n;
    }

    vector2 Center()const
    {
        return (m_vA+m_vB)/2.0;
    }
    /*



    //should be inline?
    std::ostream& operator<< (std::ostream& os, const line2d& rhs)
    {
      os << std::endl;
      os << From() << ",";
      os << To() << ",";
      os << Normal();
      return os;
    }

     void Read(std::ifstream& in)
    {
      double x,y;

      in >> x >> y;
      SetFrom(vector2(x,y));

      in >> x >> y;
      SetTo(vector2(x,y));

       in >> x >> y;
      SetNormal(vector2(x,y));
    }*/
};
//line3d
class line3d
{
public:
    line3d();
};

//
// Check for an intersection (HitPos) between a line(LP1,LP2) and a triangle face (TP1, TP2, TP3)
//
bool CheckLineTri( vector3 TP1, vector3 TP2, vector3 TP3, vector3 LP1, vector3 LP2, vector3 &HitPos)
{
    vector3 Normal, IntersectPos;

    // Find Triangle Normal
    Normal = cross( TP2 - TP1, TP3 - TP1 );
    Normal = normalize(Normal); // not really needed

    // Find distance from LP1 and LP2 to the plane defined by the triangle
    float Dist1 = dot((LP1-TP1), Normal );
    float Dist2 = dot((LP2-TP1), Normal );
    if ( (Dist1 * Dist2) >= 0.0f) return false;  // line doesn't cross the triangle.
    if ( Dist1 == Dist2) return false;// line and plane are parallel

    // Find point on the line that intersects with the plane
    IntersectPos = LP1 + (LP2-LP1) * ( -Dist1/(Dist2-Dist1) );

    // Find if the interesection point lies inside the triangle by testing it against all edges
    vector3 vTest;
    vTest = cross( Normal, TP2-TP1 );
    if ( dot( vTest, IntersectPos-TP1) < 0.0f ) return false;
    vTest = cross( Normal, TP3-TP2 );
    if ( dot( vTest, IntersectPos-TP2) < 0.0f ) return false;
    vTest = cross( Normal, TP1-TP3 );
    if ( dot( vTest, IntersectPos-TP1) < 0.0f ) return false;

    HitPos = IntersectPos;
    return true;
}
}
}
#endif
