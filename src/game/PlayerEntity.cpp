//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "PlayerEntity.hpp"

using namespace ow;

void PlayerEntity::think()
{
    setX(getX() + 1);
}