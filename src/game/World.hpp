//
// Created by till on 2/25/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <unordered_map>

#include "Entity.hpp"

#include "EntityManager.hpp"

namespace ow
{
    class World
    {
    private:
        EntityManager m_entityManager;


    public:

        Entity createEntity();
        void removeEntity(const Entity& entity);

    };
}

#endif //WORLD_H
