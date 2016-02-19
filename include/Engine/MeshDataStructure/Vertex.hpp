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

#include    <glm/glm.hpp>

#include    "Engine/Configuration.hpp"

namespace   Engine
{
    class   HalfEdge;

    class   ENGINE_EXPORTS Vertex final
    {
        public:
            Vertex(void);
            Vertex(const glm::vec3 &position, HalfEdge *half_edge);
            Vertex(const Vertex &other) noexcept = default;
            Vertex(Vertex &&other) noexcept = default;
            ~Vertex(void) noexcept;

        public:
            Vertex  &operator=(const Vertex &other) noexcept = default;
            Vertex  &operator=(Vertex &&other) noexcept = default;

        public:
            HalfEdge    *&half_edge(void);
            glm::vec3   &position(void);
            std::list<Vertex>::iterator     &iterator(void);

        private:
            std::size_t                     m_index;
            std::list<Vertex>::iterator     m_iterator;
            glm::vec3                       m_position;
            HalfEdge                        *m_half_edge;
    };
}
