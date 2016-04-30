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
// with this program; If not, see <http://www.gnu.Nuagorg/licenses/>.
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
    /// \brief This class is used to represent a LightningBoltMaterial which, applied to a mesh, determine how the mesh should be rendered.
    ///
    class ENGINE_EXPORTS LightningBoltMaterial : public Material
    {
        public:
            ///
            /// \brief Default constructor
            ///
            LightningBoltMaterial(const std::shared_ptr<ShaderProgram> &shaderprogram);

            ///
            /// \brief Copy constructor.
            ///
            LightningBoltMaterial(const LightningBoltMaterial &other) = default;

            ///
            /// \brief Move constructor.
            ///
            LightningBoltMaterial(LightningBoltMaterial &&other) noexcept = default;

            ///
            /// \brief Destructor
            ///
            virtual ~LightningBoltMaterial(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            LightningBoltMaterial    &operator=(const LightningBoltMaterial &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            LightningBoltMaterial    &operator=(LightningBoltMaterial &&other) noexcept = default;

        public:
            ///
            /// \brief Bind the LightningBoltMaterial in the graphic pipeline.
            ///
            virtual void        bind(void) const;

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
