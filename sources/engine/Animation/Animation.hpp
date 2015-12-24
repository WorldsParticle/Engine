#ifndef     __ANIMATION_HPP__
# define    __ANIMATION_HPP__

#include    <assimp/anim.h>

namespace   WorldParticles
{
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
                Animation(const aiAnimation *assimpAnimation);

                ///
                /// \brief Copy constructor.
                ///
                Animation(const Animation &other);

                ///
                /// \brief Move constructor.
                ///
                Animation(Animation &&other);

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
                Animation   &operator=(Animation &&other);
        };
    }
}

#endif /* !__ANIMATION_HPP__ */