//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
//

#pragma once

#include    <vector>
#include    <memory>
#include    <glm/glm.hpp>
#include    <assimp/mesh.h>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/BufferObject.hpp"
#include    "Engine/Core/ArrayObject.hpp"

namespace   Engine
{
    class       Material;

    ///
    /// \brief The Mesh class
    ///
    class ENGINE_EXPORTS Mesh final
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
            /// \brief Getter for the name attribute.
            ///
            const std::string                   &getName(void) const;

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

        public://TODO put back to private
            ///
            /// \brief The name of the mesh.
            ///
            /// the name is optional, could be an empty string.
            ///
            std::string     m_name;

        private:

            ///
            /// \brief The vertices attribute is used to store all vertex of the mesh.
            ///
            std::vector<float>  m_positions;

            ///
            /// \brief The normals attribute is used to store all normal of the mesh.
            ///
            std::vector<float>  m_normals;

            ///
            /// \brief The uvs attribute is used to store one chanel of uvs.
            ///
            std::vector<float>  m_uvs;

            ///
            /// \brief The indices attribute is used to store all indices of a mesh.
            ///
            std::vector<unsigned int>   m_indices;

            ///
            /// \brief This attribute is used to connect the Mesh to a vertex buffer in the graphic API.
            ///
            std::shared_ptr<BufferObject>   m_vertexBuffer;

            ///
            /// \brief This attribute is used to connect the Mesh to a element buffer in the graphic API.
            ///
            std::shared_ptr<BufferObject>   m_elementBuffer;

            ///
            /// \brief The Array Object is used to describes how the vertex attributes are stored in the bufferObject.
            ///
            std::shared_ptr<ArrayObject>    m_arrayObject;

            ///
            /// \brief The material used by the mesh.
            ///
            Material    *m_material; // TODO GSL not null.
    };
}
