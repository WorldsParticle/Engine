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

namespace MAP_NAMESPACE
{
class Map;
}

namespace GEN
{

class Generator
{

protected:
    MAP_NAMESPACE::Map        *_map;
    MAP_NAMESPACE::HeightMap  *_heightmap;
    GenerationStep  *_fillStep;
    GenerationStep  *_shapeStep;
    GenerationStep  *_elevateStep;
    GenerationStep  *_riverStep;
    GenerationStep  *_moistureStep;
    GenerationStep  *_biomeStep;
    
public:
    Generator();

    MAP_NAMESPACE::Map    *generate(double xMax, double yMax, unsigned int zoneNumber);
    MAP_NAMESPACE::HeightMap *getHeightmap() {
    	return _heightmap;
    }

};

}

#endif // GENERATOR_H
