#ifndef RIVEROR_H
#define RIVEROR_H

#include "generator.hpp"
#include "map/map.hpp"

namespace RIV {

///
/// \brief This class generates rivers and determine watersheds on a Voronoi diagram.
/// Based on the design found in https://github.com/amitp/mapgen2
///
class Riveror : public gen::GenerationStep
{
public:
    ///
    /// \brief Default constructor.
    ///
    Riveror();

    ///
    /// \brief Default destructor.
    ///
    ~Riveror();


    ///
    /// \brief Runs the generation step.
    ///
    virtual void run();

private:
    ///
    /// \brief Generates rivers.
    ///
    void                createRivers();

    ///
    /// \brief Calculate the watersheds.
    ///
    void                calculateWatersheds();

    ///
    /// \brief Find edge associated to two corners.
    /// \param From corner.
    /// \param To corner.
    ///
    map::CrossedEdge    *lookupEdgeFromCorner(map::Corner *from, map::Corner *to);

};

}

#endif // RIVEROR_H
