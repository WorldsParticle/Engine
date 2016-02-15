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

namespace   Engine
{

    class   Material;

    ///
    /// \brief The mesh class.
    ///
    class ENGINE_EXPORTS Mesh final
    {

        private:

            struct Edge;

            struct  Face
            {
                ///
                /// \brief The first edge of the face.
                ///
                std::list<Edge>::iterator   *first_edge;
            };

            class  Vertex
            {

                public:

                    ///
                    /// \brief Default constructor.
                    ///
                    Vertex(const glm::vec3 &position, const glm::vec3 &normal);

                    ///
                    /// \brief Copy constructor.
                    ///
                    Vertex(const Vertex &other);

                    ///
                    /// \brief Move constructor.
                    ///
                    Vertex(Vertex &&other) noexcept;

                    ///
                    /// \brief Destructor.
                    ///
                    ~Vertex(void) noexcept;

                public:

                    ///
                    /// \brief Copy assignment operator.
                    ///
                    Vertex  &operator=(const Vertex &other);

                    ///
                    /// \brief Move assignment operator.
                    ///
                    Vertex  &operator=(Vertex &&other) noexcept;

                public:

                    ///
                    /// \brief Return an edge between this vertex and the one in parameter. Or nullptr if that don't exist.
                    ///
                    std::list<Edge>::iterator *search_edge_to(const std::list<Vertex>::iterator &vertex);

                    ///
                    /// \brief Create an edge between this vertex and the one in parameter.
                    ///
                    std::list<Edge>::iterator *create_edge_to(const std::list<Vertex>::iterator &vertex);

                public:

                    ///
                    /// \brief The index of the vertex. Used in order to compute the indice buffer.
                    ///
                    unsigned int    index;

                    ///
                    /// \brief The position of the vertex.
                    ///
                    glm::vec3       position;

                    ///
                    /// \brief The normal of the vertex.
                    ///
                    glm::vec3       normal;

                    ///
                    /// \brief One of the edge connected to the vertex.
                    ///
                    std::list<Edge>::iterator   *edge;

                    ///
                    /// \brief The vertex iterator.
                    ///
                    std::list<Vertex>::iterator iterator;

            };

            class  Edge
            {

                public:

                    ///
                    /// \brief Default constructor.
                    ///
                    Edge(const std::list<Vertex>::iterator &begin_vertex,
                            const std::list<Vertex>::iterator &end_vertex);

                    ///
                    /// \brief Copy constructor.
                    ///
                    Edge(const Edge &other);

                    ///
                    /// \brief Move constructor.
                    ///
                    Edge(Edge &&other) noexcept;

                    ///
                    /// \brief Destructor.
                    ///
                    virtual ~Edge(void) noexcept;

                public:
                    ///
                    /// \brief Copy assignment operator.
                    ///
                    Edge    &operator=(const Edge &other);

                    ///
                    /// \brief Move assignment operator.
                    ///
                    Edge    &operator=(Edge &&other) noexcept;

                public:

                    ///
                    /// \brief Return true if v0 && v1 match begin and end (the order doesn't matter).
                    ///
                    bool match(const std::list<Vertex>::iterator &v0, const std::list<Vertex>::iterator &v1) const;

                    ///
                    /// \brief Return true if v0 is the begin vertex and v1 is the end vertex. False otherwise.
                    ///
                    /// Throw runtime_exception if v0 or v1 is nor begin nor end.
                    ///
                    bool is_oriented(std::list<Vertex>::iterator &v0, std::list<Vertex>::iterator &v1);

                    ///
                    /// \brief Return true if end vertex is v0. False otherwise.
                    ///
                    bool is_oriented(std::list<Vertex>::iterator &vo);

                    ///
                    /// \brief Build the wing of the edge. if oriented is true, it's the left wing, right wing otherwise.
                    ///
                    void build_connectivity(std::list<Edge>::iterator *backward_edge, std::list<Edge>::iterator *forward_edge, std::list<Face>::iterator *face, bool oriented);

                public:

                    ///
                    /// \brief The begin vertex of the winged edge.
                    ///
                    std::list<Vertex>::iterator begin_vertex;

                    ///
                    /// \brief The end vertex of the winged edge.
                    ///
                    std::list<Vertex>::iterator end_vertex;

                    ///
                    /// \brief The left face of the edge.
                    ///
                    std::list<Face>::iterator   *left_face;

                    ///
                    /// \brief The right face of the edge.
                    ///
                    std::list<Face>::iterator   *right_face;

                    ///
                    /// \brief The forward left edge
                    ///
                    std::list<Edge>::iterator   *forward_left_edge;

                    ///
                    /// \brief The forward right edge.
                    ///
                    std::list<Edge>::iterator   *forward_right_edge;

                    ///
                    /// \brief The backward left edge.
                    ///
                    std::list<Edge>::iterator   *backward_left_edge;

                    ///
                    /// \brief The backward right edge.
                    ///
                    std::list<Edge>::iterator   *backward_right_edge;

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
