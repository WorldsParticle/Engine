#ifndef     __TEXTURE_LIBRARY_HPP__
# define    __TEXTURE_LIBRARY_HPP__

#include    "Library.hpp"
#include    "Texture.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        class       TextureLibrary : public Library<Texture>
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                TextureLibrary(void);

                ///
                /// \brief Copy constructor.
                ///
                TextureLibrary(const TextureLibrary &other) = default;

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
                TextureLibrary  &operator=(const TextureLibrary &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                TextureLibrary  &operator=(TextureLibrary &&other) noexcept = default;

        };
    }
}

#endif /* !__TEXTURE_LIBRARY_HPP__ */
