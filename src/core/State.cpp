//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "State.hpp"

#include "Application.hpp"

using namespace ow;

void State::setApplication(Application* application)
{
    m_application = application;
}

Application* State::getApplication() const
{
    return m_application;
}

State::~State()
{

}