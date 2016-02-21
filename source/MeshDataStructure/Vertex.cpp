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

#include <iostream>

#include    "Engine/MeshDataStructure/HalfEdge.hpp"
#include    "Engine/MeshDataStructure/Vertex.hpp"

namespace   Engine
{
    Vertex::Vertex(void) :
        m_index(0),
        m_iterator(),
        m_position(0.0f),
        m_half_edge(nullptr),
        m_quadric(0)
    {
    }

    Vertex::~Vertex(void)
    {

    }



    std::size_t &
    Vertex::index(void)
    {
         return this->m_index;
    }

    HalfEdge *&
    Vertex::half_edge(void)
    {
        return this->m_half_edge;
    }

    glm::vec3 &
    Vertex::position(void)
    {
        return this->m_position;
    }

    std::list<Vertex>::iterator &
    Vertex::iterator(void)
    {
        return this->m_iterator;
    }



    std::vector<HalfEdge *>
    Vertex::ingoing_half_edges(void)
    {
        std::vector<HalfEdge *> ingoing_half_edges;

        HalfEdge *start = this->m_half_edge;
        HalfEdge *e = start;
        do
        {
            ingoing_half_edges.push_back(e->pair());
            e = e->pair()->next();
        } while (e != start);
        return ingoing_half_edges;
    }

    std::vector<HalfEdge *>
    Vertex::outgoing_half_edges(void)
    {
        std::vector<HalfEdge *> outgoing_half_edges;

        HalfEdge *start = this->m_half_edge;
        HalfEdge *e = start;
        do
        {
            outgoing_half_edges.push_back(e);
            e = e->pair()->next();
        } while (e != start);
        return outgoing_half_edges;
    }

    HalfEdge *
    Vertex::outgoing_half_edge_to(Vertex *vertex)
    {
        HalfEdge *start = this->m_half_edge;
        HalfEdge *e = start;
        do
        {
            if (e->vertex() == vertex)
                return e;
            e = e->pair()->next();
        } while (e != start);
        return nullptr;
    }

    std::vector<Vertex *>
    Vertex::neighbour_vertices(void)
    {
        std::vector<Vertex *>   neighbours;
        HalfEdge *start = this->m_half_edge;
        HalfEdge *e = start;
        do
        {
            neighbours.push_back(e->vertex());
            e = e->pair()->next();
        } while (e != start);
        return neighbours;
    }

    bool
    Vertex::is_boundary(void) const
    {
        HalfEdge *start = this->m_half_edge;
        HalfEdge *e = start;
        do
        {
            if (e->is_boundary())
                return true;
            e = e->pair()->next();
        } while (e != start);
        return false;
    }


    std::vector<Vertex *>
    Vertex::shared_neighbour_vertices_with(Vertex *vertex)
    {
        std::vector<Vertex *>     owner_neighbour = this->neighbour_vertices();
        std::vector<Vertex *>     target_neighbour = vertex->neighbour_vertices();
        std::vector<Vertex *> result;

        for (Vertex *n_v1 : owner_neighbour)
        {
            for (Vertex *n_v2 : target_neighbour)
            {
                if (n_v1 == n_v2)
                {
                    result.push_back(n_v1);
                }
            }
        }
        return result;
    }

    glm::mat4 &
    Vertex::quadric(void)
    {
        return this->m_quadric;
    }

    float
    Vertex::compute_quadric_error(const glm::vec3 &p)
    {
        glm::mat4   Q = this->m_quadric;

        return Q[0][0] * p.x * p.x + 2.0f * Q[0][1] * p.x * p.y + 2.0f * Q[0][2] * p.x * p.y + 2.0f * Q[0][3] * p.x
            + Q[1][1] * p.y * p.y + 2.0f * Q[1][2] * p.y * p.z + 2.0f * Q[1][3]
            + Q[2][2] * p.z * p.z + 2.0f * Q[2][3] * p.z
            + Q[3][3];
    }
}
