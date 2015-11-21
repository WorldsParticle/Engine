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
    Transform(const glm::vec3 &position = glm::vec3(0.0), const glm::vec3 &rotation = glm::vec3(0.0), const glm::vec3 &scale = glm::vec3(1.0));

public:
    const glm::mat4 GetMatrix(void) const;

public:
    void            SetPosition(const glm::vec3 &position)
    {
        this->_position = position;
    }

    void            SetRotation(const glm::vec3 &rotation)
    {
        this->_rotation = rotation;
    }

    void            SetScale(const glm::vec3 &scale)
    {
        this->_scale = scale;
    }

public:
    const glm::vec3 &GetPosition(void) const
    {
        return this->_position;
    }

    const glm::vec3 &GetRotation(void) const
    {
        return this->_rotation;
    }

    const glm::vec3 &GetScale(void) const
    {
        return this->_scale;
    }

private:
    glm::vec3       _position;
    glm::vec3       _rotation;
    glm::vec3       _scale;
};

#endif /* !__TRANSFORM_HPP__ */
