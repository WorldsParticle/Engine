#include "Engine/Generation/Heightmap.hpp"

namespace Engine
{

    Heightmap::Heightmap(int width, int height, int tileWidth, int tileHeight) :
        _width(width),
        _height(height),
        _tileWidth(tileWidth),
        _tileHeight(tileHeight)
    {
        for (int i = 0; i < height; ++i)
            for (int j = 0; j < width; ++j)
            {
                _tiles.push_back(HeightTile(tileWidth, tileHeight, i * tileWidth, j * tileHeight));
            }
    }

    Heightmap::~Heightmap()
    {
    }

    float   Heightmap::get(int x, int y) const
    {
        if (x > 0 && y > 0 && x < (_width * _tileWidth) && y < (_height * _tileHeight))
            return (_tiles[x / _tileWidth + (y / _tileHeight) * _width].get(x % _tileWidth, y % _tileHeight));
        return (0.0);
    }

    void    Heightmap::set(int x, int y, float value)
    {
        if (x > 0 && y > 0 && x < (_width * _tileWidth) && y < (_height * _tileHeight))
            _tiles[x / _tileWidth + (y / _tileHeight) * _width].set(x % _tileWidth, y % _tileHeight, value);

    }
}
