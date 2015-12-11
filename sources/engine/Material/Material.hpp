#ifndef     __MATERIAL_HPP__
# define    __MATERIAL_HPP__

#include    <glm/glm.hpp>
#include    <memory>

#include    "ShaderProgram.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to represent a material which a gameobject should be drawed with.
        ///
        class   Material
        {
            public:
                ///
                /// \brief Default constructor
                ///
                Material(void);

                ///
                /// \brief Destructor
                ///
                ~Material(void);

            public:

                ///
                /// \brief Getter for the color attribute.
                /// \return the color.
                ///
                const glm::vec3 &GetColor(void) const
                {
                    return this->_color;
                }

                ///
                /// \brief Getter for the shader program attribute.
                ///
                const std::shared_ptr<ShaderProgram>    &GetShaderProgram(void) const
                {
                    return this->_shaderProgram;
                }

            public:
                ///
                /// \brief Setter for the color attribute.
                ///
                void        SetColor(const glm::vec3 &color)
                {
                     this->_color = color;
                }

                ///
                /// \brief Setter for the shader program attribute.
                ///
                void        SetShaderProgram(const std::shared_ptr<ShaderProgram> &shaderProgram)
                {
                     this->_shaderProgram = shaderProgram;
                }

            private:
                ///
                /// \brief the color attribute is used to store the color of the material.
                ///
                glm::vec3                       _color;

                ///
                /// \brief The program shader used to render this material.
                ///
                std::shared_ptr<ShaderProgram>  _shaderProgram;

                /// TODO add texture
                // Texture
        };
    }
}

#endif /* !__MATERIAL_HPP__ */
