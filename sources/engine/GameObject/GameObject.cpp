#include    "GameObject.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        ///
        /// PUBLIC CONSTRUCTOR
        ///

        GameObject::GameObject(const glm::vec3 &position,
                const glm::vec3 &rotation,
                const glm::vec3 &scale) :
            transform(position, rotation, scale)
        {

        }

        GameObject::~GameObject(void)
        {

        }

        ///
        /// PUBLIC GETTER METHOD
        ///

        const Transform &
        GameObject::getTransform(void) const
        {
            return this->transform;
        }

        const IRenderer *
        GameObject::getRenderer(void) const
        {
             return this->renderer;
        }

        const std::shared_ptr<Material> &
        GameObject::getMaterial(void) const
        {
            return this->material;
        }

        const std::shared_ptr<Mesh> &
        GameObject::getMesh(void) const
        {
            return this->mesh;
        }

        const std::shared_ptr<ShaderProgram> &
        GameObject::getShaderProgram(void) const
        {
            return this->shaderprogram;
        }

        ///
        /// PUBLIC SETTER METHOD
        ///

        void
        GameObject::setTransform(const Transform &transform)
        {
            this->transform = transform;
        }

        void
        GameObject::setRenderer(IRenderer *renderer)
        {
            this->renderer = renderer;
        }

        void
        GameObject::setMaterial(std::shared_ptr<Material> &material)
        {
             this->material = material;
        }

        void
        GameObject::setMesh(std::shared_ptr<Mesh> &mesh)
        {
            this->mesh = mesh;
        }

        void
        GameObject::setShaderProgram(std::shared_ptr<ShaderProgram> &shaderprogram)
        {
             this->shaderprogram = shaderprogram;
        }
    }
}
