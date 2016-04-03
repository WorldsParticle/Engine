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


MAP::Biome        Biomizator::getBiome(std::shared_ptr<MAP::Zone> z)
{
    if (z->ocean)
        return MAP::OCEAN;
    else if (z->water)
    {
        if (z->elevation < 0.1f)
            return MAP::MARSH;
        if (z->elevation > 0.8f)
            return MAP::ICE;
        return MAP::LAKE;
    }
    else if (z->coast)
        return MAP::BEACH;
    else if (z->elevation > 0.8f)
    {
        if (z->moisture > 0.5f)
            return MAP::SNOW;
        else if (z->moisture > 0.33f)
            return MAP::TUNDRA;
        else if (z->moisture > 0.16f)
            return MAP::BARE;
        else
            return MAP::SCORCHED;
    }
    else if (z->elevation > 0.6f)
    {
        if (z->moisture > 0.66f)
                return MAP::TAIGA;
        else if (z->moisture > 0.33f)
                return MAP::SHRUBLAND;
        else
            return MAP::TEMPERATE_DESERT;
    }
    else if (z->elevation > 0.3f)
    {
        if (z->moisture > 0.83f)
            return MAP::TEMPERATE_RAIN_FOREST;
        else if (z->moisture > 0.50f)
            return MAP::TEMPERATE_DECIDUOUS_FOREST;
        else if (z->moisture > 0.16f)
            return MAP::GRASSLAND;
        else
            return MAP::TEMPERATE_DESERT;
    }
    else
    {
        if (z->moisture > 0.66f)
            return MAP::TROPICAL_RAIN_FOREST;
        else if (z->moisture > 0.33f)
            return MAP::TROPICAL_SEASONAL_FOREST;
        else if (z->moisture > 0.16f)
            return MAP::GRASSLAND;
        else
            return (MAP::SUBTROPICAL_DESERT);
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
