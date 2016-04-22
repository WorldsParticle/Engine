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

#include    <assimp/texture.h>
#include    <assimp/scene.h>
#include    <string>
#include    <map>

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
            /// \brief Construct a texture from its path (non embedded textures)
            ///
            Texture(const std::string &texture_name);

            ///
            /// \brief Construct a texture from an assimp texture. (embedded textures)
            ///
            Texture(const aiTexture *ai_texture);

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

        public:
            ///
            /// \brief bind the texture in the graphic pipeline.
            ///
            void        bind(void);

            ///
            /// \brief unbind the texture from the graphic pipeline.
            ///
            void        unbind(void);

        private:
            ///
            /// \brief This attribute is the name of the texture
            /// (its path is relative to the file loaded)
            ///
            std::string     m_name;

            ///
            /// \brief This attribute is the id of the texture
            ///
            unsigned int    m_id;
    };
}
