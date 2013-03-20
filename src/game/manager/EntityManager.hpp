//
// Created by till on 2/25/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef ENTITY_MANAGER_H
#define ENTITY_MANAGER_H

#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>

#include "../Component.hpp"
#include "../Entity.hpp"


namespace ow
{
    class EntityManager
    {
    private:
        //std::vector<std::unordered_map<std::string, Component*>> m_components;

        std::vector<Entity> m_aliveEntities;
        std::vector<Entity> m_deadEntities;

        std::vector<std::vector<std::shared_ptr<BaseComponent>>> m_componentEntities;
        std::vector<std::vector<Entity::Id>> m_entityComponents;

        unsigned int m_nextEntityId;

    public:
        EntityManager();
        ~EntityManager();

        Entity create();

        template <typename C>
        std::shared_ptr<C> assign(Entity& entity, std::shared_ptr<C> component)
        {

            std::shared_ptr<BaseComponent> basePtr = component;



            return nullptr;
        }

        void removeEntity(const Entity& entity);

    };
}

#endif // ENTITY_MANAGER_H
