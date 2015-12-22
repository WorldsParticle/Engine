#include    "Model.hpp"
#include    "ShaderProgramManager.hpp"
#include    "BasicRenderer.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        Model::Model(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
            GameObject(position, rotation, scale)
        {

        }

        Model::~Model(void)
        {

        }

        bool
        Model::initialise(void)
        {
            this->renderer = new BasicRenderer();
            this->material = std::make_shared<Material>();
            this->shaderprogram = ShaderProgramManager::Get(TEST_SHADER_PROGRAM);
            return true;
        }

        void
        Model::update(void)
        {
            const glm::vec3     &rotation = this->transform.getRotation();
            this->transform.setRotation(rotation + glm::vec3(0.0, 0.01, 0.0));
        }

        void
        Model::draw(const glm::mat4 &projection, const glm::mat4 &view)
        {
            this->renderer->draw(this, projection, view, this->transform.getMatrix());
        }
    }
}
