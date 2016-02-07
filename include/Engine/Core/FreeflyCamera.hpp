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

#ifndef     __ENGINE_CORE_FREEFLYCAMERA_HPP__
# define    __ENGINE_CORE_FREEFLYCAMERA_HPP__

#include    "Engine/Core/PerspectiveCamera.hpp"

namespace   Engine
{

    class    Event;

    ///
    /// \brief A basic implementation of a freefly camera.
    ///
    class       FreeflyCamera : public PerspectiveCamera
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            FreeflyCamera(SceneGraphNode *node);

            ///
            /// \brief Destructor.
            ///
            ~FreeflyCamera(void);

        public:
            void    test_input(const Event &event);
    };
}

#endif // !__ENGINE_CORE_FREEFLYCAMERA_HPP__
