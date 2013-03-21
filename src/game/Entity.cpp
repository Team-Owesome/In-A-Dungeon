//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "Entity.hpp"

using namespace ow;

Entity::Entity()
{
}

Entity::Entity(unsigned int id)
{
    m_id = id;
}

bool Entity::operator ==(const Entity& other) const
{
    return m_id == other.getId();
}

bool Entity::operator !=(const Entity& other) const
{
    return m_id != other.getId();
}

Entity::operator Entity::Id()
{
    return getId();
}

Entity::Id Entity::getId() const
{
    return m_id;
}