#ifndef     __SHADER_PROGRAM_HPP__
# define    __SHADER_PROGRAM_HPP__

#include    <glm/glm.hpp>
#include    <memory>

#include    "Shader.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to abstract a program shader.
        ///
        class       ShaderProgram
        {
            public:
                ///
                /// \brief Default constructor
                ///
                ShaderProgram(void);

                ///
                /// \brief Destructor
                ///
                ~ShaderProgram(void);

            public:
                ///
                /// \brief This operator is used to push a shader into the program shader.
                ///
                ShaderProgram   &operator<<(const std::shared_ptr<Shader> &shader);

            public:
                ///
                /// \brief This method is used to push a shader into the program shader.
                ///
                void            AddShader(const std::shared_ptr<Shader> &shader);

            public:

                ///
                /// \brief This method is used to link the program shader.
                /// \return true if the link succeed, false otherwise.
                ///
                bool    Link(void);

                ///
                /// \brief This method is used to bind the program shader on the graphic pipeline.
                ///
                void    Bind(void) const;

                ///
                /// \brief This method is used to unbind the program shader on the graphic pipeline.
                ///
                void    Unbind(void) const;

            public:
                ///
                /// \brief This method is used to know if the shader program have been already compiled.
                ///
                bool    IsLinked(void)
                {
                    return this->_isLinked;
                }

            public:
                ///
                /// \brief This method can be used to set a mat4 uniform.
                ///
                void    SetUniform(const std::string &name, const glm::mat4 &matrix) const;

                /// TODO add others set uniform

            protected:
                ///
                /// \brief This attribute is used to store the program id.
                ///
                unsigned int                _programId;

                ///
                /// \brief This attribute is used to know if the shader program have been compiled.
                ///
                bool                        _isLinked;

        };
    }
}

#endif /* !__SHADER_PROGRAM_HPP__ */
