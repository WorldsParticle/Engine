#include "Engine/Generation/HeightTile.hpp"

namespace Engine
{

    HeightTile::HeightTile(int width, int height, int globalX, int globalY) :
        _width(width),
        _height(height),
        _x(globalX),
        _y(globalY),
        _tile(width * height, 0.0)
    {
    }

    HeightTile::~HeightTile()
    {
    }

    float   HeightTile::get(int x, int y) const
    {
        if (x > 0 && y > 0 && x < _width && y < _height)
            return _tile[x + y * _width];
        return (0.0);
    }

    void    HeightTile::set(int x, int y, float value)
    {
        if (x > 0 && y > 0 && x < _width && y < _height)
            _tile[x + y * _width] = value;
    }
}
