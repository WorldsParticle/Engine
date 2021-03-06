#ifndef MAP_H
#define MAP_H

#include <map>
#include "point.hpp"
#include "zone.hpp"
#include "corner.hpp"
#include "crossededge.hpp"
#include "heightmap.hpp"

#include "Engine/Configuration.hpp"

namespace map
{


///
/// \brief This class stores every information about the map
///
class ENGINE_EXPORTS MapGraph
{
public:
    MapGraph(unsigned int xMaxx = 0, unsigned int yMaxx = 0);

    ///
    /// \brief Copy constructor.
    ///
    ~MapGraph();

    ///
    /// \brief Find the polygon to a 2D (x, y) point (only work if center of the polygon, see zonelookup for better result)
    /// \param point for which we need to find nearest neighbor
    ///
    Zone    *findZone(const Point *p); // ugly and slow

    ///
    /// \brief Map's zones getter.
    ///
    inline std::map<int, Zone *>        &zones()
    { return m_zones; }

    ///
    /// \brief Map's corners getter.
    ///
    inline std::map<int, Corner *>      &corners()
    { return m_corners; }

    ///
    /// \brief Map's edges getter.
    ///
    inline std::map<int, CrossedEdge *> &edges()
    { return m_edges; }

    ///
    /// \brief Width getter.
    ///
    inline double xMax()
    { return m_xMax; }

    ///
    /// \brief Height getter.
    ///
    inline double yMax()
    { return m_yMax; }

    inline HeightMap   &heightMap()
    { return m_heightMap; }

private:

    ///
    /// \brief Map's zones (= Voronoi polygons).
    ///
    std::map<int, Zone *>         m_zones;

    ///
    /// \brief Map's zone's corners (= vertices of the Voronoi polygons).
    ///
    std::map<int, Corner *>       m_corners;

    ///
    /// \brief Edges of the map (= edges of the Voronoi polygons)
    ///
    std::map<int, CrossedEdge *>  m_edges;

    ///
    /// \brief Width of the map
    ///
    double    m_xMax;

    ///
    /// \brief Height of the map
    ///
    double    m_yMax;

    HeightMap m_heightMap;
};

}

#endif // MAP_H
