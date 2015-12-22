#include    "Transform.hpp"
#include    <glm/gtc/matrix_transform.hpp>


namespace WorldParticles
{
    namespace Engine
    {

        Transform::Transform(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
            position(position),
            rotation(rotation),
            scale(scale)
        {
            // nothing to do
        }

        Transform::~Transform(void)
        {
            // nothing to do
        }

        ///
        /// PUBLIC SETTER
        ///

        void
        Transform::setPosition(const glm::vec3 &position)
        {
            this->position = position;
            this->update();
        }

        void
        Transform::setRotation(const glm::vec3 &rotation)
        {
            this->rotation = rotation;
            this->update();
        }

        void
        Transform::setScale(const glm::vec3 &scale)
        {
            this->scale = scale;
            this->update();
        }

        ///
        /// PUBLIC GETTER
        ///

        const glm::vec3 &
        Transform::getPosition(void) const
        {
             return this->position;
        }

        const glm::vec3 &
        Transform::getRotation(void) const
        {
            return this->rotation;
        }

        const glm::vec3 &
        Transform::getScale(void) const
        {
             return this->scale;
        }

        const glm::mat4 &
        Transform::getMatrix(void) const
        {
             return this->matrix;
        }

        ///
        /// PRIVATE METHOD
        ///

        void
        Transform::update(void)
        {
            glm::mat4   result = glm::mat4(1);
            result = glm::translate(result, this->position);
            result = glm::rotate(result, this->rotation.x, glm::vec3(1.0, 0.0, 0.0));
            result = glm::rotate(result, this->rotation.y, glm::vec3(0.0, 1.0, 0.0));
            result = glm::rotate(result, this->rotation.z, glm::vec3(0.0, 0.0, 1.0));
            result = glm::scale(result, this->scale);
            this->matrix = result;
        }

    }
}
