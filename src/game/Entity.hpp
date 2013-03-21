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
    private:
        unsigned int m_id;

    protected:
        Entity(unsigned int id);

    public:

        typedef unsigned int Id;

        Entity();
        Entity::Id getId() const;

        bool operator ==(const Entity& other) const;
        bool operator !=(const Entity& other) const;

        operator Entity::Id();

    friend class EntityManager;
    };
}

#endif // ENTITY_H
