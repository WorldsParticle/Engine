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
            this->_renderer = new BasicRenderer();
            this->_material = new Material();
            this->_material->SetShaderProgram(ShaderProgramManager::Get(DEFAULT_SHADER_PROGRAM));
            return true;
        }

        void
        Model::update(void)
        {

        }

        void
        Model::draw(const glm::mat4 &projection, const glm::mat4 &view)
        {
            glm::mat4   model = this->_transform.GetMatrix();
            this->_renderer->draw(this, projection, view, model);
        }
    }
}
