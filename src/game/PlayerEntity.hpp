//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef PLAYER_ENTITY_H
#define PLAYER_ENTITY_H

#include <iostream>

#include "../core/Entity.hpp"

namespace ow
{
    class PlayerEntity : public Entity
    {
    public:
        virtual void think();
    };
}

#endif // PLAYER_ENTITY_H
