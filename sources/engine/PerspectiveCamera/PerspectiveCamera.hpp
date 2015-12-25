#ifndef     __PERSPECTIVE_CAMERA_HPP__
# define    __PERSPECTIVE_CAMERA_HPP__

#include    "Camera.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class defined a perspective camera. This class implement the abstract class Camera.
        ///
        /// TODO Je pense que c'est pas nécessaire de faire deux classes pour une perspective & une orthographique.
        ///
        class       PerspectiveCamera : public Camera
        {
            public:
                ///
                /// \brief Default constructor.
                ///
                PerspectiveCamera(void);

                ///
                /// \brief Copy constructor.
                ///
                PerspectiveCamera(const PerspectiveCamera &other);

                ///
                /// \brief Move constructor.
                ///
                PerspectiveCamera(PerspectiveCamera &&other);

                ///
                /// \brief Destructor.
                ///
                ~PerspectiveCamera(void);

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                PerspectiveCamera   &operator=(const PerspectiveCamera &other);

                ///
                /// \brief Move assignment operator.
                ///
                PerspectiveCamera   &operator=(PerspectiveCamera &&other);

            public:
                ///
                /// \brief this method clone the object.
                ///
                PerspectiveCamera   *clone(void) const;

            private:
                ///
                /// \brief The projection matrix of the perspective camera.
                ///
                glm::mat4       projection;

                ///
                /// \brief The view matrix of the perspective camera.
                ///
                glm::mat4       view;
        };
    }
}

#endif /* !__PERSPECTIVE_CAMERA_HPP__ */
