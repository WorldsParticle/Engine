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
}
