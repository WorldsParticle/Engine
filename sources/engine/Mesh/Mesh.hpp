#ifndef     __MESH_HPP__
# define    __MESH_HPP__

#include    <vector>
#include    <glm/glm.hpp>

///
/// \brief The Mesh class
/// Il va falloir le modifier pour rajouter les indices etc... mais la j'ai la flemme de ouf.
///
class   Mesh
{
public:
    Mesh() {}
    ~Mesh() {}

public:
    const std::vector<glm::vec3>  &GetVertices(void) const
    {
        return this->_vertices;
    }

    const std::vector<glm::vec3>  &GetUVs(void) const
    {
        return this->_uvs;
    }

    const std::vector<glm::vec3>  &GetNormals(void) const
    {
        return this->_normals;
    }

public:
    void        SetVertices(const std::vector<glm::vec3> &vertices)
    {
        this->_vertices = vertices;
    }

    void        SetUVs(const std::vector<glm::vec3> &uvs)
    {
        this->_uvs = uvs;
    }

    void        SetNormals(const std::vector<glm::vec3> &normals)
    {
        this->_normals = normals;
    }

private:
    std::vector<glm::vec3>  _vertices;
    std::vector<glm::vec3>  _uvs;
    std::vector<glm::vec3>  _normals;
};

#endif /* !__MESH_HPP__ */
