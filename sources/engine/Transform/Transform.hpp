#ifndef     __TRANSFORM_HPP__
# define    __TRANSFORM_HPP__

#include    <glm/glm.hpp>


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
                /// \param position, a glm::vec3 that represent a position in 3D space.
                /// \param rotation, a glm::vec3 that represent a 3D rotation
                /// \param scale, a glm::vec3 that represent a scale in X, Y and Z axis.
                ///
                Transform(const glm::vec3 &position = glm::vec3(0.0),
                        const glm::vec3 &rotation = glm::vec3(0.0),
                        const glm::vec3 &scale = glm::vec3(1.0));

                ///
                /// \brief Copy constructor.
                ///
                Transform(const Transform &other);

                ///
                /// \brief Move constructor.
                ///
                Transform(Transform &&other);

                ///
                /// \brief Destructor
                ///
                virtual ~Transform(void) noexcept;

            public:
                ///
                /// \brief Copy assignment operator.
                ///
                Transform   &operator=(const Transform &other);

                ///
                /// \brief Move assignment operator.
                ///
                Transform   &operator=(Transform &&other);

            public:
                ///
                /// \brief This function is used to generate a matrix from the position, rotation and scale of the transform.
                ///
                const glm::mat4 &getMatrix(void) const;


                /// TODO implementation function like "rotate" "translate"...

            public:
                ///
                /// \brief Setter for the position attribute.
                ///
                void            setPosition(const glm::vec3 &position);

                ///
                /// \brief Setter for the rotation attribute
                ///
                void            setRotation(const glm::vec3 &rotation);

                ///
                /// \brief Setter for the scale attribute.
                ///
                void            setScale(const glm::vec3 &scale);

            public:
                ///
                /// \brief Getter for the position attribute.
                ///
                const glm::vec3     &getPosition(void) const;

                ///
                /// \brief Getter for the rotation attribute.
                ///
                const glm::vec3     &getRotation(void) const;

                ///
                /// \brief Getter for the scale attribute
                ///
                const glm::vec3     &getScale(void) const;

            private:
                ///
                /// \brief internally used to update the matrix.
                ///
                void    update(void);

            protected:
                ///
                /// \brief This attribute is used to store a position in 3D space.
                ///
                glm::vec3       position;

                ///
                /// \brief This attribute is used to store a 3D rotation (X, Y, Z in degree).
                ///
                glm::vec3       rotation;

                ///
                /// \brief This attribute is used to store a scale in X, Y and Z axis.
                ///
                glm::vec3       scale;

                ///
                /// \brief This matrix represent the actual state of the transform.
                ///
                glm::mat4       matrix;
        };
    }
}

#endif /* !__TRANSFORM_HPP__ */
