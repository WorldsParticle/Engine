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

            std::vector<Vertex *>   &&build_vertices(const aiMesh *assimp_mesh);

            std::vector<Face *>     &&build_faces(const aiMesh *assimp_mesh);

            std::set<std::pair<std::size_t, std::size_t>>     &&build_edges(
                    const aiMesh *assimp_mesh);

            std::map<std::pair<std::size_t, std::size_t>, Face *>     &&build_ordered_edge_to_face_map(
                    const aiMesh *assimp_mesh, const std::vector<Face *> &faces);


            void    build_connectivity(const std::set<std::pair<std::size_t, std::size_t>> &edges,
                    const std::vector<Vertex *> &vertices, const std::vector<Face *> &faces,
                    const std::map<std::pair<std::size_t, std::size_t>, Face *> &ordered_edge_to_face_map);

            HalfEdge *build_half_edge(void);

        private:
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
