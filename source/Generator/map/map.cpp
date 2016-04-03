#include "Generator/map/map.hpp"

namespace MAP_NAMESPACE
{

Map::Map(unsigned int xMx, unsigned int yMx, unsigned int zNumber) :
    _zones(),
    _corners(),
    _edges(),
    _xMax(xMx),
    _yMax(yMx),
    _zoneNumber(zNumber)
{

}

Map::~Map()
{
    _zones.clear();
    _corners.clear();
    _edges.clear();
}

}
