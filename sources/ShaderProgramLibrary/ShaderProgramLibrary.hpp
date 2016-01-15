///
/// \file ShaderProgramLibrary.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:34:34
///
/// \version 1.0.1
///

#ifndef     __SHADER_PROGRAM_LIBRARY_HPP__
# define    __SHADER_PROGRAM_LIBRARY_HPP__

#include    <memory>

#include    "Library.hpp"
#include    "ShaderProgram.hpp"
#include    "ShaderProgramNames.hpp"
#include    "ShaderLibrary.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to store / create and retrieve every shader program used in the engine.
        ///
        /// We must use a shared_ptr because of the non copiability of a ShaderProgram.
        ///
        class       ShaderProgramLibrary : public Library<std::shared_ptr<ShaderProgram>>
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
