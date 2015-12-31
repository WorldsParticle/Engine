
#ifndef     __SHADER_PROGRAM_LIBRARY_HPP__
# define    __SHADER_PROGRAM_LIBRARY_HPP__

#include    "Library.hpp"
#include    "ShaderProgram.hpp"
#include    "ShaderProgramNames.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to store / create and retrieve every shader program used in the engine.
        ///
        class       ShaderProgramLibrary : public Library<ShaderProgram>
        {
            public:
                ///
                /// \brief Default constructor. This constructor is reponsible for the initialisation of all shader program.
                ///
                ShaderProgramLibrary(void);

                ///
                /// \brief Copy constructor.
                ///
                ShaderProgramLibrary(const ShaderProgramLibrary &other) = default;

                ///
                /// \brief Move constructor.
                ///
                ShaderProgramLibrary(ShaderProgramLibrary &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                ~ShaderProgramLibrary(void);

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                ShaderProgramLibrary    &operator=(const ShaderProgramLibrary &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                ShaderProgramLibrary    &operator=(ShaderProgramLibrary &&other) noexcept = default;

            private:
                ///
                /// \brief This attribute is the library used by the shader program library
                /// to contains every shaders.
                ///
                ShaderLibrary           shaders;
        };
    }
}

#endif /* !__SHADER_PROGRAM_MANAGER_HPP__ */
