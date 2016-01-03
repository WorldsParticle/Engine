#ifndef     __CAMERA_HPP__
# define    __CAMERA_HPP__

#include    <string>
#include    <glm/glm.hpp>
#include    <assimp/camera.h>

#include    "Entity.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        class   SceneGraphNode;

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
                Camera(SceneGraphNode *node);

                ///
                /// \brief Construct a camera from an assimp camera.
                ///
                Camera(const aiCamera *assimpCamera, SceneGraphNode *node); // TODO GSL NOT NULL

                ///
                /// \brief Copy constructor.
                ///
                Camera(const Camera &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Camera(Camera &&other) noexcept = default;

                ///
                /// \brief Destructor.
                ///
                virtual ~Camera(void) noexcept;

            public:
                ///
                /// \brief Copy assigment operator.
                ///
                Camera  &operator=(const Camera &other) = default;

                ///
                /// \brief Move assigment operator.
                ///
                Camera  &operator=(Camera &&other) noexcept = default;

            public:
                ///
                /// \brief Getter for the camera name.
                ///
                const std::string   &getName(void) const;

                ///
                /// \brief Getter for the camera projection matrix.
                ///
                virtual const glm::mat4     &getProjection(void) const = 0;

                ///
                /// \brief Getter for the camera view matrix.
                ///
                virtual const glm::mat4     &getView(void) const = 0;

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
                /// \brief Up vector of the camera coordinate system relative to
                /// the coordinate space defined by the related node. (Entity::node);
                ///
                glm::vec3           up;

                ///
                /// \brief lookat vector of the camera coordinate system relative
                /// to the coordinate space defined by the related node. (Entity::node)
                ///
                glm::vec3           lookat;

                ///
                /// \brief Position of the camera relative to the coordinate space
                /// defined by the related node. (Entity::node)
                ///
                glm::vec3           position;
        };

    }
}

#endif /* !__CAMERA_HPP__ */
