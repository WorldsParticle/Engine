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

#include    "Engine/Configuration.hpp"

namespace   Engine
{
    class   EdgeCollapse;
    class   Vertex;
    class   Face;

    class   ENGINE_EXPORTS HalfEdge final
    {
        public:
            HalfEdge(void);
            HalfEdge(const HalfEdge &other) noexcept = default;
            HalfEdge(HalfEdge &&other) noexcept = default;
            ~HalfEdge(void);

        public:
            HalfEdge    &operator=(const HalfEdge &other) noexcept = default;
            HalfEdge    &operator=(HalfEdge &&other) noexcept = default;

        public:
            Vertex      *&vertex(void);
            HalfEdge    *&next(void);
            HalfEdge    *&prev(void);
            HalfEdge    *&pair(void);
            Face        *&face(void);
            std::list<HalfEdge>::iterator   &iterator(void);

        public:

            bool        is_boundary(void) const;

            EdgeCollapse    *&edge(void);

        private:
            std::list<HalfEdge>::iterator   m_iterator;
            ///
            /// \brief Vertex at the end of the half edge.
            ///
            Vertex          *m_vertex;
            HalfEdge        *m_next;
            HalfEdge        *m_prev;
            HalfEdge        *m_pair;
            Face            *m_face;
            EdgeCollapse    *m_edge;
    };
}
