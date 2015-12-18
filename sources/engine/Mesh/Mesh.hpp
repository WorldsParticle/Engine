#ifndef     __MESH_HPP__
# define    __MESH_HPP__

#include    <vector>
#include    <memory>
#include    <glm/glm.hpp>
#include    <assimp/mesh.h>

#include    "BufferObject.hpp"

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
                ///
                /// \brief This method is used to update the mesh in the graphic card.
                ///
                void    update(void);

                ///
                /// \brief This method is used to bind the mesh in the rendering pipeline.
                ///
                void    bind(void);

                ///
                /// \brief This method is used to unbind the mesh of the rendering pipeline.
                ///
                void    unbind(void);

            public:
                ///
                /// \brief This method is used to know if the mesh contains positions.
                ///
                bool    hasPositions(void) const;

                ///
                /// \brief This method is used to know if the mesh contains normals.
                ///
                bool    hasNormals(void) const;

                ///
                /// \brief This method is used to know if the mesh contains indices.
                ///
                bool    hasIndices(void) const;

            public:
                ///
                /// \brief Getter for the vertices attribute.
                ///
                const std::vector<glm::vec3>        &getPositions(void) const;

                ///
                /// \brief Getter for the normals attribute.
                ///
                const std::vector<glm::vec3>        &getNormals(void) const;

                ///
                /// \brief Getter for the indices attribute.
                ///
                const std::vector<unsigned int>     &getIndices(void) const;

            public:
                ///
                /// \brief Setter for the vertices attribute.
                ///
                void    setPositions(const std::vector<glm::vec3> &positions);

                ///
                /// \brief Setter for the normal attribute.
                ///
                void    setNormals(const std::vector<glm::vec3> &normals);

                ///
                /// \brief Setter for the indices attribute.
                ///
                void    setIndices(const std::vector<unsigned int> &indices);

            private:
                ///
                /// \brief Setter for the vertices attribute.
                /// \param[in] positions A aiVector3D array of numberElements size.
                /// \param[in] numberElements Number of element present in the vertices array.
                ///
                void    setPositions(const aiVector3D *positions, unsigned int numberElements);

                ///
                /// \brief Setter for the mesh normals.
                /// \param[in] normals A aiVector3D array of numberElement size which contains new normal value.
                /// \param[in] numberElements Number of element present in the normals array.
                ///
                void    setNormals(const aiVector3D *normals, unsigned int numberElements);

                ///
                /// \brief Setter for the mesh indices.
                /// \param[in] faces A aiFace array of numberElements size which contains new indice values.
                /// \param[in] numberElements Number of element present in the faces array.
                ///
                void    setIndices(const aiFace *faces, unsigned int numberElements);

            private:
                ///
                /// \brief The name of the mesh.
                ///
                /// the name is optional, could be an empty string.
                ///
                std::string                     name;

                ///
                /// \brief The vertices attribute is used to store all vertex of the mesh.
                ///
                std::vector<glm::vec3>          positions;

                ///
                /// \brief The normals attribute is used to store all normal of the mesh.
                ///
                std::vector<glm::vec3>          normals;

                ///
                /// \brief The indices attribute is used to store all indices of a mesh.
                ///
                std::vector<unsigned int>       indices;

                ///
                /// \brief This boolean is used to know if the mesh should be send to the graphic api or if it's already updated.
                ///
                bool                            updated;

                ///
                /// \brief This boolean is used to know if the mesh is optmized for rendering.
                ///
                bool                            optimized;

                ///
                /// \brief This attribute is used to connect the Mesh to a vertex buffer in the graphic API.
                ///
                std::shared_ptr<BufferObject>   vertexBuffer;

                ///
                /// \brief This attribute is used to connect the Mesh to a element buffer in the graphic API.
                ///
                std::shared_ptr<BufferObject>   elementBuffer;
        };
    }
}

#endif /* !__MESH_HPP__ */
