//
// Created by till on 2/21/13.
//
// To change the template use AppCode | Preferences | File Templates.
//



#ifndef GAME_STATE_H
#define GAME_STATE_H

#include <iostream>
#include "../core/State.hpp"
#include "../core/Entity.hpp"
#include "../core/TileMap.hpp"
#include "../game/TurnManager.hpp"
#include "../game/PlayerEntity.hpp"

namespace ow
{
    class GameState : public State
    {
    private:
        unsigned int m_round;

        TurnManager m_turnManager;
        TileMap m_tileMap;

        PlayerEntity m_playerEntity;

        std::vector<Entity*> m_entities;

        sf::Font m_font;
        sf::Text m_debugText;

        unsigned int m_selectedX;
        unsigned int m_selectedY;

    protected:
        virtual void init();
        virtual void pause();
        virtual void resume();
        virtual void handleEvent(sf::Event& event);
        virtual void draw(sf::RenderWindow& window);
        virtual void update(float time, float dt);

        void think();

    public:
        GameState();
    };
}

#endif // GAME_STATE_H