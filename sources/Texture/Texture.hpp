///
/// \file Texture.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:35:07
///
/// \version 1.0.1
///

#ifndef     __TEXTURE_HPP__
# define    __TEXTURE_HPP__

#include    <assimp/texture.h>

namespace   WorldParticles
{
    namespace   Engine
    {
        class       Texture
        {
            public:
                ///
                /// \brief Default constructor. create an empty texture.
                ///
                Texture(void);

                ///
                /// \brief Construct a texture from an assimp texture.
                ///
                Texture(const aiTexture *assimpTexture);

                ///
                /// \brief Copy constructor.
                ///
                Texture(const Texture &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Texture(Texture &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                virtual ~Texture(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Texture     &operator=(const Texture &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                Texture     &operator=(Texture &&other) noexcept = default;
        };
    }
}

#endif /* !__TEXTURE_HPP__ */
