//
// Created by till on 2/25/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "World.hpp"

using namespace ow;

Entity World::createEntity()
{
    return m_entityManager.create();
}

void World::removeEntity(const Entity& entity)
{
    m_entityManager.removeEntity(entity);
}