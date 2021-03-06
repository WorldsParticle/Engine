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

#include    <assimp/anim.h>
#include    <string>

#include    "Engine/Configuration.hpp"

namespace   Engine
{
    class ENGINE_EXPORTS Animation final
    {
        public:
            ///
            /// \brief Default constructor. Create an empty animation.
            ///
            Animation(void);

            ///
            /// \brief Construct an animation from an assimp animation.
            ///
            Animation(const aiAnimation *assimpAnimation); // TODO GSL NOT NULL

            ///
            /// \brief Copy constructor.
            ///
            Animation(const Animation &other);

            ///
            /// \brief Move constructor.
            ///
            Animation(Animation &&other) noexcept;

            ///
            /// \brief Destructor.
            ///
            virtual ~Animation(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Animation   &operator=(const Animation &other);

            ///
            /// \brief Move assignment operator.
            ///
            Animation   &operator=(Animation &&other) noexcept;

        public:
            ///
            /// \brief Return the name of the animation.
            ///
            const std::string   &name(void) const;

        private:
            ///
            /// \brief The name of the animation.
            ///
            std::string     m_name;
    };
}
