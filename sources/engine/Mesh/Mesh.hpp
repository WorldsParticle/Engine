#ifndef     __MESH_HPP__
# define    __MESH_HPP__

#include    <vector>
#include    <glm/glm.hpp>
#include    <assimp/mesh.h>

namespace WorldParticles
{
    namespace Engine
    {
        ///
        /// \brief The Mesh class
        ///
        class   Mesh
        {
            public:
                ///
                /// \brief Create an empty mesh.
                ///
                Mesh(void);

                ///
                /// \brief This constructor is used to transform an assimp mesh to a mesh.
                ///
                Mesh(const aiMesh *assimpMesh);

                ///
                /// \brief Destructor
                ///
                ~Mesh(void);

            public:

                /// should be removed
                void    initialise(void);

                /// should be removed
                void    bind(void) const;

                /// should be removed
                void    unbind(void) const;

                /// permet de mettre a jour le vbo.
                void    update(void);

            public:
                ///
                /// \brief Getter for the vertices attribute.
                ///
                const std::vector<glm::vec3>        &getVertices(void) const
                {
                    return this->_vertices;
                }

                ///
                /// \brief Getter for the normals attribute.
                ///
                const std::vector<glm::vec3>        &getNormals(void) const
                {
                    return this->_normals;
                }

                ///
                /// \brief Getter for the indices attribute.
                ///
                const std::vector<unsigned int>     &getIndices(void) const
                {
                    return this->_indices;
                }

            public:
                ///
                /// \brief Setter for the vertices attribute.
                ///
                void        setVertices(const std::vector<glm::vec3> &vertices)
                {
                    this->_vertices = vertices;
                }

                ///
                /// \brief Setter for the vertices attribute.
                /// \param[in] vertices A aiVector3D array of numberElements size.
                /// \param[in] numberElements Number of element present in the vertices array.
                ///
                void        setVertices(const aiVector3D *vertices, unsigned int numberElements);

                ///
                /// \brief Setter for the normal attribute.
                ///
                void        setNormals(const std::vector<glm::vec3> &normals)
                {
                    this->_normals = normals;
                }

                ///
                /// \brief Setter for the mesh normals.
                /// \param[in] normals A aiVector3D array of numberElement size which contains new normal value.
                /// \param[in] numberElements Number of element present in the normals array.
                ///
                void        setNormals(const aiVector3D *normals, unsigned int numberElements);

                ///
                /// \brief Setter for the indices attribute.
                ///
                void        setIndices(const std::vector<unsigned int> &indices)
                {
                    this->_indices = indices;
                }

                ///
                /// \brief Setter for the mesh indices.
                /// \param[in] faces A aiFace array of numberElements size which contains new indice values.
                /// \param[in] numberElements Number of element present in the faces array.
                ///
                void        setIndices(const aiFace *faces, unsigned int numberElements);

            private:
                ///
                /// \brief The name of the mesh.
                ///
                std::string                 _name;

                ///
                /// \brief The vertices attribute is used to store all vertex of the mesh.
                ///
                std::vector<glm::vec3>      _vertices;

                ///
                /// \brief The normals attribute is used to store all normal of the mesh.
                ///
                std::vector<glm::vec3>      _normals;

                ///
                /// \brief The indices attribute is used to store all indices of a mesh.
                ///
                std::vector<unsigned int>   _indices;

                std::shared_ptr<VertexBufferObject>     _bufferObject;
                std::shared_ptr<ElementBufferObject>    _elementBuffer;
                // TODO abstraction vbo, faire en sorte de pouvoir opti les bordels [v][n][v][n] au lieu [v][v][n][n]
        };
    }
}

#endif /* !__MESH_HPP__ */
