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

#ifndef     __ENGINE_MATERIAL_HPP__
# define    __ENGINE_MATERIAL_HPP__

#include    <memory>
#include    <glm/glm.hpp>
#include    <assimp/material.h>

#include    "Engine/Core/Texture.hpp"
#include    "Engine/Core/TextureLibrary.hpp"
#include    "Engine/Configuration.hpp"

namespace   Engine
{
    class   ShaderProgram;
    class   ShaderProgramLibrary;
    ///
    /// \brief This class is used to represent a material which, applied to a mesh, determine how the mesh should be rendered.
    ///
    class ENGINE_EXPORTS Material final
    {
        public:
            ///
            /// \brief Default constructor
            ///
            Material(const std::shared_ptr<ShaderProgram> &shaderprogram);

            ///
            /// \brief Construct a material from an assimp material.
            ///
            Material(const aiMaterial *assimpMaterial,
                    const std::shared_ptr<ShaderProgram> &shaderprogram,
		    const TextureLibrary &texLib);

            ///
            /// \brief Copy constructor.
            ///
            Material(const Material &other) = default;

            ///
            /// \brief Move constructor.
            ///
            Material(Material &&other) noexcept = default;

            ///
            /// \brief Destructor
            ///
            virtual ~Material(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Material    &operator=(const Material &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            Material    &operator=(Material &&other) noexcept = default;

        public:
            ///
            /// \brief Bind the material in the graphic pipeline.
            ///
            void        bind(void) const;

            ///
            /// \brief Unbind the material off the graphic pipeline.
            ///
            void        unbind(void) const;

        public:
            ///
            /// \brief Getter for the name attribute.
            /// \return the name of the material.
            ///
            const std::string       &getName(void) const;

            ///
            /// \brief Getter for the shader program used by the material.
            /// \return the shader program.
            ///
            const std::shared_ptr<ShaderProgram>    &getShaderProgram(void) const;

        public:
            ///
            /// \brief Setter for the name attribute.
            ///
            void    setName(const std::string &name);

        private:
            ///
            /// \brief The name of the material.
            ///
            std::string     m_name;

            ///
            /// \brief The shaderprogram used with this material.
            ///
            std::shared_ptr<ShaderProgram>  m_shaderprogram;

            ///
            /// \brief The ids of the textures of the material
            ///
	    Texture			    *m_texture;
    };
}

#endif /* !__ENGINE_MATERIAL_HPP__ */
