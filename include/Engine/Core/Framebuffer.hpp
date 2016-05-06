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

#include    <glm/glm.hpp>
#include    <memory>

#include    "Engine/Configuration.hpp"


namespace   Engine
{
    ///
    /// \brief This class is used to encapsulate the opengl framebuffer
    ///
    class   ArrayObject;
    class   BufferObject;
    class   ShaderProgram;
    class   ShaderProgramLibrary;

    class ENGINE_EXPORTS Framebuffer
    {
	public:
            ///
            /// \brief Default constructor
            ///
	    Framebuffer(const ShaderProgramLibrary &shaderprograms, const glm::ivec2 &size);

            ///
            /// \brief Construct a camera from an assimp camera.
            ///
	    Framebuffer(const Framebuffer &);

            ///
            /// \brief Move constructor.
            ///
	    Framebuffer(Framebuffer &&) noexcept;

            ///
            /// \brief Destructor.
            ///
	    ~Framebuffer();

        public:
            ///
            /// \brief Copy assigment operator.
            ///
            Framebuffer &operator=(const Framebuffer &other);

            ///
            /// \brief Move assigment operator.
            ///
            Framebuffer &operator=(Framebuffer &&other) noexcept;

	public:
            ///
            /// \brief bind framebuffer (before drawing the objects in the scene)
            ///
	    void bind();

            ///
            /// \brief unbind framebuffer (after drawing the objects in the scene)
            ///
	    void unbind();

            ///
            /// \brief draw framebuffer
            ///
	    void draw();

	private:
            ///
            /// \brief bind the texture of the size of the framebuffer
            ///
	    void bindTexture();

            ///
            /// \brief create a texture of the size of the framebuffer
            ///
	    void createTexture();

	private:

            ///
            /// \brief The shader for the framebuffer
            ///
	    const std::shared_ptr<ShaderProgram>    m_shaderFramebuff;

            ///
            /// \brief The array object (a simple quad) to print the image (framebuffer) on the screen
            ///
            std::shared_ptr<ArrayObject>	    m_vao;

            ///
            /// \brief The buffer object (a simple quad) to print the image (framebuffer) on the screen
            ///
            std::shared_ptr<BufferObject>	    m_vbo;

            ///
            /// \brief The opengl framebuffer
            ///
	    unsigned int			    m_framebuffer;

            ///
            /// \brief A texture (color) of the size of the framebuffer
            ///
	    unsigned int			    m_textureColorbuffer;

            ///
            /// \brief The size of the framebuffer (and its texture).
	    ///
	    /// It correspond to the size of the viewport
            ///
            glm::ivec2				    m_size;
    };
}
