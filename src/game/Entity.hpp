//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>

namespace ow
{
    class EntityManager;

    class Entity
    {
    public:
        typedef unsigned int Id;

        Entity::Id getId() const;

        bool operator ==(const Entity& other) const;
        bool operator !=(const Entity& other) const;

        operator Entity::Id() const;

    protected:
        Entity(EntityManager* manager, Entity::Id id);

    private:
        EntityManager* m_entityManager;
        unsigned int m_id;

    friend class EntityManager;
    };
}

#endif // ENTITY_H
