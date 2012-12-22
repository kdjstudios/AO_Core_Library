/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOENTITY_H
#define AOENTITY_H

#include "vector3.h"
#include "aoTelegram.h"
#include "aoMath.h"

namespace ao
{
	using namespace core;
namespace graphics
{

class BaseEntity //:public Entity{
{
private:
    int m_ID;
    int m_EntityTag;//used to designate a type of object(should have defaults somewhere)
    int m_Flag;//
    //int m_Layer;//Used for?
    int NextValidID()
    {
        static int NextID=0;
        return NextID++;
    }
    //Stuff Below will be implemented later
    bool updating;
    BaseEntity* m_Parent;
    BaseEntity* m_Childs;
    BaseEntity* m_NewChilds;
    int m_ChildCount;
    int m_NewChildCount;
    int m_MaxObjects;
    bool m_Die;
    //-------------------------------
protected:
	vector3 m_Position;
    vector3 m_Scale;
    double m_BoundingRadius;
public:
    BaseEntity():m_ID(NextValidID()),
        m_BoundingRadius(0.0),
        m_Position(vector3()),
        m_Scale(vector3(1.0,1.0,1.0)),
        m_EntityTag(-1),//this is just a defalut
        m_Flag(false) {}
    BaseEntity(int type, vector3 pos, double radius):m_Position(pos),
        m_BoundingRadius(radius),
        m_ID(NextValidID()),
        m_Scale(vector3(1.0,1.0,1.0)),
        m_EntityTag(type),
        m_Flag(false) {}
    BaseEntity(int type, vector3 pos, double radius,vector3 scale):m_Position(pos),
        m_BoundingRadius(radius),
        m_ID(NextValidID()),
        m_Scale(scale),
        m_EntityTag(type),
        m_Flag(false) {}
    BaseEntity(int type, int ForcedID):m_ID(ForcedID),
        m_BoundingRadius(0.0),
        m_Scale(vector3(1.0,1.0,1.0)),
        m_EntityTag(type),
        m_Flag(false) {}

    virtual ~BaseEntity() {}
    virtual void Update(double time_elapsed) {};
    virtual void Render() {}
    virtual bool HandleMessage(const Telegram& msg)
    {
        return false;
    }

    //virtual void Write(std::ostream&  os)const{}
    //virtual void Read (std::ifstream& is){}

    vector3      Position()const
    {
        return m_Position;
    }
    void         SetPosition(vector3 new_pos)
    {
        m_Position = new_pos;
    }

    double       BoundingRadius()const
    {
        return m_BoundingRadius;
    }
    void         SetBoundingRadius(double r)
    {
        m_BoundingRadius = r;
    }
    int          ID()const
    {
        return m_ID;
    }

    bool         IsFlagged()const
    {
        return m_Flag != 0;
    }
    void         Flag()
    {
        m_Flag = true;
    }
    void         UnFlag()
    {
        m_Flag = false;
    }

    vector3      Scale()const
    {
        return m_Scale;
    }
    void         SetScale(vector3 val)
    {
        m_BoundingRadius *= max(val.X, val.Y)/max(m_Scale.X, m_Scale.Y);
        m_Scale = val;
    }
    void         SetScale(double val)
    {
        m_BoundingRadius *= (val/max(m_Scale.X, m_Scale.Y));
        m_Scale = vector3(val,val,val);
    }

    int          EntityTag()const
    {
        return m_EntityTag;
    }
    void         SetEntityTag(int new_tag)
    {
        m_EntityTag = new_tag;
    }

};


}
}
#endif
