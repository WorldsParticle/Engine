#ifndef     __SHADER_PROGRAM_HPP__
# define    __SHADER_PROGRAM_HPP__

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
                /// \brief This method is used to compile the program shader.
                /// \return true if the compilation succeed, false otherwise.
                ///
                bool    Compile(void);

                ///
                /// \brief This method is used to bind the program shader to use it in the graphic pipeline.
                ///
                void    Bind(void);

            public:
                ///
                /// \brief This method is used to know if the shader program have been already compiled.
                ///
                bool    IsCompiled(void)
                {
                    return this->_isCompiled;
                }

                ///
                /// \brief This method is used to know if the shader program already contains a vertex shader.
                ///
                bool    HasVertexShader(void)
                {
                    return this->_vertexShaderIsPresent;
                }

                ///
                /// \brief This method is used to know if the shader program already contains a fragment shader.
                ///
                bool    HasFragmentShader(void)
                {
                    return this->_fragmentShaderIsPresent;
                }

                ///
                /// \brief This method is used to know if the shader program already contains a geometry shader.
                ///
                bool    HasGeometryShader(void)
                {
                    return this->_geometryShaderIsPresent;
                }

            protected:
                ///
                /// \brief This attribute is used to know if the shader program have been compiled.
                ///
                bool     _isCompiled;

                ///
                /// \brief This attribute is used to know if the shader program already have a vertex shader.
                ///
                bool    _vertexShaderIsPresent;

                ///
                /// \brief This attribute is used to know if the shader program already have a fragment shader.
                ///
                bool    _fragmentShaderIsPresent;

                ///
                /// \brief This attribute is used to know if the shader program already have a geometry shader.
                ///
                bool    _geometryShaderIsPresent;

        };
    }
}

#endif /* !__SHADER_PROGRAM_HPP__ */
