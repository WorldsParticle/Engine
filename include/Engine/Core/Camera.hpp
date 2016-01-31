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

#ifndef     __ENGINE_CAMERA_HPP__
# define    __ENGINE_CAMERA_HPP__

#include    <string>
#include    <glm/glm.hpp>
#include    <assimp/camera.h>

#include    "Engine/Core/Entity.hpp"

// Windows compilation, windows...
#undef  near
#undef  far

namespace   Engine
{

    class   SceneGraphNode;

    ///
    /// \brief This class is used to store information about a basic camera in a 3D world.
    ///
    /// It is not a concrete implementation for a camera.
    ///
    class       Camera : public Entity
    {
        public:
            ///
            /// \brief This struct is used to store the clipping plane of the camera.
            ///
            struct  ClippingPlane
            {
                ///
                /// \brief Distance of the near clipping plane from the camera.
                ///
                float   near;

                ///
                /// \brief Distance of the far clipping plane from the camera.
                ///
                float   far;
            };

        public:
            ///
            /// \brief Default constructor
            ///
            Camera(SceneGraphNode *node);

            ///
            /// \brief Construct a camera from an assimp camera.
            ///
            Camera(const aiCamera *assimpCamera, SceneGraphNode *node); // TODO GSL NOT NULL

            ///
            /// \brief Copy constructor.
            ///
            Camera(const Camera &other) = default;

            ///
            /// \brief Move constructor.
            ///
            Camera(Camera &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            virtual ~Camera(void) noexcept;

        public:
            ///
            /// \brief Copy assigment operator.
            ///
            Camera  &operator=(const Camera &other) = default;

            ///
            /// \brief Move assigment operator.
            ///
            Camera  &operator=(Camera &&other) noexcept = default;

        public:
            ///
            /// \brief Getter for the camera projection matrix.
            ///
            virtual const glm::mat4     &getProjection(void) const = 0;

            ///
            /// \brief Getter for the camera view matrix.
            ///
            virtual const glm::mat4     &getView(void) const = 0;

        protected:
            ///
            /// \brief the clipping plane for the camera.
            ///
            ClippingPlane   m_clippingPlane;

            ///
            /// \brief Screen aspect ratio.
            ///
            float   m_aspect;

            ///
            /// \brief The field of view angle for the horizontal axis in radian.
            ///
            float   m_fov;

            ///
            /// \brief Up vector of the camera coordinate system relative to
            /// the coordinate space defined by the related node. (Entity::node);
            ///
            glm::vec3   m_up;

            ///
            /// \brief lookat vector of the camera coordinate system relative
            /// to the coordinate space defined by the related node. (Entity::node)
            ///
            glm::vec3   m_lookat;

            ///
            /// \brief Position of the camera relative to the coordinate space
            /// defined by the related node. (Entity::node)
            ///
            glm::vec3   m_position;
    };
}

#endif /* !__ENGINE_CAMERA_HPP__ */
