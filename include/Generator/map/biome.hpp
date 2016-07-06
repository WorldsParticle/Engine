/* 
 * File:   biome.hpp
 * Author: marie
 *
 * Created on 6 juillet 2016, 22:22
 */

#ifndef BIOME_HPP
#define BIOME_HPP

#include <map>

namespace map
{

///
/// \brief Enumeration of all the possible zone biomes.
///
enum Biome {
    OCEAN,
//    MARSH,
//    ICE,
    LAKE,
    BEACH,
    SNOW,
//    TUNDRA,
//    BARE,
//    SCORCHED,
//    TAIGA,
//    SHRUBLAND,
    TEMPERATE_DESERT,
    TEMPERATE_RAIN_FOREST,
//    TEMPERATE_DECIDUOUS_FOREST,
    GRASSLAND,
//    TROPICAL_SEASONAL_FOREST,
//    TROPICAL_RAIN_FOREST,
//    SUBTROPICAL_DESERT

    BIOME_COUNT //BIOME_COUNT is not a biome, it is used in for loop on the enum
};

struct BiomeName
{
    static std::string const&  getBiomeName(Biome const& b) {
        static std::map<Biome, std::string> biomeNames;

        if (biomeNames.empty())//TODO function to initialize the map
        {
            biomeNames.emplace(OCEAN, "Ocean");
            biomeNames.emplace(LAKE, "Lake");
            biomeNames.emplace(BEACH, "Beach");
            biomeNames.emplace(SNOW, "Snow");
            biomeNames.emplace(TEMPERATE_DESERT, "Temperate Desert");
            biomeNames.emplace(TEMPERATE_RAIN_FOREST, "Temperate Rain Desert");
            biomeNames.emplace(GRASSLAND, "Grassland");
            biomeNames.emplace(BIOME_COUNT, "ERROR BIOME NAME");
        }
        return biomeNames.at(b);
    }
};

}

#endif /* BIOME_HPP */

