#ifndef     __TRANSFORM_HPP__
# define    __TRANSFORM_HPP__

#include    <glm/glm.hpp>

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
    /// \brief Destructor
    ///
    ~Transform(void);

public:
    ///
    /// \brief This function is used to generate a matrix from the position, rotation and scale of the transform.
    ///
    const glm::mat4 GetMatrix(void) const;

public:
    ///
    /// \brief Setter for the position attribute.
    ///
    void            SetPosition(const glm::vec3 &position)
    {
        this->_position = position;
    }

    ///
    /// \brief Setter for the rotation attribute
    ///
    void            SetRotation(const glm::vec3 &rotation)
    {
        this->_rotation = rotation;
    }

    ///
    /// \brief Setter for the scale attribute.
    ///
    void            SetScale(const glm::vec3 &scale)
    {
        this->_scale = scale;
    }

public:
    ///
    /// \brief Getter for the position attribute.
    ///
    const glm::vec3 &GetPosition(void) const
    {
        return this->_position;
    }

    ///
    /// \brief Getter for the rotation attribute.
    ///
    const glm::vec3 &GetRotation(void) const
    {
        return this->_rotation;
    }

    ///
    /// \brief Getter for the scale attribute
    ///
    const glm::vec3 &GetScale(void) const
    {
        return this->_scale;
    }

protected:
    ///
    /// \brief This attribute is used to store a position in 3D space.
    ///
    glm::vec3       _position;

    ///
    /// \brief This attribute is used to store a 3D rotation (X, Y, Z in degree).
    ///
    glm::vec3       _rotation;

    ///
    /// \brief This attribute is used to store a scale in X, Y and Z axis.
    ///
    glm::vec3       _scale;
};

#endif /* !__TRANSFORM_HPP__ */
