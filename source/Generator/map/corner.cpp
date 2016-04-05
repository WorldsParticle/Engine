#include "Generator/map/corner.hpp"

namespace map
{

int Corner::indexMax = 0;
Corner::Corner() :
    index(indexMax),
    point(0, 0),
    ocean(false),
    water(false),
    coast(false),
    border(false),
    elevation(0.0),
    moisture(0.0),
    faces(),
    edges(),
    adjacent(),
    river(0),
    watershedSize(0),
    downslope(),
    watershed()
{
    ++indexMax;
}

}
