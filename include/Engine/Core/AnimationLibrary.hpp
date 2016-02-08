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

#ifndef     __ENGINE_ANIMATION_LIBRARY_HPP__
# define    __ENGINE_ANIMATION_LIBRARY_HPP__

#include    <assimp/anim.h>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Library.hpp"
#include    "Engine/Core/Animation.hpp"

namespace   Engine
{
    ///
    /// \brief This class is used to contains every animation available in a scene.
    ///
    class ENGINE_EXPORTS AnimationLibrary : public Library<Animation *>
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            AnimationLibrary(void);

            ///
            /// \brief Construct the library from an array of assimp animations of size 'size'
            ///
            /// TODO GSL array_view
            ///
            AnimationLibrary(aiAnimation **assimpAnimations, unsigned int size);

            ///
            /// \brief Copy constructor.
            ///
            AnimationLibrary(const AnimationLibrary &other);

            ///
            /// \brief Move constructor
            ///
            AnimationLibrary(AnimationLibrary &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            virtual ~AnimationLibrary(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            virtual AnimationLibrary    &operator=(const AnimationLibrary &other);

            ///
            /// \brief Move assignment operator.
            ///
            virtual AnimationLibrary    &operator=(AnimationLibrary &&other) noexcept = default;

    };
}

#endif /* !__ENGINE_ANIMATION_LIBRARY_HPP__ */
