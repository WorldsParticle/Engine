#ifndef GENERATIONSTEP_H
#define GENERATIONSTEP_H

#include "map/map.hpp"

namespace gen
{

///
/// \brief This abstract class describes the backbone of a map's generation step.
///
class GenerationStep
{
public:

    ///
    /// \brief Enumeration of the different generation steps.
    ///
    enum STEP
    {
        FILL = 0,
        SHAPE,
        ELEVATE,
        MOISTING,
        RIVERING,
        BIOMIZATING
    };

    ///
    /// \brief Default constructor.
    ///
    GenerationStep() : _map(nullptr), _step() {}

    inline void    generate(map::MapGraph *map)
    { _map = std::shared_ptr<map::MapGraph>(map); run(); }

    virtual ~GenerationStep() {}

protected:

    ///
    /// \brief Should run the generation step in the concrete class.
    ///
    virtual void    run() = 0;

    ///
    /// \brief Pointer to the map which is used in the generation step.
    ///
    std::shared_ptr<map::MapGraph>        _map;

    ///
    /// \brief Returns the current generation step.
    ///
    STEP            _step;
};

}

#endif // GENERATIONSTEP_H
