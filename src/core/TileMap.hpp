#ifndef TILE_MAP_H
#define TILE_MAP_H

#include <iostream>
#include <cstdint>
#include <map>

#include "Entity.hpp"

namespace ow
{
    class TileMap
    {
    private:
        std::int8_t* m_tileMap;
        std::map<int, std::map<int, Entity*>> m_objectMap;

        unsigned int m_width;
        unsigned int m_height;

    public:
        TileMap();

        TileMap(unsigned int width,
                unsigned int height);

        ~TileMap();

        void create(unsigned int width,
                    unsigned int height);

        unsigned int getWidth();
        unsigned int getHeight();

        std::int8_t get(unsigned int x,
                        unsigned int y);

        void set(unsigned int x,
                 unsigned int y,
                 std::int8_t value);
    };
}

#endif // TILE_MAP_H
