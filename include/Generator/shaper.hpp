#ifndef SHAPER_H
#define SHAPER_H

#include "generator.hpp"

namespace SHA {

///
/// \brief This class determines the land types of the corners and zones of a Voronoi diagram.
/// Based on the design found in https://github.com/amitp/mapgen2
///
class Shaper : public gen::GenerationStep
{
public:
    ///
    /// \brief Default constructor.
    ///
    Shaper();

    ///
    /// \brief Default destructor.
    ///
    ~Shaper();

    ///
    /// \brief Runs the generation step.
    ///
    virtual void run();

private:

    ///
    /// \brief Assign land corners and ocean corners.
    ///
    void        assignCornerLandPerlin(int seed);

    ///
    /// \brief Assign land and ocean zones according to corners' value.
    ///
    void        assignOceanCostAndLand();
};

}

#endif // SHAPER_H
