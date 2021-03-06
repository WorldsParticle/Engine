#ifndef BIOMIZATOR_H
#define BIOMIZATOR_H

#include "generationstep.hpp"
#include "../map/map.hpp"

#include    "Engine/Configuration.hpp"

namespace gen {

///
/// \brief This class assign biomes to the zones of a Voronoi diagram.
/// Based on the design found in https://github.com/amitp/mapgen2
///
class ENGINE_EXPORTS BiomizatorStep : public gen::GenerationStep
{
public:

    ///
    /// \brief Default constructor.
    ///
    BiomizatorStep();

    ///
    /// \brief Default destructor.
    ///
    ~BiomizatorStep();

    ///
    /// \brief Runs the generation step.
    ///
    virtual void run();

    ///
    /// \brief Returns the biome of a zone.
    /// \param Zone to be inspected.
    ///
    map::Biome      getBiome(map::Zone *z);

    ///
    /// \brief Assigns the diagram's zones' biomes.
    ///
    void            assignBiomes();

private:

};

}

#endif // BIOMIZATOR_H
