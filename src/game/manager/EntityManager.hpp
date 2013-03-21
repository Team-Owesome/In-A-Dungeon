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

        std::vector<std::bitset<64>> m_entityComponentMask;
        std::vector<std::vector<std::shared_ptr<BaseComponent>>> m_entityComponents;

        unsigned int m_nextEntityId;

        // Resizes to fit new component
        void resizeForComponent(BaseComponent::Family family);

        // Resizes to fit new entity
        void resizeForEntity(Entity::Id entity);

    public:
        EntityManager();
        ~EntityManager();

        Entity create();

        template<typename C>
        std::shared_ptr<C> assign(Entity::Id entity)
        {
            return assign<C>(entity, std::make_shared<C>());
        }

        template <typename C>
        std::shared_ptr<C> assign(Entity::Id entityId, std::shared_ptr<C> component)
        {
            resizeForComponent(C::Family);

            m_entityComponentMask[entityId][C::Family] = true;
            m_entityComponents[C::Family][entityId] = component;

            return component;
        }

        template <typename C>
        bool has(Entity::Id entityId)
        {
            return m_entityComponentMask[entityId][C::Family];
        }

        template <typename C>
        std::shared_ptr<C> get(Entity::Id entityId)
        {
            if (m_entityComponentMask[entityId][C::Family])
            {
                return m_entityComponents[C::Family][entityId];
            }
            else
            {
                return nullptr;
            }
        }

        void removeEntity(const Entity& entity);

    };
}

#endif // ENTITY_MANAGER_H
