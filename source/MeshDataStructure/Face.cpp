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

#include    "Engine/MeshDataStructure/Face.hpp"

namespace   Engine
{
    Face::Face(void) :
        m_half_edge(nullptr),
        m_iterator()
    {
    }

    Face::Face(HalfEdge *half_edge) :
        m_half_edge(half_edge),
        m_iterator()
    {

    }

    Face::~Face(void)
    {
    }

    HalfEdge *&
    Face::half_edge(void)
    {
        return this->m_half_edge;
    }

    std::list<Face>::iterator &
    Face::iterator(void)
    {
         return this->m_iterator;
    }
}
