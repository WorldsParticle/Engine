#ifndef     __SHADER_MANAGER_HPP__
# define    __SHADER_MANAGER_HPP__

#include    "Shader.hpp"
#include    "ShaderNames.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to store / create and retrieve every shader used in the engine.
        ///
        class       ShaderLibrary : public Library<Shader>
        {
            public:
                ///
                /// \brief The constructor is responsible for the initialisation of all shaders.
                ///
                ShaderLibrary(void);

                ///
                /// \brief Copy constructor.
                ///
                ShaderLibrary(const ShaderLibrary &other) = default;

                ///
                /// \brief Move constructor.
                ///
                ShaderLibrary(ShaderLibrary &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                ~Shader(void);

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                ShaderLibrary   &operator=(const ShaderLibrary &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                ShaderLibrary   &operator=(ShaderLibrary &&other) noexcept = default;

        };
    }
}

#endif /* !__SHADER_MANAGER_HPP__ */
