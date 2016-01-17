///
/// \file ShaderLibrary.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:02:03
///
/// \version 1.0.5
///

#ifndef     __ENGINE_SHADER_MANAGER_HPP__
# define    __ENGINE_SHADER_MANAGER_HPP__

#include    <memory>

#include    <Engine/Library.hpp>
#include    <Engine/Shader.hpp>
#include    <Engine/ShaderNames.hpp>

namespace   Engine
{
    ///
    /// \brief This class is used to store / create and retrieve every shader used in the engine.
    ///
    class       ShaderLibrary : public Library<std::shared_ptr<Shader>>
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
            virtual ~ShaderLibrary(void);

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

#endif /* !__ENGINE_SHADER_MANAGER_HPP__ */
