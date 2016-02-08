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

#ifndef     __ENGINE_SHADER_PROGRAM_LIBRARY_HPP__
# define    __ENGINE_SHADER_PROGRAM_LIBRARY_HPP__

#include    <memory>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Library.hpp"
#include    "Engine/Core/ShaderProgram.hpp"
#include    "Engine/Core/ShaderProgramNames.hpp"
#include    "Engine/Core/ShaderLibrary.hpp"

namespace   Engine
{
    ///
    /// \brief This class is used to store / create and retrieve every shader program used in the engine.
    ///
    /// We must use a shared_ptr because of the non copiability of a ShaderProgram.
    ///
    class ENGINE_EXPORTS ShaderProgramLibrary : public Library<std::shared_ptr<ShaderProgram>>
    {
        public:
            ///
            /// \brief Default constructor. This constructor is reponsible for the initialisation of all shader program.
            ///
            ShaderProgramLibrary(void);

            ///
            /// \brief Copy constructor.
            ///
            ShaderProgramLibrary(const ShaderProgramLibrary &other) = default;

            ///
            /// \brief Move constructor.
            ///
            ShaderProgramLibrary(ShaderProgramLibrary &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            ~ShaderProgramLibrary(void);

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            ShaderProgramLibrary    &operator=(const ShaderProgramLibrary &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            ShaderProgramLibrary    &operator=(ShaderProgramLibrary &&other) noexcept = default;

        private:
            ///
            /// \brief This attribute is the library used by the shader program library
            /// to contains every shaders.
            ///
            ShaderLibrary           m_shaders;
    };
}

#endif /* !__ENGINE_SHADER_PROGRAM_MANAGER_HPP__ */
