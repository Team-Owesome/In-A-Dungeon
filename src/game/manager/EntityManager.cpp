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


Entity EntityManager::create()
{
    Entity nextEntity;

    // Reuse dead entites
    if (m_deadEntities.size() != 0)
    {
        nextEntity = m_deadEntities.back();
        m_deadEntities.pop_back();

        m_aliveEntities.push_back(nextEntity);
    }
    else
    {
        unsigned int newId = m_nextEntityId++;
        nextEntity = Entity(newId);
    }

    m_aliveEntities.push_back(nextEntity);
    return nextEntity;
}

void EntityManager::removeEntity(const Entity& entity)
{
    auto it = std::find(m_aliveEntities.begin(), m_aliveEntities.end(), entity);

    if (it != m_aliveEntities.end())
    {
        m_deadEntities.push_back(*it);
        m_aliveEntities.erase(it);
    }
}


