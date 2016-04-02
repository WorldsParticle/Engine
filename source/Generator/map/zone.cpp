#include "Generator/map/zone.hpp"

namespace MAP
{

int Zone::indexMax = 0;
Zone::Zone(double x, double y) :
    index(indexMax),
    point(x, y),
    water(false),
    ocean(false),
    coast(false),
    border(false),
    biome(),
    elevation(0.0),
    moisture(0.0),
    neighbors(),
    borders(),
    corners()
{
    ++indexMax;
}

bool    Zone::haveNeighbor(std::shared_ptr<Zone> zone)
{
    for (const auto &z: neighbors)
        if (z == zone)
            return true;
    return false;
}

}
