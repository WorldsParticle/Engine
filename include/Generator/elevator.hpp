#ifndef ELEVATOR_H
#define ELEVATOR_H

#include "generator.hpp"

namespace ELE {

///
/// \brief This class assign heights to the corners and zones of a Voronoi diagram
/// Based on the design found in https://github.com/amitp/mapgen2
///
class Elevator : public gen::GenerationStep
{
public:
    ///
    /// \brief Default constructor.
    ///
    Elevator();

    ///
    /// \brief Default destructor.
    ///
    ~Elevator();

    ///
    /// \brief Runs the generation step.
    ///
    virtual void run();

private:

    ///
    /// \brief Assign's a Voronoi diagram's corners their height
    ///
    void        assignCornerElevation();

    ///
    /// \brief Redistribute the elevation to a x^2 type curve, yielding more lower heights.
    ///
    void        redistributeElevation();

    ///
    /// \brief Assign's a Voronoi diagram's polyongs their elevation (corner's average).
    ///
    void        setPolygonElevation();

    ///
    /// \brief Find for each Voronoi diagram's corners its neighboring corner with the lowest elevation.
    ///
    void        calculateDownSlopes();

};

}

#endif // ELEVATOR_H
