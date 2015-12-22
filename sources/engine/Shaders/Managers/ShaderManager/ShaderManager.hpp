
#ifndef         __SHADER_MANAGER_HPP__
# define        __SHADER_MANAGER_HPP__

#include    <memory>
#include    <map>

#include    "Shader.hpp"
#include    "ShaderNames.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to store / create and retrieve every shader used in the engine.
        ///
        class       ShaderManager
        {

            public:
                ///
                /// \brief This method should be used to get a shader.
                /// \param name The shader program name requested.
                ///
                static const std::shared_ptr<Shader>    &Get(const ShaderName &name);

            private:

                ///
                /// \brief This method is internaly used to create a new shader.
                ///
                static std::shared_ptr<Shader>  CreateShader(const ShaderName &name);

            protected:

                ///
                /// \brief This attribute is used to contains the shaders.
                ///
                static std::map<ShaderName, std::shared_ptr<Shader>>    _shaders;

        };
    }
}

#endif /* !__SHADER_MANAGER_HPP__ */
