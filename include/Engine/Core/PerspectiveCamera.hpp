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

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Camera.hpp"

namespace   Engine
{
    namespace   Event
    {
        class       Event;
    }

    ///
    /// \brief This class defined a perspective camera. This class implement the abstract class Camera.
    ///
    /// TODO Je pense que c'est pas nécessaire de faire deux classes pour une perspective & une orthographique.
    ///
    class ENGINE_EXPORTS PerspectiveCamera : public Camera
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            PerspectiveCamera(SceneGraphNode *node);

            ///
            /// \brief Construct a perspective camera from an assimp camera.
            ///
            PerspectiveCamera(const aiCamera *assimpCamera, SceneGraphNode *node);

            ///
            /// \brief Copy constructor.
            ///
            PerspectiveCamera(const PerspectiveCamera &other) = default;

            ///
            /// \brief Move constructor.
            ///
            PerspectiveCamera(PerspectiveCamera &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            ~PerspectiveCamera(void);

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            PerspectiveCamera   &operator=(const PerspectiveCamera &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            PerspectiveCamera   &operator=(PerspectiveCamera &&other) noexcept = default;

        public:
            ///
            /// \brief this method clone the perspective camera.
            ///
            virtual PerspectiveCamera   *clone(void) const override;

            ///
            /// \brief This method is used to update the perspective camera.
            ///
            virtual void                update(void) override;

        public:
            ///
            /// \brief Getter for the camera projection matrix.
            ///
            const glm::mat4     &getProjection(void) const override;

            ///
            /// \brief Getter for the camera view matrix.
            ///
            const glm::mat4     &getView(void) const override;

        private:
            ///
            /// \brief Callback used when a resize event happen.
            ///
            void                on_resize_event(const Event::Event &event);

        protected:
            ///
            /// \brief The projection matrix of the perspective camera.
            ///
            glm::mat4       m_projection;

            ///
            /// \brief The view matrix of the perspective camera.
            ///
            glm::mat4       m_view;
    };
}
