
#ifndef     __SHADER_PROGRAM_MANAGER_HPP__
# define    __SHADER_PROGRAM_MANAGER_HPP__

#include        <map>
#include        <memory>

#include        "ShaderProgram.hpp"
#include        "ShaderProgramNames.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to store / create and retrieve every shader program used in the engine.
        ///
        class       ShaderProgramManager
        {
            public:
                ///
                /// \brief This method is used to retrieve a shader program from its name.
                ///
                static const std::shared_ptr<ShaderProgram>     &Get(const ShaderProgramName &name);


            private:
                ///
                /// \brief This method is used internally to create a new shader program from the shader program name.
                ///
                static std::shared_ptr<ShaderProgram>   CreateShaderProgram(const ShaderProgramName &name);

            protected:
                ///
                /// \brief This attribute is used to store all shader program.
                ///
                static std::map<ShaderProgramName, std::shared_ptr<ShaderProgram>>  _shaderPrograms;
        };
    }
}

#endif /* !__SHADER_PROGRAM_MANAGER_HPP__ */
