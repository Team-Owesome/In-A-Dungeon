//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef APPLICATION_H
#define APPLICATION_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>


namespace ow
{
    class State;

    enum class ExitCode
    {
        Success = 0,
        Failure = 1
    };

    class Application
    {
    private:
        sf::RenderWindow m_window;
        std::vector<State*> m_states;

        float m_time;
        float m_deltaTime;
        float m_accumulator;


    public:
        ////////////////////////////////////////////////////////////
        /// Run the machine
        ////////////////////////////////////////////////////////////
        ExitCode run(State* state);
        void exit(const char* errorMessage) const;

        void changeState(State* state);
        void pushState(State* state);
        void popState();

        State* getActiveState() const;

        unsigned int getWidth() const;
        unsigned int getHeight() const;

        const char* getResourcePath() const;
    };
}

#endif // APPLICATION_H
