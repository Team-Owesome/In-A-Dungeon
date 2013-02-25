//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef STATE_H
#define STATE_H

#include <iostream>

#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

namespace ow
{
    class Application;

    class State
    {
        friend class Application;

    private:
        Application* m_application;

        void setApplication(Application* application);
    protected:
        virtual void init() = 0;

        virtual void pause() = 0;
        virtual void resume() = 0;

        virtual void handleEvent(sf::Event& event) = 0;
        virtual void draw(sf::RenderWindow& window) = 0;
        virtual void update(float time, float dt) = 0;

    public:
        Application* getApplication() const;

        virtual ~State();
    };
}

#endif // STATE_H
