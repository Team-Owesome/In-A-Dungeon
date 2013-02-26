//
// Created by till on 2/25/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef COMPONENT_MANAGER_H
#define COMPONENT_MANAGER_H

#include <iostream>
#include <unordered_map>
#include <string>

#include "../Entity.hpp"
#include "../Component.hpp"

namespace ow
{
    class ComponentManager
    {
        std::unordered_map<Entity*, std::unordered_map<std::string, Component*>> m_components;

    private:
        void addComponent(Entity& entity);
        void getComponent(Entity& entity);
    };
}


#endif // COMPONENT_MANAGER_H
