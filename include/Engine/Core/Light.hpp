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

#ifndef     __ENGINE_LIGHT_HPP__
# define    __ENGINE_LIGHT_HPP__

#include    <string>
#include    <assimp/light.h>

#include    "Engine/Core/Entity.hpp"

namespace Engine
{

    ///
    /// \brief This class is used to represent a light in the 3d world.
    ///
    /// TODO : implement the class.
    ///
    class Light : public Entity
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            Light(SceneGraphNode *node);

            ///
            /// \brief Construct a light from an assimp light.
            ///
            Light(const aiLight *assimpLight, SceneGraphNode *node);

            ///
            /// \brief Copy constructor.
            ///
            Light(const Light &other) = default;

            ///
            /// \brief Move constructor.
            ///
            Light(Light &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            virtual ~Light(void) noexcept;

        public:
            ///
            /// \brief Copy assigment operator.
            ///
            Light   &operator=(const Light &other) = default;

            ///
            /// \brief Move assigment operator.
            ///
            Light   &operator=(Light &&other) noexcept = default;

        public:
            ///
            /// \brief This method clone the light.
            ///
            virtual Light   *clone(void) const;

            ///
            /// \brief This method is used to update the light.
            ///
            void            update(void);

        public:
            ///
            /// \brief Getter for the light name.
            ///
            const std::string   &getName(void) const;

        private:
            ///
            /// \brief The name of the light.
            ///
            std::string         name;

    };
}

#endif /* !__ENGINE_LIGHT_HPP__ */
