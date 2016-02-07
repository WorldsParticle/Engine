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

    namespace   Event
    {
        class       Event;
        class       KeyPressed;
    }
    class   KeyPressed;

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
            ///
            /// \brief Callback call when a key is pressed.
            ///
            void    on_key_pressed(const Event::Event &event);

            void    on_z_pressed(const Event::KeyPressed &event);
            void    on_q_pressed(const Event::KeyPressed &event);
            void    on_s_pressed(const Event::KeyPressed &event);
            void    on_d_pressed(const Event::KeyPressed &event);

        protected:
            ///
            /// \brief the speed of the camera.
            ///
            float       m_speed;
    };
}

#endif // !__ENGINE_CORE_FREEFLYCAMERA_HPP__
