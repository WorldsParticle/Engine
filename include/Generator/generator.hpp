#ifndef GENERATOR_MARIE_H
#define GENERATOR_MARIE_H

#include "generationstep.hpp"
#include <map>


#include "Generator/map/map.hpp"
#include "Generator/heightmap.hpp"
#include "Generator/voronoi/voronoi.hpp"
#include "Generator/shaper.hpp"
#include "Generator/elevator.hpp"
#include "Generator/riveror.hpp"
#include "Generator/moistor.hpp"
#include "Generator/biomizator.hpp"

namespace map
{
class MapGraph;
}

namespace gen
{

class Generator
{

protected:
    map::MapGraph        *_map;
    map::HeightMap  *_heightmap;
    GenerationStep  *_fillStep;
    GenerationStep  *_shapeStep;
    GenerationStep  *_elevateStep;
    GenerationStep  *_riverStep;
    GenerationStep  *_moistureStep;
    GenerationStep  *_biomeStep;
    
public:
    Generator();

    map::MapGraph    *generate(unsigned int xMax, unsigned int yMax, unsigned int zoneNumber);
    map::HeightMap *getHeightmap() {
    	return _heightmap;
    }

};

}

#endif // GENERATOR_H
