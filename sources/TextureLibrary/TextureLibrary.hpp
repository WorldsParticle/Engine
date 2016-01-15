///
/// \file TextureLibrary.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:35:21
///
/// \version 1.0.1
///

#ifndef     __TEXTURE_LIBRARY_HPP__
# define    __TEXTURE_LIBRARY_HPP__

#include    "Library.hpp"
#include    "Texture.hpp"

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

#endif /* !__TEXTURE_LIBRARY_HPP__ */
