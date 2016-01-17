///
/// \file PerspectiveCamera.hpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sun, 17 Jan 2016 07:52:39
///
/// \version 1.0.7
///

#ifndef     __ENGINE_PERSPECTIVE_CAMERA_HPP__
# define    __ENGINE_PERSPECTIVE_CAMERA_HPP__

#include    "Engine/Core/Camera.hpp"

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
            PerspectiveCamera(SceneGraphNode *node);

            ///
            /// \brief Construct a perspective camera from an assimp camera.
            ///
            PerspectiveCamera(const aiCamera *assimpCamera, SceneGraphNode *node);

            ///
            /// \brief Copy constructor.
            ///
            PerspectiveCamera(const PerspectiveCamera &other) = default;

            ///
            /// \brief Move constructor.
            ///
            PerspectiveCamera(PerspectiveCamera &&other) noexcept = default;

            ///
            /// \brief Destructor.
            ///
            ~PerspectiveCamera(void);

        public:
            ///
            /// \brief Copy assignment operator.
            ///
            PerspectiveCamera   &operator=(const PerspectiveCamera &other) = default;

            ///
            /// \brief Move assignment operator.
            ///
            PerspectiveCamera   &operator=(PerspectiveCamera &&other) noexcept = default;

        public:
            ///
            /// \brief this method clone the perspective camera.
            ///
            virtual PerspectiveCamera   *clone(void) const;

            ///
            /// \brief This method is used to update the perspective camera.
            ///
            virtual void                update(void);

        public:
            ///
            /// \brief Getter for the camera projection matrix.
            ///
            const glm::mat4     &getProjection(void) const;

            ///
            /// \brief Getter for the camera view matrix.
            ///
            const glm::mat4     &getView(void) const;

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

#endif /* !__ENGINE_PERSPECTIVE_CAMERA_HPP__ */
