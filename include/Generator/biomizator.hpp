#ifndef BIOMIZATOR_H
#define BIOMIZATOR_H

#include "generator.hpp"
#include "map/map.hpp"

namespace BIO {

///
/// \brief This class assign biomes to the zones of a Voronoi diagram.
/// Based on the design found in https://github.com/amitp/mapgen2
///
class Biomizator : public gen::GenerationStep
{
public:

    ///
    /// \brief Default constructor.
    ///
    Biomizator();

    ///
    /// \brief Default destructor.
    ///
    ~Biomizator();

    ///
    /// \brief Runs the generation step.
    ///
    virtual void run();

    ///
    /// \brief Returns the biome of a zone.
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
