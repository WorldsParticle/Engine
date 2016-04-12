#include "Generator/map/map.hpp"

namespace map
{

MapGraph::MapGraph(unsigned int xMaxx, unsigned int yMaxx, unsigned int zoneNumberr) :
    _zones(),
    _corners(),
    _edges(),
    _xMax(xMaxx),
    _yMax(yMaxx),
    _zoneNumber(zoneNumberr)
{

}

MapGraph::~MapGraph()
{
    for(std::map<int, Zone *>::iterator it = _zones.begin(); it != _zones.end(); ++it)
        delete (*it).second;
    for(std::map<int, Corner *>::iterator it = _corners.begin(); it != _corners.end(); ++it)
        delete (*it).second;
    for(std::map<int, CrossedEdge *>::iterator it = _edges.begin(); it != _edges.end(); ++it)
        delete (*it).second;

    _zones.clear();
    _corners.clear();
    _edges.clear();
}

Zone   *MapGraph::findZone(const Point *p)
{
    if (!p)
        return NULL;

    for(std::map<int, Zone *>::iterator it = _zones.begin(); it != _zones.end(); ++it)
        if ((*it).second->point == *p)
            return (*it).second;

    return NULL;
}

}
