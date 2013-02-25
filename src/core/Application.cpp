//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "Application.hpp"

#include <cassert>
#include "State.hpp"

using namespace ow;

ExitCode Application::run(State* state)
{
    assert(state != nullptr && "State must not be null");

    m_window.create(sf::VideoMode(600, 400), "In A Dungeon");

    m_time = 0;
    m_deltaTime = 1.0f / 30.0f;
    m_accumulator = 0;

    sf::Clock frameClock;

    changeState(state);

    while (m_window.isOpen())
    {
        State* activeState = getActiveState();

        sf::Event event;
        while (m_window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
            {
                m_window.close();
            }

            activeState->handleEvent(event);
        }

        float frameTime = frameClock.restart().asSeconds();
        m_accumulator += frameTime;

        while (m_accumulator > m_deltaTime)
        {
            m_time += m_deltaTime;
            m_accumulator -= m_deltaTime;

            activeState->update(m_time, m_deltaTime);
        }

        m_window.clear(sf::Color::Black);
        activeState->draw(m_window);
        m_window.display();
    }

    return ExitCode::Success;
}

void Application::exit(const char* errorMessage) const
{
    std::cout << "Error: " << errorMessage << '\n';
    std::exit(static_cast<int>(ExitCode::Failure));
}

void Application::changeState(State* state)
{
    if (m_states.size() > 0)
    {
        State* oldState = m_states.back();
        m_states.pop_back();

        delete oldState;
    }

    state->setApplication(this);
    state->init();

    m_states.push_back(state);
}

void Application::pushState(State* state)
{
    if (m_states.size() > 0)
    {
        State* oldState = m_states.back();
        oldState->pause();
    }

    state->setApplication(this);
    state->init();

    m_states.push_back(state);
}

void Application::popState()
{
    assert(m_states.size() > 1 && "Only one state is on the stack");
    State* oldState = m_states.back();
    m_states.pop_back();

    delete oldState;
}

State* Application::getActiveState() const
{
    return m_states.back();
}

unsigned int Application::getWidth() const
{
    return m_window.getSize().x;
}

unsigned int Application::getHeight() const
{
    return m_window.getSize().y;
}

const char* Application::getResourcePath() const
{

    return "../../res";
}


