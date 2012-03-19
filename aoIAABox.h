#ifndef IAABOX2_H
#define IAABOX2_H
/*-----------------------------------------------------------------------------
simple inverted (y increases down screen) axis aligned bounding box class
//-----------------------------------------------------------------------------*/

#include "vector2.h"
namespace ao
{
namespace core
{

class IAABox2
{
private:

    vector2  m_vTopLeft;
    vector2  m_vBottomRight;

    vector2  m_vCenter;

public:

    IAABox2(vector2 tl,
            vector2 br):m_vTopLeft(tl),
        m_vBottomRight(br),
        m_vCenter((tl+br)/2.0)
    {}

    //returns true if the bbox described by other intersects with this one
    bool isOverlappedWith(const IAABox2& other)const
    {
        return !((other.Top() > this->Bottom()) ||
                 (other.Bottom() < this->Top()) ||
                 (other.Left() > this->Right()) ||
                 (other.Right() < this->Left()));
    }


    vector2 TopLeft()const
    {
        return m_vTopLeft;
    }
    vector2 BottomRight()const
    {
        return m_vBottomRight;
    }

    double    Top()const
    {
        return m_vTopLeft.Y;
    }
    double    Left()const
    {
        return m_vTopLeft.X;
    }
    double    Bottom()const
    {
        return m_vBottomRight.Y;
    }
    double    Right()const
    {
        return m_vBottomRight.X;
    }
    vector2 Center()const
    {
        return m_vCenter;
    }



};
}
}
#endif
