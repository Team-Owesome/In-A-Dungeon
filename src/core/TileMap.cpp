#include "TileMap.hpp"

#include <cassert>

using namespace ow;

TileMap::TileMap()
{
    m_tileMap = nullptr;

    m_width = 0;
    m_height = 0;
}

TileMap::TileMap(unsigned int width,
                 unsigned int height)
{
    create(width, height);
}

TileMap::~TileMap()
{
    delete[] m_tileMap;
}

void TileMap::create(unsigned int width,
                     unsigned int height)
{
    if (m_tileMap)
    {
        delete[] m_tileMap;
    }

    // Big ol' chunk of memory
    m_tileMap = new std::int8_t[width * height]();

    std::cout << "SIZE -> " << width * height << ", " << width << ", " << height << '\n';

    m_width = width;
    m_height = height;
}

unsigned int TileMap::getWidth()
{
    return m_width;
}

unsigned int TileMap::getHeight()
{
    return m_height;
}

void TileMap::set(unsigned int x,
                  unsigned int y,
                  int8_t value)
{
    assert((x < m_width && y < m_height) && "Position is out of range");
    m_tileMap[x * m_height + y] = value;
}

std::int8_t TileMap::get(unsigned int x, unsigned int y)
{
    assert((x < m_width && y < m_height) && "Position is out of range");
    return m_tileMap[x * m_height + y];
}