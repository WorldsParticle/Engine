#ifndef MOISTOR_H
#define MOISTOR_H

#include "generator.hpp"

namespace MOI {

///
/// \brief This class assigns moisture to the corners and zones of a Voronoi diagram.
/// Based on the design found in https://github.com/amitp/mapgen2
///
class Moistor : public gen::GenerationStep
{
public:
    ///
    /// \brief Default constructor.
    ///
    Moistor();

    ///
    /// \brief Default destructor.
    ///
    ~Moistor();

    ///
    /// \brief Runs the generation step.
    ///
    virtual void run();

    ///
    /// \brief Assign moisture to Voronoi polygon's corners.
    ///
    void    assignCornerMoisture();

    ///
    /// \brief Redistributes moisture following a linear curve.
    ///
    void    redistributeMoisture();

    ///
    /// \brief Assign Voronoi polygon's moisture (= avg. of its corners).
    ///
    void    assignPolygonMoisture();

private:

};

}

#endif // MOISTOR_H
