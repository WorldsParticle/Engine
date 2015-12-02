#ifndef     __CAMERA_HPP__
# define    __CAMERA_HPP__

#include    <glm/glm.hpp>
#include    "Transform.hpp"
#include    "GameObject.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief This class is used to represent a basic camera in a 3D world.
        ///
        class       Camera
        {
            public:
                ///
                /// \brief Default constructor
                ///
                Camera(const glm::vec3 &position = glm::vec3(0.0),
                        const glm::vec3 &rotation = glm::vec3(0.0),
                        const glm::vec3 &scale = glm::vec3(1.0));

                ///
                /// \brief Destructor
                ///
                ~Camera(void);

            public:
                ///
                /// \brief This method is used to return the projection matrix of the camera.
                ///
                glm::mat4   GetProjection(void) const;

                ///
                /// \brief This method is used to return the view matrix of the camera.
                ///
                glm::mat4   GetView(void) const;

            public:
                ///
                /// \brief This method is used to update the camera in the scene.
                ///
                virtual void    Update(void);

                ///
                /// \brief This method is used to launch the draw of this camera.
                ///
                virtual void    Draw(void);

            protected:

                ///
                /// \brief The transform attribute is used to store the 3D transformation of the camera
                ///
                Transform   transform;

                ///
                /// \brief This attribute is used to store the camera field of view.
                ///
                float       fieldOfView;

                ///
                /// \brief This attribute is used to store the minimum view distance.
                ///
                float       zNear;

                ///
                /// \brief This attribute is used to store the maximum view distance.
                ///
                float       zFar;

        };

    }
}

#endif /* !__CAMERA_HPP__ */
