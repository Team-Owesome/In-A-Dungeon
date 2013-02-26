//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//


#include "GameState.hpp"

#include <sstream>
#include <cmath>

#include "../core/Application.hpp"

using namespace ow;

GameState::GameState()
{
    m_round = 0;

    if (!m_font.loadFromFile("/Library/Fonts/Arial.ttf"))
    {
        getApplication()->exit("Could not load font.");
    }

    m_debugText.setFont(m_font);
}

void GameState::init()
{
    m_tileMap.create(100, 100);
}

void GameState::pause()
{

}

void GameState::resume()
{

}

void GameState::handleEvent(sf::Event& event)
{
    if (event.type == sf::Event::KeyPressed)
    {
        think();
        m_round++;
    }
    else if (event.type == sf::Event::MouseMoved)
    {
        m_selectedX = static_cast<unsigned int>(std::floorf((event.mouseMove.x - 8.0f) / 16.0f));
        m_selectedY = static_cast<unsigned int>(std::floorf((event.mouseMove.y - 8.0f) / 16.0f));
    }
}

void GameState::draw(sf::RenderWindow& window)
{
    std::stringstream stream;

    stream << m_round;

    m_debugText.setString(stream.str());
    window.draw(m_debugText);

    sf::RectangleShape shape(sf::Vector2f(16, 16));
    shape.setFillColor(sf::Color::Red);

    for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
    {
        Entity* entity = *it;

        window.draw(shape);
    }


    shape.setFillColor(sf::Color::Transparent);
    shape.setOutlineColor(sf::Color::Blue);
    shape.setOutlineThickness(3.0f);

    shape.setPosition(m_selectedX * 16, m_selectedY * 16);
    window.draw(shape);
}

void GameState::update(float time, float dt)
{

}

void GameState::think()
{
    for (auto it = m_entities.begin(); it != m_entities.end(); ++it)
    {
        Entity* entity = *it;
    }
}
