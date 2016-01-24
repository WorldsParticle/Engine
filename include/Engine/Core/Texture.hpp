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

#ifndef     __ENGINE_TEXTURE_HPP__
# define    __ENGINE_TEXTURE_HPP__

#include    <assimp/texture.h>

namespace   Engine
{
    class       Texture
    {
        public:
            ///
            /// \brief Default constructor. create an empty texture.
            ///
            Texture(void);

            ///
            /// \brief Construct a texture from an assimp texture.
            ///
            Texture(const aiTexture *assimpTexture);

            ///
            /// \brief Copy constructor.
            ///
            Texture(const Texture &other) = default;

            ///
            /// \brief Move constructor.
            ///
            Texture(Texture &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            virtual ~Texture(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Texture     &operator=(const Texture &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            Texture     &operator=(Texture &&other) noexcept = default;
    };
}

#endif /* !__ENGINE_TEXTURE_HPP__ */
