//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "Entity.hpp"

using namespace ow;

void Entity::setX(unsigned int x)
{
    m_x = x;
}

void Entity::setY(unsigned int y)
{
    m_y = y;
}

unsigned int Entity::getX()
{
    return m_x;
}


unsigned int Entity::getY()
{
    return m_y;
}