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

#include    <list>
#include    <memory>
#include    <glm/glm.hpp>
#include    <assimp/mesh.h>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/BufferObject.hpp"
#include    "Engine/Core/ArrayObject.hpp"

#include    "Engine/Core/Edge.hpp"
#include    "Engine/Core/Face.hpp"
#include    "Engine/Core/Vertex.hpp"

namespace   Engine
{

    class   Material;

    ///
    /// \brief The mesh class.
    ///
    class ENGINE_EXPORTS Mesh final
    {

        public:
            ///
            /// \brief Create an empty mesh.
            ///
            Mesh(Material *material);

            ///
            /// \brief Construct a mesh from an assimp mesh and a material.
            ///
            Mesh(const aiMesh *assimp_mesh, Material *material);

            ///
            /// \brief Copy constructor.
            ///
            /// TODO must be manually implemented.
            ///
            Mesh(const Mesh &other) = default;

            ///
            /// \brief Move constructor.
            ///
            /// TODO must be manually implemented.
            ///
            Mesh(Mesh &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            virtual ~Mesh(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            /// TODO must be manually implemented.
            ///
            Mesh    &operator=(const Mesh &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            /// TODO must be manually implemented.
            ///
            Mesh    &operator=(Mesh &&other) noexcept = default;

        public:

            ///
            /// \brief Draw the mesh on the screen.
            ///
            /// TODO temporary.
            ///
            void    draw(const glm::mat4 &model, const glm::mat4 &view, const glm::mat4 &projection);

            ///
            /// \brief Update the mesh in the graphic card.
            ///
            /// TODO temporary.
            ///
            void    update(void);

            ///
            /// \brief True if the mesh must be updated in the graphic card before drawing. False otherwise.
            ///
            bool    is_dirty(void) const;

        private:

            ///
            /// \brief Update the vertices_buffer.
            ///
            void    update_vertices_buffer(void);

            ///
            /// \brief Update the elements buffer.
            ///
            void    update_elements_buffer(void);

            ///
            /// \brief Update the array object.
            ///
            void    update_array_object(void);

        private:
            ///
            /// \brief The name of the mesh.
            ///
            std::string     m_name;

            ///
            /// \brief True if the mesh need to be updated in the graphic card.
            ///
            bool            m_dirty;

            std::list<Edge>     m_edges;
            std::list<Face>     m_faces;
            std::list<Vertex>   m_vertices;

            ///
            /// TODO Three temporary member.
            ///
            std::shared_ptr<BufferObject>   m_vertices_buffer;
            std::shared_ptr<BufferObject>   m_elements_buffer;
            std::shared_ptr<ArrayObject>    m_array_object;

            ///
            /// \brief The material used by the mesh.
            ///
            Material        *m_material;
    };
}
