//
// Created by till on 2/25/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef WORLD_H
#define WORLD_H

#include <iostream>
#include <vector>

#include "../core/Entity.hpp"

class World
{
    std::vector<Entity*> m_entities;
};

#endif //WORLD_H
