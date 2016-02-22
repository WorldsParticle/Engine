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
#include    <algorithm>

#define GLM_SWIZZLE
#define GLM_SWIZZLE_XYZW
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


    class   EdgeCollapse
    {
        public:
        HalfEdge   *m_he;
        std::multiset<EdgeCollapse>::iterator  m_iterator;
        mutable float       m_error;

        public:

        // MUST BE ORDERED BY SMALLEST ERROR

        float       error(void) const
        {
            Vertex *v1 = this->m_he->vertex();
            Vertex *v2 = this->m_he->pair()->vertex();

/*            glm::vec4 pos = glm::vec4(v1->position() + v2->position(), 1.0f);*/
            //pos /= 2;
            //pos.w = 1.0f;

            glm::mat4 Q = v1->quadric() + v2->quadric();
            glm::mat4 Qi = glm::mat4(Q[0], Q[1], Q[2], glm::vec4(0.0f, 0.0f, 0.0f, 1.0f));
            Qi = glm::inverse(Qi);
            glm::vec4 pos = glm::vec4(Qi[0][3], Qi[1][3], Qi[2][3], Qi[3][3]);

            glm::vec4   v = pos;

            glm::vec4   t = v * Q;
            float val = glm::dot(t, v);

/*            float val = v1->compute_quadric_error(v1->position())*/
                /*+ v2->compute_quadric_error(v2->position());*/
            m_error = val;
            return val;
        };

        public:
        friend bool   operator<(const EdgeCollapse &l, const EdgeCollapse &r)
        {
            return l.error() < r.error();
        };

        friend bool   operator>(const EdgeCollapse &l, const EdgeCollapse &r)
        {
            return l.error() > r.error();
        };


/*        bool   operator>(const EdgeCollapse &other) const*/
        //{
            //return this->error() > other.error();
        //};

        public:
        EdgeCollapse(HalfEdge *ptr) : m_he(ptr), m_iterator(), m_error(42)
        {

        }

        HalfEdge *&half_edge(void)
        {
             return this->m_he;
        }

        HalfEdge *half_edge_const(void) const
        {
             return this->m_he;
        }

        std::set<EdgeCollapse>::iterator &
        iterator(void)
        {
             return this->m_iterator;
        }
    };

    using Edge = std::pair<Vertex *, Vertex *>;
    using FaceVertices = std::tuple<Vertex *, Vertex *, Vertex *>;

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
            void    draw(const glm::mat4 &model, const glm::mat4 &view,
                        const glm::mat4 &projection);

        private:
            void    update(void);
            void    update_vao(void);

        public:
            void    increase(void);
            void    reduce(void);

        public:

            bool check_consistency(void);
            Vertex  *collapse(Vertex *v1, Vertex *v2);
            HalfEdge *merge(HalfEdge *he1, HalfEdge *he2);
            void tmp(int);
        private:

            ///
            /// \brief Build the connectivity of an assimp mesh.
            ///
            void    build_connectivity(const aiMesh *ai_mesh);

            ///
            /// \brief Build all vertices of the mesh from the vertices assimp
            ///     array.
            /// \param[in] ai_vertices The assimp array of vertices.
            /// \param[in] ai_vertices_number The number of vertices in the
            ///     ai_vertices array.
            /// \return Return an rvalue reference of a vector filled with
            ///     vertex pointer at their index position in the ai_vertices
            ///     array.
            ///
            std::vector<Vertex *>   build_vertices(
                    const aiVector3D *ai_vertices,
                    unsigned int ai_vertices_number);

            ///
            /// \brief Build all faces of the mesh from the face assimp array.
            /// \param[in] ai_faces The assimp array of faces.
            /// \param[in] ai_faces_number The number of elements in the
            ///     ai_faces array.
            /// \return Return an rvalue reference of a vector filled with face
            ///     pointer at their index position in the ai_faces array.
            ///
            std::vector<Face *>     build_faces(unsigned int ai_faces_number);

            ///
            /// \brief Build a set of edge. An edge is just a pair of vertex
            ///     index.
            /// \param[in] ai_faces The assimp array of faces.
            /// \param[in] ai_faces_number The number of elements in the
            ///     ai_faces array.
            /// \return Return an rvalue reference of a set of pair of vertex
            ///     index that represent an edge between these two vertex index.
            ///
            std::set<Edge>  build_edges(const aiFace *ai_faces,
                    unsigned int ai_faces_number,
                    const std::vector<Vertex *> &vertices);

            ///
            /// \brief Build a map of edge to face, edge are directional. An
            ///     edge have one entry for its two direction. 0 to 1 && 1 to 0.
            /// \param[in] ai_faces The assimp array of faces.
            /// \param[in] ai_faces_number The number of elements in the
            ///     ai_faces array.
            /// \return Return an rvalue reference of the map created.
            ///
            std::map<Edge, Face *>   build_ordered_edge_to_face_map(
                    const aiFace *ai_faces,
                    unsigned int ai_faces_number,
                    const std::vector<Face *> &faces,
                    const std::vector<Vertex *> &vertices);

            ///
            /// \brief Build all the half edges of the mesh.
            /// \param[in] edges the set of edge created by the "build_edges"
            ///     method.
            /// \param[in] vertices The vector of vertices created by the
            ///     "build_vertices" method.
            /// \param[in] ordered_edge_to_face_map The edge to face map created
            ///     by the "build_ordered_edge_to_face_map" method.
            /// \return Return an rvalue reference of a
            ///     "ordered edge to half edge" map.
            ///
            std::map<Edge, HalfEdge *> build_half_edges(
                    const std::set<Edge> &edges,
                    const std::map<Edge, Face *> &ordered_edge_to_face);

            ///
            /// \brief This method create a map of face to vertices. Used in the
            ///     construction of half_edge connectivity.
            /// \param[in] ai_faces The assimp array of faces.
            /// \param[in] ai_faces_number The number of faces in the assimp
            ///     array of faces.
            /// \param[in] faces The vector of faces generated by the
            ///     "build_faces" method.
            /// \param[in] vertices The vector of vertices generated by the
            ///     "build_vertices" method.
            /// \return Return the map of face to vertices.
            ///
            std::map<Face *, FaceVertices> build_face_to_vertices(
                    const aiFace *ai_faces,
                    unsigned int ai_faces_number,
                    const std::vector<Face *> &faces,
                    const std::vector<Vertex *> &vertices);

            ///
            /// \brief This method set the next component of each half edge.
            /// \param[in] faces_to_vertices The map of face to vertices
            ///     generated by the "build_face_to_vertices" method.
            /// \param[in] ord_edge_to_half_edge A map of directional edge to
            ///     half edge.
            ///
            void    build_half_edge_connectivity(
                    const std::map<Face *, FaceVertices> &faces_to_vertices,
                    const std::map<Edge, HalfEdge *> &ord_edge_to_half_edge);

            ///
            /// \brief This method construct the half_edge connectivity for
            ///     half edge boundary.
            /// \param[in] boundary_half_edges The list of boundary half edge.
            ///
            /// Invoked by the build_half_edge_connectivity.
            ///
            void    build_half_edge_boundary_connectivity(
                    const std::list<HalfEdge *> &boundary_half_edge);

            ///
            /// \brief Set the prev component of each half_edge. prev component
            ///     is add in order to support boundary mesh decimation.
            ///
            void    set_half_edge_prev_component(void);

            void    compute_quadric(void);
            void    compute_priority_queue(void);

            ///
            /// \brief Create a new empty half_edge in the m_half_edges list
            ///     and initialise the iterator member in the half_edge
            /// \return Return a reference to the new HalfEdge.
            ///
            HalfEdge    &build_half_edge(void);

            ///
            /// \brief Create a new empty vertex in the m_vertices list. Also
            ///     initialise the iterator member of the vertex.
            /// \return Return a reference to the new vertex.
            ///
            Vertex      &build_vertex(void);

            ///
            /// \brief Create a new empty face in the m_faces list. Also set the
            ///     iterator member of the new face.
            /// \return Return a reference to the new face.
            ///
            Face        &build_face(void);

        private:

            ///
            /// \return True if the mesh must be updated in the graphic card.
            ///     False otherwise.
            ///
            bool        is_dirty(void) const;

        private:
            ///
            /// \brief The name of the mesh.
            ///
            std::string         m_name;

            /// TODO => do better.
            std::list<HalfEdge *>   m_edges;
            std::multiset<EdgeCollapse, std::less<EdgeCollapse>>   m_collapse;

            std::list<HalfEdge>     m_half_edges;
            std::list<Face>         m_faces;
            std::list<Vertex>       m_vertices;

            std::shared_ptr<BufferObject>   m_vertices_buffer;
            std::shared_ptr<BufferObject>   m_elements_buffer;
            std::shared_ptr<ArrayObject>    m_array_object;
            Material        *m_material;

            ///
            /// \brief Set to true if the mesh must be updated in the graphic
            ///     card.
            ///
            bool            m_dirty;

    };
}
