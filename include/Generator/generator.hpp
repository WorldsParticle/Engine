#ifndef GENERATOR_MARIE_H
#define GENERATOR_MARIE_H

#include "steps/generationstep.hpp"
#include <map>
#include <list>


#include "map/map.hpp"
#include "heightmap.hpp"
#include "steps/generationstep.hpp"

namespace map
{
class MapGraph;
}

namespace gen
{

///
/// \brief This class fill the mapgraph and the heightmap (who should be insinde the mapgraph)
/// for now it will juste launch one by one the generation steps which have been assigned (actually in a static way)
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
    ///
    void run(map::MapGraph *map);

    ///
    /// \brief Heightmap getter.
    ///
    inline map::HeightMap   *heightmap() {
        return m_heightmap;
    }

protected:
    ///
    /// \brief heightmap associated to the map
    ///
    map::HeightMap              *m_heightmap;

    ///
    /// \brief steps which are run (in order)
    ///
    std::list<GenerationStep *> m_steps;
};

}

#endif // GENERATOR_H
