#ifndef RECT_H
#define RECT_H

#include "aoMath.h"

#include "vector2.h"

namespace ao
{
namespace core
{
class Rect
{
public:

    enum Rect_modifier {halfsize, normal};

protected:

    double        m_dTop;
    double        m_dLeft;
    double        m_dRight;
    double        m_dBottom;

    double        m_dWidth;
    double        m_dHeight;

    vector2     m_vCenter;

    int          m_iID;

public:

    Rect():m_dTop(0),m_dBottom(0),m_dLeft(0),m_dRight(0)
    {}


    Rect(double left,
         double top,
         double right,
         double bottom,
         int id = -1):m_dTop(top),
        m_dRight(right),
        m_dLeft(left),
        m_dBottom(bottom),
        m_iID(id)
    {
        //calculate center of Rect
        m_vCenter = vector2( (left+right)*0.5f, (top+bottom)*0.5f );

        m_dWidth  = fabs(right-left);
        m_dHeight = fabs(bottom-top);
    }

    virtual ~Rect() {}

    //returns true if the given position lays inside the Rect. The
    //Rect modifier can be used to contract the Rect bounderies
    inline bool     Inside(vector2 pos, Rect_modifier r)const;

    //returns a vector representing a random location
    //within the Rect
    inline vector2 GetRandomPosition()const;

    //-------------------------------
    double     Top()const
    {
        return m_dTop;
    }
    double     Bottom()const
    {
        return m_dBottom;
    }
    double     Left()const
    {
        return m_dLeft;
    }
    double     Right()const
    {
        return m_dRight;
    }
    double     Width()const
    {
        return fabs(m_dRight - m_dLeft);
    }
    double     Height()const
    {
        return fabs(m_dTop - m_dBottom);
    }
    double     Length()const
    {
        return max(Width(), Height());
    }
    double     Breadth()const
    {
        return min(Width(), Height());
    }

    vector2  Center()const
    {
        return m_vCenter;
    }
    int       ID()const
    {
        return m_iID;
    }

};


/*
inline vector2 Rect::GetRandomPosition()const
{
  return vector2(RandInRange(m_dLeft, m_dRight),
                   RandInRange(m_dTop, m_dBottom));
}
*/
inline bool Rect::Inside(vector2 pos, Rect_modifier r=normal)const
{
    if (r == normal)
    {
        return ((pos.X > m_dLeft) && (pos.X < m_dRight) &&
                (pos.Y > m_dTop) && (pos.Y < m_dBottom));
    }
    else
    {
        const double marginX = m_dWidth * 0.25;
        const double marginY = m_dHeight * 0.25;

        return ((pos.X > (m_dLeft+marginX)) && (pos.X < (m_dRight-marginX)) &&
                (pos.Y > (m_dTop+marginY)) && (pos.Y < (m_dBottom-marginY)));
    }

}


}
}
#endif
