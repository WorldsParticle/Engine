#ifndef HEIGHTMAP_NAMESPACE_H
#define HEIGHTMAP_NAMESPACE_H

#include <vector>
#include <glm/glm.hpp>
#include "map/heightpoint.hpp"
//#include "generator.hpp"
#include "zonelookup.hpp"

namespace map {

///
/// \brief This class stores the height of the (x, y) points of a 2D map
/// and also generates the buffers describing the map's mesh
///
class HeightMap
{
public:
    ///
    /// \brief Default constructor.
    /// \param Width of the heightmap.
    /// \param Height of the heightmap.
    ///
    HeightMap(unsigned int width, unsigned int height);

    ///
    /// \brief Default destructor.
    ///
    ~HeightMap();

    ///
    /// \brief Initialize the heightmap from a Voronoi diagram.
    /// \param Map from which to build the heightmap.
    ///
    void    init(map::MapGraph & m);

    ///
    /// \brief Veryfies that a point s is inside the abc triangle.
    /// \param Point to be checked.
    /// \param Vertice a.
    /// \param Vertice b.
    /// \param Vertice c.
    ///
    bool    pointInsideTrigon(glm::vec3 s, glm::vec3 a, glm::vec3 b, glm::vec3 c);

    ///
    /// \brief Generates the mesh associated to the heightmap.
    ///
    void    generateMesh();

    ///
    /// \brief Vertice buffer getter.
    ///
    std::vector<float> const &getPoints();

    ///
    /// \brief Indices buffer getter.
    ///
    std::vector<unsigned int> const &getIndices();

    ///
    /// \brief Normals buffer getter.
    ///
    std::vector<float> const &getNormals();

private:

    ///
    /// \brief Width of the heightmap.
    ///
    unsigned int _width;

    ///
    /// \brief Height of the heightmap.
    ///
    unsigned int _height;

    ///
    /// \brief Every point of the heightmap.
    ///
    std::vector<HeightPoint>    _points;

    ///
    /// \brief Class holding the zone's center kd-tree.
    ///
    ZoneLookUp                  _zoneLookUp;

    ///
    /// \brief Heightmap's vertices buffer.
    ///
    std::vector<float> _vertices;

    ///
    /// \brief Heightmap's indices buffer.
    ///
    std::vector<unsigned int>   _indices;

    ///
    /// \brief Heightmap's normals buffer.
    ///
    std::vector<float> _normals;

};

}

#endif // HEIGHTMAP_NAMESPACE_H
