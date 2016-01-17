///
/// \file Mesh.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 21:03:53
///
/// \version 1.0.5
///

#ifndef     __ENGINE_MESH_HPP__
# define    __ENGINE_MESH_HPP__

#include    <vector>
#include    <memory>
#include    <glm/glm.hpp>
#include    <assimp/mesh.h>

#include    <Engine/BufferObject.hpp>
#include    <Engine/ArrayObject.hpp>

namespace WorldParticles
{
    namespace Engine
    {
        class Material;
        ///
        /// \brief The Mesh class
        ///
        class   Mesh
        {
            public:
                ///
                /// \brief Create an empty mesh.
                ///
                Mesh(Material *material);

                ///
                /// \brief This constructor is used to transform an assimp mesh to a mesh.
                ///
                Mesh(const aiMesh *assimpMesh, Material *material);

                ///
                /// \brief Copy constructor.
                ///
                Mesh(const Mesh &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Mesh(Mesh &&other) noexcept = default;

                ///
                /// \brief Destructor
                ///
                virtual ~Mesh(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Mesh    &operator=(const Mesh &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                Mesh    &operator=(Mesh &&other) noexcept = default;

            public:
                ///
                /// \brief This method is used to update the mesh in the graphic card.
                ///
                void    update(void);

                ///
                /// \brief This method is used to bind the mesh in the rendering pipeline.
                ///
                void    bind(void) const;

                ///
                /// \brief This method is used to unbind the mesh of the rendering pipeline.
                ///
                void    unbind(void) const;

                ///
                /// \brief This method is used to draw the mesh on the screen.
                ///
                void    draw(const glm::mat4 &model, const glm::mat4 &view,
                            const glm::mat4 &projection) const;

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
                /// \brief This method is used to know if the mesh contains uvs.
                ///
                bool    hasUVs(void) const;

                ///
                /// \brief This method is used to know if the mesh contains indices.
                ///
                bool    hasIndices(void) const;

            public:
                ///
                /// \brief Getter for the vertices attribute.
                ///
                const std::vector<float>            &getPositions(void) const;

                ///
                /// \brief Getter for the normals attribute.
                ///
                const std::vector<float>            &getNormals(void) const;

                ///
                /// \brief Getter for the uvs attribute.
                ///
                const std::vector<float>            &getUVs(void) const;

                ///
                /// \brief Getter for the indices attribute.
                ///
                const std::vector<unsigned int>     &getIndices(void) const;

            public:
                ///
                /// \brief Setter for the vertices attribute.
                ///
                void    setPositions(const std::vector<float> &positions);

                ///
                /// \brief Setter for the normal attribute.
                ///
                void    setNormals(const std::vector<float> &normals);

                ///
                /// \brief Setter for the uvs attribute.
                ///
                void    setUVs(const std::vector<float> &uvs);

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

                ///
                /// \brief Setter for the UVs channel.
                ///
                void    setUVs(const aiVector3D *uvs, unsigned int numberElements);

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
                std::vector<float>              positions;

                ///
                /// \brief The normals attribute is used to store all normal of the mesh.
                ///
                std::vector<float>              normals;

                ///
                /// \brief The uvs attribute is used to store one chanel of uvs.
                ///
                std::vector<float>              uvs;

                ///
                /// \brief The indices attribute is used to store all indices of a mesh.
                ///
                std::vector<unsigned int>       indices;

                ///
                /// \brief This attribute is used to connect the Mesh to a vertex buffer in the graphic API.
                ///
                std::shared_ptr<BufferObject>   vertexBuffer;

                ///
                /// \brief This attribute is used to connect the Mesh to a element buffer in the graphic API.
                ///
                std::shared_ptr<BufferObject>   elementBuffer;

                ///
                /// \brief The Array Object is used to describes how the vertex attributes are stored in the bufferObject.
                ///
                std::shared_ptr<ArrayObject>    arrayObject;

                ///
                /// \brief The material used by the mesh.
                ///
                Material                        *material; // TODO GSL not null.
        };
    }
}

#endif /* !__ENGINE_MESH_HPP__ */