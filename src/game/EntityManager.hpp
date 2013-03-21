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

#include "Component.hpp"
#include "Entity.hpp"

#include "../core/NonCopyable.hpp"

#define OW_MAX_COMPONENTS 64

namespace ow
{
    class EntityManager : public NonCopyable
    {
    public:
        typedef std::bitset<OW_MAX_COMPONENTS> ComponentMask;

        EntityManager();
        ~EntityManager();

        Entity create();
        void destroy(Entity::Id entity);

        template<typename C>
        std::shared_ptr<C> assign(Entity::Id entity)
        {
            return assign<C>(entity, std::make_shared<C>());
        }

        template <typename C>
        std::shared_ptr<C> assign(Entity::Id entityId, std::shared_ptr<C> component)
        {
            resizeForComponent(C::Family);

            m_entityComponentMasks[entityId][C::Family] = true;
            m_entityComponents[C::Family][entityId] = component;

            return component;
        }

        template <typename C>
        bool has(Entity::Id entityId)
        {
            return m_entityComponentMasks[entityId][C::Family];
        }

        template <typename C>
        std::shared_ptr<C> get(Entity::Id entityId)
        {
            if (m_entityComponentMasks[entityId][C::Family])
            {
                // Trust me compiler it is of type "C"
                return std::static_pointer_cast<C>(m_entityComponents[C::Family][entityId]);
            }
            else
            {
                return nullptr;
            }
        }

        template <typename C>
        ComponentMask createComponentMask()
        {
            ComponentMask mask;
            mask.set(C::Family);

            return mask;
        }

        template <typename C1, typename C2, typename ... Components>
        ComponentMask createComponentMask()
        {
            return createComponentMask<C1>() | createComponentMask<C2, Components ...>();
        }

        template <typename C, typename ... Components>
        std::vector<Entity> entitiesWithComponents()
        {
            ComponentMask mask = createComponentMask<C, Components ...>();
            return entitiesWithMask(mask);
        }

        std::vector<Entity> entitiesWithMask(ComponentMask bitSet)
        {
            Entity::Id currentId = 0;
            std::vector<Entity> entities;

            for (auto mask : m_entityComponentMasks)
            {
                if ((mask &= bitSet) == bitSet)
                {
                    entities.push_back(Entity(this, currentId));
                }

                currentId++;
            }

            return entities;
        }

    private:
        std::vector<Entity::Id> m_aliveEntities;
        std::vector<Entity::Id> m_deadEntities;

        std::vector<ComponentMask> m_entityComponentMasks;
        std::vector<std::vector<std::shared_ptr<BaseComponent>>> m_entityComponents;

        unsigned int m_nextEntityId;

        // Resizes to fit new component
        void resizeForComponent(BaseComponent::Family family);

        // Resizes to fit new entity
        void resizeForEntity(Entity::Id entity);


    };
}

#endif // ENTITY_MANAGER_H
