/*
ONLY FILE NEEDED TO INCLUDE
*/
#ifndef AOENTITY_H
#define AOENTITY_H


namespace ao{
namespace core{

class BaseEntity{//:public Entity{
private:
	int m_ID;
	int m_EntityTag;//used to designate a type of object(should have defaults somewhere)
	int m_Flag;//
	//int m_Layer;//Used for?
	int NextValidID(){static int NextID=0;return NextID++;}
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
                   m_Flag(false){}
	BaseEntity(int type, vector3 pos, double radius):m_Position(pos),
                                        m_BoundingRadius(radius),
                                        m_ID(NextValidID()),
                                        m_Scale(vector3(1.0,1.0,1.0)),
                                        m_EntityTag(type),
                                        m_Flag(false){}
	BaseEntity(int type, vector3 pos, double radius,vector3 scale):m_Position(pos),
                                        m_BoundingRadius(radius),
                                        m_ID(NextValidID()),
                                        m_Scale(scale),
                                        m_EntityTag(type),
                                        m_Flag(false){}
	BaseEntity(int type, int ForcedID):m_ID(ForcedID),
                                        m_BoundingRadius(0.0),
                                        m_Scale(vector3(1.0,1.0,1.0)),
                                        m_EntityTag(type),
                                        m_Flag(false){}

	virtual ~BaseEntity(){}
	virtual void Update(double time_elapsed){};
	virtual void Render(){}
	virtual bool HandleMessage(const Telegram& msg){return false;}

	//virtual void Write(std::ostream&  os)const{}
	//virtual void Read (std::ifstream& is){}

  vector3      Position()const{return m_Position;}
  void         SetPosition(vector3 new_pos){m_Position = new_pos;}

  double       BoundingRadius()const{return m_BoundingRadius;}
  void         SetBoundingRadius(double r){m_BoundingRadius = r;}
  int          ID()const{return m_ID;}

  bool         IsFlagged()const{return m_Flag;}
  void         Flag(){m_Flag = true;}
  void         UnFlag(){m_Flag = false;}

  vector3      Scale()const{return m_Scale;}
  void         SetScale(vector3 val){m_BoundingRadius *= max(val.X, val.Y)/max(m_Scale.X, m_Scale.Y); m_Scale = val;}
  void         SetScale(double val){m_BoundingRadius *= (val/max(m_Scale.X, m_Scale.Y)); m_Scale = vector3(val,val,val);}

  int          EntityTag()const{return m_EntityTag;}
  void         SetEntityTag(int new_tag){m_EntityTag = new_tag;}

};
//TODO: maybe this should be bodyentity?
class MovingEntity:public BaseEntity{
protected:
	vector3 m_Velocity;
	vector3 m_Heading;
	vector3 m_Side;
	//Physics used with RigidBodys and GeneralApplyForces
	double m_Mass;
	double m_MaxSpeed;
	double m_MaxForce;
	double m_MaxTurnRate;
public:
	MovingEntity(vector3 position,vector3 heading,vector3 scale, vector3 velocity,double radius,
               double max_speed, double mass, double turn_rate,
               double max_force):BaseEntity((int)0, position, radius, scale),
                                  m_Heading(heading),
                                  m_Velocity(velocity),
                                  m_Mass(mass),
                                  m_Side(perpendicular(m_Heading)),
                                  m_MaxSpeed(max_speed),
                                  m_MaxTurnRate(turn_rate),
                                  m_MaxForce(max_force)
								  {}
	virtual ~MovingEntity(){}

  //Functionality
  vector3  Velocity()const{return m_Velocity;}
  void      SetVelocity(const vector3& NewVel){m_Velocity = NewVel;}

  double     Mass()const{return m_Mass;}

  vector3 Side()const{return m_Side;}

  double     MaxSpeed()const{return m_MaxSpeed;}
  void      SetMaxSpeed(double new_speed){m_MaxSpeed = new_speed;}

  double     MaxForce()const{return m_MaxForce;}
  void      SetMaxForce(double maxforce){m_MaxForce = maxforce;}

  bool      IsSpeedMaxedOut()const{return m_MaxSpeed*m_MaxSpeed >= lengthSquared(m_Velocity);}
  double     Speed()const{return magnitude(m_Velocity);}
  double     SpeedSq()const{return lengthSquared(m_Velocity);}

  vector3  Heading()const{return m_Heading;}
  void      SetHeading(vector3 new_heading);
  bool      RotateHeadingToFacePosition(vector3 target);

  double     MaxTurnRate()const{return m_MaxTurnRate;}
  void      SetMaxTurnRate(double val){m_MaxTurnRate = val;}

};
//#define EntityManager EntityManger::Instance();
class EntityManager{
private:
	//need to make my own
	//typedef std::map<int,BaseGameEntity*> EntityMap;
	//EntityMap m_EntityMap;
	EntityManager(){}
public:
	static EntityManager* Instance(){}
	void RegisterEntity(BaseEntity * NewEntity);
	BaseEntity* FindEntityFromID(int id)const;
	void RemoveEntity(BaseEntity*entity);

};
}
}
#endif
