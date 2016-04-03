#ifndef HEIGHTMAP_NAMESPACE_H
#define HEIGHTMAP_NAMESPACE_H

#include <vector>
#include <glm/glm.hpp>
#include "map/heightpoint.hpp"
//#include "generator.hpp"
#include "zonelookup.hpp"
#include "tools/bitmap_image.hpp"

namespace MAP_NAMESPACE {

///
/// \brief The HeightMap class, propelling floor to space like a rocketeer
/// Based on the design found between two neurons
///
class HeightMap
{
public:
    HeightMap(int width, int height);
    ~HeightMap();

    void    init(MAP_NAMESPACE::Map & m);
    void    paintByMoisture();
    void    paintByHeight();
    void    paintByLandType();
    void    paintByBiome();

    void    generateMesh();

    std::vector<float> const &getPoints();
    std::vector<unsigned int> const &getIndices();
    std::vector<float> const &getNormals();

private:

    int _width;
    int _height;

    std::vector<HeightPoint>    _points;
    ZoneLookUp                  _zoneLookUp;
    bitmap_image                image;

    std::vector<float> _vertices;
    std::vector<unsigned int>   _indices;
    std::vector<float> _normals;

};

}

#endif // HEIGHTMAP_NAMESPACE_H
