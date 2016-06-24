#ifndef HEIGHTMAPINGSTEP_HPP
#define HEIGHTMAPINGSTEP_HPP

#include "generationstep.hpp"
#include "Generator/map/zonelookup.hpp"

namespace gen
{

///
/// \brief The HeightMapingStep class
/// it will fill the heightmap points height
///
class HeightMapingStep : public GenerationStep
{
public:
    HeightMapingStep();
    virtual ~HeightMapingStep();

    virtual void    run() override;

private:
    ///
    /// \brief Class holding the zone's center kd-tree.
    /// should move it inside MapGraph, and createCould at the end of zoningStep
    ///
    map::ZoneLookUp m_zoneLookUp;
};

}

#endif  /* HEIGHTMAPINGSTEP_HPP */
