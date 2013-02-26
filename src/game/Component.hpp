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
    class Component
    {
    private:
    public:
        virtual const char* getType();

        Property<float>::ptr test;
    };
}

#endif //COMPONENT_H
