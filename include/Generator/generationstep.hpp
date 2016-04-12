#ifndef GENERATIONSTEP_H
#define GENERATIONSTEP_H

#include "map/map.hpp"

namespace gen
{

class GenerationStep
{
public:
    enum STEP
    {
        FILL = 0,
        SHAPE,
        ELEVATE,
        MOISTING,
        RIVERING,
        BIOMIZATING
    };

    GenerationStep() : _map(nullptr), _step() {}

    inline void    generate(map::MapGraph *map)
    { _map = std::shared_ptr<map::MapGraph>(map); run(); }

    virtual ~GenerationStep() {}

protected:
    virtual void    run() = 0;
    std::shared_ptr<map::MapGraph>        _map;
    STEP            _step;
};

}

#endif // GENERATIONSTEP_H
