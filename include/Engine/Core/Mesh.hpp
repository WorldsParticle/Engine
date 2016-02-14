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

namespace   Engine
{
    ///
    /// \brief The mesh class.
    ///
    class ENGINE_EXPORTS Mesh final
    {

        private:

            class   Edge
            {
                ///
                /// \brief The id of the edge.
                ///
                unsigned int    id;

                unsigned int    begin_vertex_id;
                unsigned int    end_vertex_id;

                unsigned int    left_face_id;
                unsigned int    right_face_id;

                unsigned int    forward_left_edge_id;
                unsigned int    forward_right_edge_id;
                unsigned int    backward_left_edge_id;
                unsigned int    backward_right_edge_id;

            };

            class   Face
            {
                ///
                /// \brief The id of the face.
                ///
                unsigned int    id;

            };

            class    Vertex
            {
                ///
                /// \brief The id of the vertex.
                ///
                unsigned int    id;
            };

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

        private:
            ///
            /// \brief The name of the mesh.
            ///
            std::string     m_name;

            std::list<glm::vec3>    m_vertex;

            ///
            ///
            ///
            std::list<Edge>         m_edges;

            ///
            /// \brief The material used by the mesh.
            ///
            Material        *m_material;
    }
}
