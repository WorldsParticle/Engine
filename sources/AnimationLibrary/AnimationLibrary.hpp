///
/// \file AnimationLibrary.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Fri, 15 Jan 2016 13:28:03
///
/// \version 1.0.1
///

#ifndef     __ANIMATION_LIBRARY_HPP__
# define    __ANIMATION_LIBRARY_HPP__

#include    <assimp/anim.h>

#include    "Library.hpp"
#include    "Animation.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        class       AnimationLibrary : public Library<Animation *>
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                AnimationLibrary(void);

                ///
                /// \brief Construct the library from an array of assimp animations of size 'size'
                ///
                /// TODO GSL array_view
                ///
                AnimationLibrary(aiAnimation **assimpAnimations, unsigned int size);

                ///
                /// \brief Copy constructor.
                ///
                AnimationLibrary(const AnimationLibrary &other);

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
                virtual AnimationLibrary    &operator=(const AnimationLibrary &other);

                ///
                /// \brief Move assignment operator.
                ///
                virtual AnimationLibrary    &operator=(AnimationLibrary &&other) noexcept = default;

        };
    }
}

#endif /* !__ANIMATION_LIBRARY_HPP__ */
