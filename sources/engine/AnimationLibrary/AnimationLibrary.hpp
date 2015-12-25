#ifndef     __ANIMATION_LIBRARY_HPP__
# define    __ANIMATION_LIBRARY_HPP__

#include    "Library.hpp"
#include    "Animation.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        class       AnimationLibrary : Library<Animation>
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                AnimationLibrary(void);

                ///
                /// \brief Copy constructor.
                ///
                AnimationLibrary(const AnimationLibrary &other) = default;

                ///
                /// \brief Move constructor
                ///
                AnimationLibrary(AnimationLibrary &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                virtual ~AnimationLibrary(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                AnimationLibrary    &operator=(const AnimationLibrary &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                AnimationLibrary    &operator=(AnimationLibrary &&other) noexcept = default;

        };
    }
}

#endif /* !__ANIMATION_LIBRARY_HPP__ */
