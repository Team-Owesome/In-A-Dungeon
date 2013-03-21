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
    struct BaseComponent
    {
    public:
        typedef unsigned int Family;

    public:
        static BaseComponent::Family NextFamilyId;
    };


    template<typename Derived>
    struct Component : public BaseComponent
    {
    public:
        typedef std::shared_ptr<Derived> sPtr;
        typedef std::weak_ptr<Derived> wPtr;

        static const BaseComponent::Family Family;

    public:

        Component()
        {
        }

        BaseComponent::Family getFamily()
        {
            return Family;
        }
    };

    template <class Derived> BaseComponent::Family const Component<Derived>::Family = NextFamilyId++;
}

#endif //COMPONENT_H
