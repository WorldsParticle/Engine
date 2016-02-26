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
#include    <assimp/vector3.h>
#include    <assimp/matrix4x4.h>

#include    "Engine/Configuration.hpp"

namespace   Engine
{
    ///
    /// \brief The Transform class is used to represent an object transformation in space. (like position, rotation and scale of the object)
    ///
    /// This class should be updated with quaternion support.
    ///
    class ENGINE_EXPORTS Transform
    {
        public:
            ///
            /// \brief Default constructor
            ///
            Transform(void);

            ///
            /// \brief Construct a transform from an assimp matrix4x4.
            ///
            Transform(const aiMatrix4x4 &assimpTransformation);

            ///
            /// \brief Copy constructor.
            ///
            Transform(const Transform &other) = default;

            ///
            /// \brief Move constructor.
            ///
            Transform(Transform &&other) noexcept = default;

            ///
            /// \brief Destructor
            ///
            virtual ~Transform(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Transform   &operator=(const Transform &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            Transform   &operator=(Transform &&other) noexcept = default;

        public:
            ///
            /// \brief Get the matrix of the transform.
            ///
            const glm::mat4 &getMatrix(void) const;

            /// TODO implementation function like "rotate" "translate"...

        public:
            ///
            /// \brief This method rotate the transform.
            ///
            void    rotate(const glm::vec3 &rotation);

        protected:
            ///
            /// \brief This matrix represent the actual state of the transform.
            ///
            glm::mat4       m_matrix;
    };
}
