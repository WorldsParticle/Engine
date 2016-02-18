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

namespace   Engine
{
    HalfEdge::HalfEdge(void) :
        m_iterator(),
        m_vertex(nullptr),
        m_next(nullptr),
        m_pair(nullptr),
        m_face(nullptr)
    {
    }

    HalfEdge::HalfEdge(Vertex *vertex, HalfEdge *next, HalfEdge *pair, Face *face) :
        m_iterator(),
        m_vertex(vertex),
        m_next(next),
        m_pair(pair),
        m_face(face)
    {
    }

    HalfEdge::~HalfEdge(void)
    {

    }

    Vertex *&
    HalfEdge::vertex(void)
    {
        return this->m_vertex;
    }

    HalfEdge *&
    HalfEdge::next(void)
    {
        return this->m_next;
    }

    HalfEdge *&
    HalfEdge::pair(void)
    {
        return this->m_pair;
    }

    Face *&
    HalfEdge::face(void)
    {
        return this->m_face;
    }

    std::list<HalfEdge>::iterator &
    HalfEdge::iterator(void)
    {
        return this->m_iterator;
    }
}
