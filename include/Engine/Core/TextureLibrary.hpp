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

#include    <GL/gl.h>
#include    <string>
#include    <map>
#include    "Engine/Core/Library.hpp"
#include    "Engine/Core/Texture.hpp"
#include    "Engine/Core/AssimpScene.hpp"

namespace   Engine
{
    class       TextureLibrary : public Library<Texture *>
    {
	private:
	    std::map<std::string, Texture*> _textureMap;

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
            /// \brief Construct the library from the assimp scene
            ///
	    TextureLibrary(const AssimpScene &assimpScene);

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

	public:
            ///
            /// \brief Bind the texture corresponding to the name passed as parameter if it exist and is loaded
            ///
	    void BindTexture(const std::string &name);

            ///
            /// \brief Find the texture corresponding to the name passed as parameter if it exist and is loaded
            ///
	    Texture *FindTexture(const std::string &name) const;
    };
}
