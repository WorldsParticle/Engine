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
                Texture(const Texture &other);

                ///
                /// \brief Move constructor.
                ///
                Texture(Texture &&other);

                ///
                /// \brief Destructor.
                ///
                virtual ~Texture(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Texture     &operator=(const Texture &other);

                ///
                /// \brief Move assignment operator.
                ///
                Texture     &operator=(Texture &&other);
        };
    }
}

#endif /* !__TEXTURE_HPP__ */
