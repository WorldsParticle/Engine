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

#ifndef     __ENGINE_TEXTURE_LIBRARY_HPP__
# define    __ENGINE_TEXTURE_LIBRARY_HPP__

#include    "Engine/Core/Library.hpp"
#include    "Engine/Core/Texture.hpp"

namespace   Engine
{
    class       TextureLibrary : public Library<Texture *>
    {
        public:
            ///
            /// \brief Default constructor.
            ///
            TextureLibrary(void);

            ///
            /// \brief Construct the library from an array of assimp textures.
            ///
            /// TODO  GSL array_view
            ///
            TextureLibrary(aiTexture **assimpTextures, unsigned int size);

            ///
            /// \brief Copy constructor.
            ///
            TextureLibrary(const TextureLibrary &other);

            ///
            /// \brief Move constructor.
            ///
            TextureLibrary(TextureLibrary &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            virtual ~TextureLibrary(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            TextureLibrary  &operator=(const TextureLibrary &other);

            ///
            /// \brief Move assignment operator.
            ///
            TextureLibrary  &operator=(TextureLibrary &&other) noexcept = default;

    };
}

#endif /* !__ENGINE_TEXTURE_LIBRARY_HPP__ */
