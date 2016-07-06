#ifndef GENERATOR_MARIE_H
#define GENERATOR_MARIE_H

#include "steps/generationstep.hpp"
#include "data/zoneData.hpp"
#include <map>
#include <list>

namespace map
{
class MapGraph;
}

namespace gen
{

///
/// \brief This class run a bunch of step whose fill the mapgraph
/// for now it will juste launch one by one the generation steps which have been assigned (actually in a static way)
///
class ENGINE_EXPORTS Generator
{
public:
    Generator();

    ///
    /// \brief Executes the map generation steps.
    ///
    void run(map::MapGraph *map);


    inline const std::vector<GenerationStep *>  &steps()
    { return m_steps; }

    GenerationStep  *stepFromName(const std::string &namee);

    inline const std::vector<GenData::ZoneData>  &zoneDatas()
    { return m_zoneDatas; }

protected:
    std::vector<GenerationStep *> m_steps;
    
    std::vector<GenData::ZoneData>    m_zoneDatas;
};

}

#endif // GENERATOR_H
