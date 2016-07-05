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
#include    <glm/glm.hpp>

#include    "Engine/Configuration.hpp"
#include <Engine/Core/Material.hpp>

namespace   Engine
{

    class   ShaderProgram;
    class   ShaderProgramLibrary;
    class   Texture;
    class   TextureLibrary;

    ///
    /// \brief This class is used to represent a NuagesMaterial which, applied to a mesh, determine how the mesh should be rendered.
    ///
    class ENGINE_EXPORTS NuagesMaterial : public Material
    {
        public:
            ///
            /// \brief Default constructor
            ///
            NuagesMaterial(const std::shared_ptr<ShaderProgram> &shaderprogram);

            ///
            /// \brief Copy constructor.
            ///
            NuagesMaterial(const NuagesMaterial &other) = default;

            ///
            /// \brief Move constructor.
            ///
            NuagesMaterial(NuagesMaterial &&other) noexcept = default;

            ///
            /// \brief Destructor
            ///
            virtual ~NuagesMaterial(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            NuagesMaterial    &operator=(const NuagesMaterial &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            NuagesMaterial    &operator=(NuagesMaterial &&other) noexcept = default;

        public:
            ///
            /// \brief Bind the NuagesMaterial in the graphic pipeline.
            ///
            virtual void        bind(void) const override;

    private:
        ///
        /// \brief The name of the material
        ///
        std::string     m_name;

        ///
        /// \brief The shaderprogram used with this material.
        ///
        std::shared_ptr<ShaderProgram>  m_shaderprogram;

        ///
        /// \brief The ids of the textures of the material
        ///
        Texture     *m_texture;
    };
}
