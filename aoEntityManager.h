#ifndef AOENTITYMANAGER_H
#define AOENTITYMANAGER_H
#include <map>
#include <cassert>
#include "aoEntity.h"
//class BaseEntity;

class EntityManager
{
private:
    //need to make my own
    typedef std::map<int,BaseEntity*> EntityMap;
    EntityMap m_EntityMap;
    EntityManager() {}
public:
    static EntityManager* Instance()
    {
        static EntityManager instance;

        return &instance;
    }
    void RegisterEntity(BaseEntity * NewEntity)
    {
        m_EntityMap.insert(std::make_pair(NewEntity->ID(), NewEntity));
    }
    BaseEntity* FindEntityFromID(int id)const
    {
        //find the entity
        EntityMap::const_iterator ent = m_EntityMap.find(id);

        //assert that the entity is a member of the map
        assert ( (ent !=  m_EntityMap.end()) && "<EntityManager::GetEntityFromID>: invalid ID");

        return ent->second;
    }
    void RemoveEntity(BaseEntity*entity)
    {
        m_EntityMap.erase(m_EntityMap.find(pEntity->ID()));
    }

};
//provide easy access
#define EntityManager EntityManger::Instance();
}
}
#endif

