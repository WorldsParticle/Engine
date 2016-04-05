#ifndef RIVEROR_H
#define RIVEROR_H

#include "generator.hpp"
#include "map/map.hpp"

namespace RIV {

///
/// \brief The Riveror class, daughter of rain and mother of rivers and watersheds
/// Based on the design found in https://github.com/amitp/mapgen2
///
class Riveror : public gen::GenerationStep
{
public:
    Riveror();
    ~Riveror();

    virtual void run();

private:
    void                createRivers();
    void                calculateWatersheds();
    map::CrossedEdge    *lookupEdgeFromCorner(map::Corner *from, map::Corner *to);

};

}

#endif // RIVEROR_H
