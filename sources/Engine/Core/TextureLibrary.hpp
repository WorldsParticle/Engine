///
/// \file TextureLibrary.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:51:18
///
/// \version 1.0.8
///

#ifndef     __ENGINE_TEXTURE_LIBRARY_HPP__
# define    __ENGINE_TEXTURE_LIBRARY_HPP__

#include    "Engine/Core/Library.hpp"
#include    "Engine/Core/Texture.hpp"

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

#endif /* !__ENGINE_TEXTURE_LIBRARY_HPP__ */
