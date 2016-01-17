///
/// \file Animation.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 22:33:28
///
/// \version 1.0.4
///

#ifndef     __ENGINE_ANIMATION_HPP__
# define    __ENGINE_ANIMATION_HPP__

#include    <assimp/anim.h>
#include    <string>

namespace   Engine
{
    class       Animation
    {
        public:
            ///
            /// \brief Default constructor. Create an empty animation.
            ///
            Animation(void);

            ///
            /// \brief Construct an animation from an assimp animation.
            ///
            Animation(const aiAnimation *assimpAnimation); // TODO GSL NOT NULL

            ///
            /// \brief Copy constructor.
            ///
            Animation(const Animation &other);

            ///
            /// \brief Move constructor.
            ///
            Animation(Animation &&other) noexcept;

            ///
            /// \brief Destructor.
            ///
            virtual ~Animation(void) noexcept;

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            Animation   &operator=(const Animation &other);

            ///
            /// \brief Move assignment operator.
            ///
            Animation   &operator=(Animation &&other) noexcept;

        private:
            ///
            /// \brief The name of the animation.
            ///
            std::string     name;
    };
}

#endif /* !__ENGINE_ANIMATION_HPP__ */
