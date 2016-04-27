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

///
/// \brief This class generates and fills a Voronoi diagram, while also generating the associated heightmap.
///
class Generator
{
public:

    ///
    /// \brief Default constructor.
    ///
    Generator();

    ///
    /// \brief Executes the map generation steps.
    /// \param Max x coordinate for Voronoi diagram.
    /// \param Max y coordinate for Voronoi diagram.
    /// \param Number of zones (= polygons) for the Voronoi diagram.
    ///
    map::MapGraph    *generate(unsigned int xMax, unsigned int yMax, unsigned int zoneNumber);

    ///
    /// \brief Heightmap getter.
    ///
    map::HeightMap *getHeightmap() {
        return _heightmap;
    }


protected:
    ///
    /// \brief Map being generated.
    ///
    map::MapGraph        *_map;

    ///
    /// \brief heightmap associated to the map
    ///
    map::HeightMap  *_heightmap;

    ///
    /// \brief Voronoi diagram generation step.
    ///
    GenerationStep  *_fillStep;

    ///
    /// \brief Land & ocean assignation step.
    ///
    GenerationStep  *_shapeStep;

    ///
    /// \brief Height assignation step.
    ///
    GenerationStep  *_elevateStep;

    ///
    /// \brief River generating step.
    ///
    GenerationStep  *_riverStep;

    ///
    /// \brief Moisture assignation step.
    ///
    GenerationStep  *_moistureStep;

    ///
    /// \brief Biome assignation step.
    ///
    GenerationStep  *_biomeStep;

};

}

#endif // GENERATOR_H
