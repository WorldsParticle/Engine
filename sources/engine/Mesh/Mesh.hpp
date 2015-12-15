#ifndef     __MESH_HPP__
# define    __MESH_HPP__

#include    <vector>
#include    <glm/glm.hpp>

namespace WorldParticles
{
    namespace Engine
    {
        ///
        /// \brief The Mesh class
        /// Il va falloir le modifier pour rajouter les indices etc... mais la j'ai la flemme de ouf.
        ///
        class   Mesh
        {
            public:
                ///
                /// \brief Default constructor
                ///
                Mesh(const std::vector<glm::vec3> &vertices = std::vector<glm::vec3>(),
                        const std::vector<glm::vec3> &uvs = std::vector<glm::vec3>(),
                        const std::vector<glm::vec3> &normals = std::vector<glm::vec3>());

                ///
                /// \brief Destructor
                ///
                ~Mesh(void);

            public:

                void    initialise(void);

                void    bind(void) const;

                void    unbind(void) const;

            public:
                ///
                /// \brief Getter for the vertices attribute.
                ///
                const std::vector<glm::vec3>  &GetVertices(void) const
                {
                    return this->_vertices;
                }

                ///
                /// \brief Getter for the UVs attribute.
                ///
                const std::vector<glm::vec3>  &GetUVs(void) const
                {
                    return this->_uvs;
                }

                ///
                /// \brief Getter for the normals attribute.
                ///
                const std::vector<glm::vec3>  &GetNormals(void) const
                {
                    return this->_normals;
                }

            public:
                ///
                /// \brief Setter for the vertices attribute.
                ///
                void        SetVertices(const std::vector<glm::vec3> &vertices)
                {
                    this->_vertices = vertices;
                }

                ///
                /// \brief Setter for the UVs attribute.
                ///
                void        SetUVs(const std::vector<glm::vec3> &uvs)
                {
                    this->_uvs = uvs;
                }

                ///
                /// \brief Setter for the normal attribute.
                ///
                void        SetNormals(const std::vector<glm::vec3> &normals)
                {
                    this->_normals = normals;
                }

            private:
                ///
                /// \brief The vertices attribute is used to store all vertex of the mesh.
                ///
                std::vector<glm::vec3>  _vertices;

                ///
                /// \brief THe uvs attribute is used to store all uvs of the mesh.
                ///
                std::vector<glm::vec3>  _uvs;

                ///
                /// \brief The normals attribute is used to store all normal of the mesh.
                ///
                std::vector<glm::vec3>  _normals;

                unsigned int            vbo;
        };
    }
}

#endif /* !__MESH_HPP__ */
