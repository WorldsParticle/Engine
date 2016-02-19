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

#include    <set>
#include    <map>
#include    <list>
#include    <string>
#include    <memory>

#include    <glm/glm.hpp>

#include    <assimp/mesh.h>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/BufferObject.hpp"
#include    "Engine/Core/ArrayObject.hpp"
#include    "Engine/MeshDataStructure/HalfEdge.hpp"
#include    "Engine/MeshDataStructure/Vertex.hpp"
#include    "Engine/MeshDataStructure/Face.hpp"

namespace   Engine
{
    class   Material;

    class   ENGINE_EXPORTS Mesh final
    {
        public:
            Mesh(Material *material);
            Mesh(const aiMesh *assimp_mesh, Material *material);
            Mesh(const Mesh &other) = default;
            Mesh(Mesh &&other) noexcept = default;
            ~Mesh(void) noexcept;

        public:
            Mesh    &operator=(const Mesh &other) = default;
            Mesh    &operator=(Mesh &&other) noexcept = default;

        public:
            void    draw(const glm::mat4 &model, const glm::mat4 &view, const glm::mat4 &projection);

        public:
            void    increase(void);
            void    reduce(void);

        private:

            ///
            /// \brief Build all vertices of the mesh from the vertices assimp array.
            /// \param[in] ai_vertices The assimp array of vertices.
            /// \param[in] ai_vertices_number The number of vertices in the ai_vertices array.
            /// \return Return an rvalue reference of a vector filled with vertex pointer at their index position in the ai_vertices array.
            ///
            std::vector<Vertex *>   &&build_vertices(const aiVector3D *ai_vertices,
                    unsigned int ai_vertices_number);

            ///
            /// \brief Build all faces of the mesh from the face assimp array.
            /// \param[in] ai_faces The assimp array of faces.
            /// \param[in] ai_faces_number The number of elements in the
            ///     ai_faces array.
            /// \return Return an rvalue reference of a vector filled with face
            ///     pointer at their index position in the ai_faces array.
            ///
            std::vector<Face *>     &&build_faces(const aiFace *ai_faces,
                    unsigned int ai_faces_number);

            ///
            /// \brief Build a set of edge. An edge is just a pair of vertex index.
            /// \param[in] ai_faces The assimp array of faces.
            /// \param[in] ai_faces_number The number of elements in the ai_faces array.
            /// \return Return an rvalue reference of a set of pair of vertex index
            ///     that represent an edge between these two vertex index.
            ///
            std::set<std::pair<std::size_t, std::size_t>>     &&build_edges(
                    const aiFace *ai_faces, unsigned int ai_faces_number);

            ///
            /// \brief Build a map of edge to face, edge are directional. An
            ///     edge have one entry for its two direction. 0 to 1 && 1 to 0.
            /// \param[in] ai_faces The assimp array of faces.
            /// \param[in] ai_faces_number The number of elements in the ai_faces array.
            /// \return Return an rvalue reference of the map created.
            ///
            std::map<std::pair<std::size_t, std::size_t>, Face *>   &&build_ordered_edge_to_face_map(
                    const aiFace *ai_faces, unsigned int ai_faces_number,
                    const std::vector<Face *> &faces);

            ///
            /// \brief Build all the half edges of the mesh.
            /// \param[in] edges the set of edge created by the "build_edges" method.
            /// \param[in] vertices The vector of vertices created by the "build_vertices" method.
            /// \param[in] ordered_edge_to_face_map The edge to face map created by the "build_ordered_edge_to_face_map" method.
            /// \return Return an rvalue reference of a ordered edge to half_edge map.
            ///
            std::map<std::pair<std::size_t, std::size_t>, HalfEdge *> &&
                build_half_edges(const std::set<std::pair<std::size_t, std::size_t>> &edges,
                        const std::vector<Vertex *> &vertices,
                        const std::map<std::pair<std::size_t, std::size_t>, Face *> &ordered_edge_to_face_map);

            ///
            /// \brief Build the connectivity of an assimp mesh.
            ///
            void    build_connectivity(const aiMesh *ai_mesh);

            void    build_half_edge_connectivity(const aiMesh *assimp_mesh);


            HalfEdge    *build_half_edge(void);
            Vertex      *build_vertex(void);
            Face        *build_face(void);

        private:
            ///
            /// \brief The name of the mesh.
            ///
            std::string         m_name;

            std::list<HalfEdge> m_half_edges;
            std::list<Face>     m_faces;
            std::list<Vertex>   m_vertices;

            std::shared_ptr<BufferObject>   m_vertices_buffer;
            std::shared_ptr<BufferObject>   m_elements_buffer;
            std::shared_ptr<ArrayObject>    m_array_object;
            Material        *m_material;

    };
}
