#include <iostream>

#include "core/Application.hpp"
#include "core/State.hpp"
#include "core/TileMap.hpp"

#include "state/GameState.hpp"

#include <random>

class TestState : public ow::State
{
private:
    sf::Clock m_testClock;
    float m_alpha;

    ow::TileMap tileMap;
    std::mt19937 random;
    std::uniform_int_distribution<uint32_t> dist;

protected:

    virtual void init()
    {
        ow::Application* application = getApplication();

        random.seed(static_cast<unsigned int>(m_testClock.getElapsedTime().asMilliseconds()));



        tileMap.create(application->getWidth() / 8,
                       application->getHeight() / 8);

        std::cout << application->getWidth() / 8 << '\n';

        for (unsigned int i = 0; i < tileMap.getWidth(); i++)
        {
            for (unsigned int j = 0; j < tileMap.getHeight(); j++)
            {
                unsigned int value = dist(random);
                tileMap.set(i, j, value);
            }
        }

        m_testClock.restart();
    }

    virtual void pause()
    {

    }

    virtual void resume()
    {

    }

    virtual void handleEvent(sf::Event& event)
    {
    }

    virtual void draw(sf::RenderWindow& window)
    {
        sf::RectangleShape rectangleShape(sf::Vector2f(8, 8));

        for (unsigned int i = 0; i < tileMap.getWidth(); i++)
        {
            for (unsigned int j = 0; j < tileMap.getHeight(); j++)
            {
                std::int8_t value = tileMap.get(i, j);


                if (value == 0)
                {
                    rectangleShape.setFillColor(sf::Color::Blue);
                }
                else
                {
                    rectangleShape.setFillColor(sf::Color::Red);
                }
                rectangleShape.setPosition(i * 8, j * 8);

                window.draw(rectangleShape);
            }
        }
    }

    virtual void update(float time, float dt)
    {
        m_alpha = m_testClock.getElapsedTime().asSeconds() / 2.0f;
    }

public:

    TestState() : dist(0, 1)
    {

    }
};

#include "game/Component.hpp"

class Lol : public ow::Component
{

};

int main(int argc, char* argv[])
{
    ow::Component component;
    Lol component2;

    std::cout << component.getType() << '\n';
    std::cout << component2.getType() << '\n';


    ow::Application application;
    return static_cast<int>(application.run(new ow::GameState()));
}

