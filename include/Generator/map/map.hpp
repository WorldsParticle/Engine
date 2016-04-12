#ifndef MAP_H
#define MAP_H

#include <map>
#include "point.hpp"
#include "zone.hpp"
#include "corner.hpp"
#include "crossededge.hpp"

namespace map
{

class MapGraph
{
public:
    MapGraph(unsigned int xMaxx = 0, unsigned int yMaxx = 0, unsigned int zoneNumberr = 0);
    ~MapGraph();

    Zone    *findZone(const Point *p); // ugly and slow

    inline std::map<int, Zone *>        &zones()
    { return _zones; }
    inline std::map<int, Corner *>      &corners()
    { return _corners; }
    inline std::map<int, CrossedEdge *> &edges()
    { return _edges; }

    inline double xMax()
    { return _xMax; }
    inline double yMax()
    { return _yMax; }
    inline unsigned int zoneNumber()
    { return _zoneNumber; }

private:

    std::map<int, Zone *>         _zones;
    std::map<int, Corner *>       _corners;
    std::map<int, CrossedEdge *>  _edges;

    double    _xMax;
    double    _yMax;
    unsigned int    _zoneNumber;
};

}

#endif // MAP_H
