#ifndef     __TRANSFORM_HPP__
# define    __TRANSFORM_HPP__

#include    <glm/glm.hpp>
#include    <assimp/vector3.h>
#include    <assimp/matrix4x4.h>

namespace   WorldParticles
{
    namespace   Engine
    {
        ///
        /// \brief The Transform class is used to represent an object transformation in space. (like position, rotation and scale of the object)
        ///
        /// This class should be updated with quaternion support.
        ///
        class   Transform
        {
            public:
                ///
                /// \brief Default constructor
                ///
                Transform(void);

                ///
                /// \brief Construct a transform from an assimp matrix4x4.
                ///
                Transform(const aiMatrix4x4 &assimpTransformation);

                ///
                /// \brief Copy constructor.
                ///
                Transform(const Transform &other) = default;

                ///
                /// \brief Move constructor.
                ///
                Transform(Transform &&other) noexcept = default;

                ///
                /// \brief Destructor
                ///
                virtual ~Transform(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Transform   &operator=(const Transform &other) = default;

                ///
                /// \brief Move assignment operator.
                ///
                Transform   &operator=(Transform &&other) noexcept = default;

            public:
                ///
                /// \brief Get the matrix of the transform.
                ///
                const glm::mat4 &getMatrix(void) const;

                /// TODO implementation function like "rotate" "translate"...

            public:
                ///
                /// \brief This method rotate the transform.
                ///
                void    rotate(const glm::vec3 &rotation);

            protected:
                ///
                /// \brief This matrix represent the actual state of the transform.
                ///
                glm::mat4       matrix;
        };
    }
}

#endif /* !__TRANSFORM_HPP__ */
