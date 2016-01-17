///
/// \file AnimationLibrary.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 22:35:25
///
/// \version 1.0.7
///

#ifndef     __ENGINE_ANIMATION_LIBRARY_HPP__
# define    __ENGINE_ANIMATION_LIBRARY_HPP__

#include    <assimp/anim.h>

#include    "Engine/Library.hpp"
#include    "Engine/Animation.hpp"

namespace   Engine
{
    ///
    /// \brief This class is used to contains every animation available in a scene.
    ///
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

#endif /* !__ENGINE_ANIMATION_LIBRARY_HPP__ */
