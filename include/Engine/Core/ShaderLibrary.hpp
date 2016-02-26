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

#include    <memory>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Library.hpp"
#include    "Engine/Core/Shader.hpp"
#include    "Engine/Core/ShaderNames.hpp"

namespace   Engine
{
    ///
    /// \brief This class is used to store / create and retrieve every shader used in the engine.
    ///
    class ENGINE_EXPORTS ShaderLibrary : public Library<std::shared_ptr<Shader>>
    {
        public:
            ///
            /// \brief The constructor is responsible for the initialisation of all shaders.
            ///
            ShaderLibrary(void);

            ///
            /// \brief Copy constructor.
            ///
            ShaderLibrary(const ShaderLibrary &other) = default;

            ///
            /// \brief Move constructor.
            ///
            ShaderLibrary(ShaderLibrary &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            virtual ~ShaderLibrary(void);

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            ShaderLibrary   &operator=(const ShaderLibrary &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            ShaderLibrary   &operator=(ShaderLibrary &&other) noexcept = default;

    };
}
