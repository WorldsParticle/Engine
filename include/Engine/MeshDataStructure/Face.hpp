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

#include    <glm/glm.hpp>

#include    <vector>

#include    "Engine/Configuration.hpp"
#include    "Engine/MeshDataStructure/HalfEdge.hpp"

namespace   Engine
{
     class ENGINE_EXPORTS   Face final
     {
        public:
            Face(void);
            Face(HalfEdge *half_edge);
            Face(const Face &other) noexcept = default;
            Face(Face &&other) noexcept = default;
            ~Face(void) noexcept;

        public:
            Face    &operator=(const Face &other) noexcept = default;
            Face    &operator=(Face &&other) noexcept = default;

        public:
            HalfEdge                    *&half_edge(void);
            std::list<Face>::iterator   &iterator(void);
            glm::vec3                   &color(void);

        public:
            glm::vec3                   normal(void);
            std::vector<Vertex *>       vertices(void) const;

        public:
            ///
            /// \brief Compute and return the plane equation of the face.
            ///
            glm::vec4                   plane_equation(void) const;

        private:
            HalfEdge                    *m_half_edge;
            std::list<Face>::iterator   m_iterator;
            glm::vec3                   m_color;
     };
}

