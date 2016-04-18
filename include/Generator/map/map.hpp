#ifndef MAP_H
#define MAP_H

#include <map>
#include "point.hpp"
#include "zone.hpp"
#include "corner.hpp"
#include "crossededge.hpp"

namespace map
{


///
/// \brief This class stores the backbone of a Voronoi diagram.
///
class MapGraph
{
public:
    MapGraph(unsigned int xMaxx = 0, unsigned int yMaxx = 0, unsigned int zoneNumberr = 0);

    ///
    /// \brief Copy constructor.
    ///
    ~MapGraph();

    ///
    /// \brief Find the associated polygon to a 2D (x, y) point
    /// \param point for which we need to find nearest neighbor
    ///
    Zone    *findZone(const Point *p); // ugly and slow

    ///
    /// \brief Map's zones getter.
    ///
    inline std::map<int, Zone *>        &zones()
    { return _zones; }

    ///
    /// \brief Map's corners getter.
    ///
    inline std::map<int, Corner *>      &corners()
    { return _corners; }

    ///
    /// \brief Map's edges getter.
    ///
    inline std::map<int, CrossedEdge *> &edges()
    { return _edges; }

    ///
    /// \brief Width getter.
    ///
    inline double xMax()
    { return _xMax; }

    ///
    /// \brief Height getter.
    ///
    inline double yMax()
    { return _yMax; }

    ///
    /// \brief Zone count getter.
    ///
    inline unsigned int zoneNumber()
    { return _zoneNumber; }

private:

    ///
    /// \brief Map's zones (= Voronoi polygons).
    ///
    std::map<int, Zone *>         _zones;

    ///
    /// \brief Map's zone's corners (= vertices of the Voronoi polygons).
    ///
    std::map<int, Corner *>       _corners;

    ///
    /// \brief Edges of the map (= edges of the Voronoi polygons)
    ///
    std::map<int, CrossedEdge *>  _edges;

    ///
    /// \brief Width of the map
    ///
    double    _xMax;

    ///
    /// \brief Height of the map
    ///
    double    _yMax;

    ///
    /// \brief Total count of zones in the diagram
    ///
    unsigned int    _zoneNumber;
};

}

#endif // MAP_H
