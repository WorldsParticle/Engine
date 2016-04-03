#include "Generator/biomizator.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <algorithm>

namespace BIO
{

Biomizator::Biomizator()
{
    _step = BIOMIZATING;
}

Biomizator::~Biomizator()
{
}

void    Biomizator::run()
{
    assignBiomes();
}


MAP_NAMESPACE::Biome        Biomizator::getBiome(std::shared_ptr<MAP_NAMESPACE::Zone> z)
{
    if (z->ocean)
        return MAP_NAMESPACE::OCEAN;
    else if (z->water)
    {
        if (z->elevation < 0.1f)
            return MAP_NAMESPACE::MARSH;
        if (z->elevation > 0.8f)
            return MAP_NAMESPACE::ICE;
        return MAP_NAMESPACE::LAKE;
    }
    else if (z->coast)
        return MAP_NAMESPACE::BEACH;
    else if (z->elevation > 0.8f)
    {
        if (z->moisture > 0.5f)
            return MAP_NAMESPACE::SNOW;
        else if (z->moisture > 0.33f)
            return MAP_NAMESPACE::TUNDRA;
        else if (z->moisture > 0.16f)
            return MAP_NAMESPACE::BARE;
        else
            return MAP_NAMESPACE::SCORCHED;
    }
    else if (z->elevation > 0.6f)
    {
        if (z->moisture > 0.66f)
                return MAP_NAMESPACE::TAIGA;
        else if (z->moisture > 0.33f)
                return MAP_NAMESPACE::SHRUBLAND;
        else
            return MAP_NAMESPACE::TEMPERATE_DESERT;
    }
    else if (z->elevation > 0.3f)
    {
        if (z->moisture > 0.83f)
            return MAP_NAMESPACE::TEMPERATE_RAIN_FOREST;
        else if (z->moisture > 0.50f)
            return MAP_NAMESPACE::TEMPERATE_DECIDUOUS_FOREST;
        else if (z->moisture > 0.16f)
            return MAP_NAMESPACE::GRASSLAND;
        else
            return MAP_NAMESPACE::TEMPERATE_DESERT;
    }
    else
    {
        if (z->moisture > 0.66f)
            return MAP_NAMESPACE::TROPICAL_RAIN_FOREST;
        else if (z->moisture > 0.33f)
            return MAP_NAMESPACE::TROPICAL_SEASONAL_FOREST;
        else if (z->moisture > 0.16f)
            return MAP_NAMESPACE::GRASSLAND;
        else
            return (MAP_NAMESPACE::SUBTROPICAL_DESERT);
    }
}

void        Biomizator::assignBiomes()
{
    for (auto & z : _map->zones())
    {
        z.second->biome = getBiome(z.second);
    }
}

}
