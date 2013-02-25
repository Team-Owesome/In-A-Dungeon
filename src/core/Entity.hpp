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
    class Entity
    {
    private:
        unsigned int m_x;
        unsigned int m_y;

    public:

        unsigned int getX();
        unsigned int getY();

        void setX(unsigned int x);
        void setY(unsigned int y);



        virtual void think() = 0;
    };
}

#endif // ENTITY_H
