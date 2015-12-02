#include    "Mesh.hpp"


namespace   WorldParticles
{
    namespace   Engine
    {

        Mesh::Mesh(const std::vector<glm::vec3> &vertices,
                const std::vector<glm::vec3> &uvs,
                const std::vector<glm::vec3> &normals) :
            _vertices(vertices),
            _uvs(uvs),
            _normals(normals)
        {

        }

        Mesh::~Mesh(void)
        {

        }

    }
}

