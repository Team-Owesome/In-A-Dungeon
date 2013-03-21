//
// Created by till on 2/25/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "EntityManager.hpp"


using namespace ow;

EntityManager::EntityManager() : m_nextEntityId(0)
{
}

EntityManager::~EntityManager()
{
}

void EntityManager::resizeForComponent(BaseComponent::Family family)
{
    if (m_entityComponents.size() <= family)
    {
        m_entityComponents.resize(family + 1);
        m_entityComponents[family].resize(m_nextEntityId);
    }
}

void EntityManager::resizeForEntity(Entity::Id entity)
{
    if (m_entityComponentMask.size() <= entity)
    {
        m_entityComponentMask.resize(entity + 1);
        for (auto& component : m_entityComponents)
        {
            m_entityComponents.resize(entity + 1);
        }
    }
}


Entity EntityManager::create()
{
    Entity::Id nextEntityId;

    // Reuse dead entites
    if (m_deadEntities.size() != 0)
    {
        nextEntityId = m_deadEntities.back();
        m_deadEntities.pop_back();
    }
    else
    {
        unsigned int newId = m_nextEntityId++;
        nextEntityId = newId;

        resizeForEntity(nextEntityId);
    }

    m_aliveEntities.push_back(nextEntityId);

    return Entity(this, nextEntityId);
}

void EntityManager::destroy(Entity::Id entity)
{
    auto it = std::find(m_aliveEntities.begin(), m_aliveEntities.end(), entity);

    if (it != m_aliveEntities.end())
    {
        m_deadEntities.push_back(*it);
        m_aliveEntities.erase(it);
    }
}


