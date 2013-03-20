//
// Created by till on 2/25/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef COMPONENT_H
#define COMPONENT_H

#include <iostream>
#include <unordered_map>
#include <string>

#include "Property.hpp"

namespace ow
{
    namespace private
    {
        static unsigned int NextComponentId = 0;
    }

    template<class Derived>
    struct Component
    {
    private:
        static bool Initialised;
        static unsigned int Id;

    public:

        Component()
        {
        }

        static unsigned int getId()
        {
            return Id;
        }
    };


    template <class Derived> bool Component<Derived>::Initialised = 0;
    template <class Derived> unsigned int Component<Derived>::Id = private::NextComponentId++;

}

#endif //COMPONENT_H
