//
// Created by till on 2/25/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <iostream>
#include <vector>
#include <unordered_map>

#include "../Component.hpp"

namespace ow
{
    class Entity;

    class EntityManager
    {
    private:
        //std::vector<std::unordered_map<std::string, Component*>> m_components;

        std::vector<Entity> m_aliveEntities;
        std::vector<Entity> m_deadEntities;

        unsigned int m_nextEntityId;

    public:
        EntityManager();
        ~EntityManager();

        Entity createEntity();
        void removeEntity(const Entity& entity);

    };
}

#endif // ENTITY_MANAGER_H
