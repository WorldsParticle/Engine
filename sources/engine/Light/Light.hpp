#ifndef         __LIGHT_HPP__
# define        __LIGHT_HPP__

#include    "Transform.hpp"

namespace WorldParticles
{
    namespace Engine
    {
        ///
        /// \brief This class is used to represent a light in the 3d world.
        ///
        /// TODO : implement the class.
        ///
        class Light
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                Light(void);

                ///
                /// \brief Construct a light from an assimp light.
                ///
                Light(const aiLight *assimpLight);

                ///
                /// \brief Copy constructor.
                ///
                Light(const Light &other);

                ///
                /// \brief Move constructor.
                ///
                Light(Light &&other);

                ///
                /// \brief Destructor.
                ///
                virtual ~Light(void);

            public:
                ///
                /// \brief Copy assigment operator.
                ///
                Light   &operator=(const Light &other);

                ///
                /// \brief Move assigment operator.
                ///
                Light   &operator=(Light &&other);

            private:
                ///
                /// \brief The transform of the light.
                ///
                Transform       transform;

        };
    }
}

#endif /* !__LIGHT_HPP__ */
