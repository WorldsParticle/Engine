#ifndef HEIGHTMAP_NAMESPACE_H
#define HEIGHTMAP_NAMESPACE_H

#include <vector>
#include <glm/glm.hpp>
#include "map/heightpoint.hpp"
//#include "generator.hpp"
#include "zonelookup.hpp"

namespace map {

///
/// \brief The HeightMap class, propelling floor to space like a rocketeer
/// Based on the design found between two neurons
///
class HeightMap
{
public:
    HeightMap(unsigned int width, unsigned int height);
    ~HeightMap();

    void    init(map::MapGraph & m);
    bool    pointInsideTrigon(glm::vec3 s, glm::vec3 a, glm::vec3 b, glm::vec3 c);

    void    generateMesh();

    std::vector<float> const &getPoints();
    std::vector<unsigned int> const &getIndices();
    std::vector<float> const &getNormals();

private:

    unsigned int _width;
    unsigned int _height;

    std::vector<HeightPoint>    _points;
    ZoneLookUp                  _zoneLookUp;

    std::vector<float> _vertices;
    std::vector<unsigned int>   _indices;
    std::vector<float> _normals;

};

}

#endif // HEIGHTMAP_NAMESPACE_H
