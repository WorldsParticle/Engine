#ifndef     __CAMERA_HPP__
# define    __CAMERA_HPP__

#include    <glm/glm.hpp>

#include    "Entity.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to store information about a basic camera in a 3D world.
        ///
        /// It is not a concrete implementation for a camera.
        ///
        class       Camera : public Entity
        {
            public:
                ///
                /// \brief This struct is used to store the clipping plane of the camera.
                ///
                struct  ClippingPlane
                {
                    ///
                    /// \brief Distance of the near clipping plane from the camera.
                    ///
                    float   near;

                    ///
                    /// \brief Distance of the far clipping plane from the camera.
                    ///
                    float   far;
                };

            public:
                ///
                /// \brief Default constructor
                ///
                Camera(void);

                ///
                /// \brief Construct a camera from an assimp camera.
                ///
                Camera(const aiCamera *assimpCamera); // TODO GSL NOT NULL

                ///
                /// \brief Copy constructor.
                ///
                Camera(const Camera &other);

                ///
                /// \brief Move constructor.
                ///
                Camera(Camera &&other) noexcept;

                ///
                /// \brief Destructor.
                ///
                virtual ~Camera(void) noexcept;

            public:
                ///
                /// \brief Copy assigment operator.
                ///
                Camera  &operator=(const Camera &other);

                ///
                /// \brief Move assigment operator.
                ///
                Camera  &operator=(const Camera &&other) noexcept;

            protected:
                ///
                /// \brief The name of the camera.
                ///
                std::string         name;

                ///
                /// \brief the clipping plane for the camera.
                ///
                ClippingPlane       clippingPlane;

                ///
                /// \brief Screen aspect ratio.
                ///
                float               aspect;

                ///
                /// \brief The field of view angle for the horizontal axis in radian.
                ///
                float               fov;

                ///
                ///
                ///
                glm::vec3           up;

                ///
                ///
                ///
                glm::vec3           lookat;

                ///
                ///
                ///
                glm::vec3           position;
        };

    }
}

#endif /* !__CAMERA_HPP__ */
