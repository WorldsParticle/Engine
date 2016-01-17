///
/// \file TextureLibrary.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 20:58:16
///
/// \version 1.0.4
///

#ifndef     __ENGINE_TEXTURE_LIBRARY_HPP__
# define    __ENGINE_TEXTURE_LIBRARY_HPP__

#include    <Engine/Library.hpp>
#include    <Engine/Texture.hpp>

namespace   WorldParticles
{
    namespace   Engine
    {
        class       TextureLibrary : public Library<Texture *>
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                TextureLibrary(void);

                ///
                /// \brief Construct the library from an array of assimp textures.
                ///
                /// TODO  GSL array_view
                ///
                TextureLibrary(aiTexture **assimpTextures, unsigned int size);

                ///
                /// \brief Copy constructor.
                ///
                TextureLibrary(const TextureLibrary &other);

                ///
                /// \brief Move constructor.
                ///
                TextureLibrary(TextureLibrary &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                virtual ~TextureLibrary(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                TextureLibrary  &operator=(const TextureLibrary &other);

                ///
                /// \brief Move assignment operator.
                ///
                TextureLibrary  &operator=(TextureLibrary &&other) noexcept = default;

        };
    }
}

#endif /* !__ENGINE_TEXTURE_LIBRARY_HPP__ */
