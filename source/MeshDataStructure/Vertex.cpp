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

#include    "Engine/MeshDataStructure/HalfEdge.hpp"
#include    "Engine/MeshDataStructure/Vertex.hpp"

namespace   Engine
{
    Vertex::Vertex(void) :
        m_index(0),
        m_iterator(),
        m_position(0.0f),
        m_half_edge(nullptr)
    {
    }

    Vertex::Vertex(const glm::vec3 &position, HalfEdge *half_edge) :
        m_index(0),
        m_iterator(),
        m_position(position),
        m_half_edge(half_edge)
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
}
