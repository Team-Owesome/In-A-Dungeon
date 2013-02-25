//
// Created by till on 2/25/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>
#include <map>

#include "Entity.hpp"

#include "manager/EntityManager.hpp"
#include "manager/ComponentManager.hpp"

namespace ow
{
    class World
    {
    private:
        EntityManager m_entityManager;
        ComponentManager m_componentManager;


    public:

        Entity createEntity();

    };
}

#endif //WORLD_H
