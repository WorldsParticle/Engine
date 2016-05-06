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

#include    "Engine/Configuration.hpp"
#include    "Engine/Event/Event.hpp"

namespace   Engine
{
    namespace   Event
    {
        class ENGINE_EXPORTS Resize : public Event
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                Resize(const glm::ivec2 &s);

                ///
                /// \brief Destructor.
                ///
                ~Resize(void);

            public:
                ///
                /// \brief Get the size of the event.
                ///
                const glm::ivec2    &size(void) const;

            protected:
                ///
                /// \brief The new size of the resize event.
                ///
                glm::ivec2   m_size;
        };
    }
}
