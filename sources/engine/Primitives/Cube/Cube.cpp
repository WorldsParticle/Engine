
#include    "worldparticles.hpp"
#include    "Cube.hpp"
#include    "BasicRenderer.hpp"
#include    "ShaderProgramManager.hpp"

namespace WorldParticles
{
    namespace Engine
    {
        namespace Primitives
        {

            Cube::Cube(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
                GameObject(position, rotation, scale)
            {
            }

            bool    Cube::initialise(void)
            {
                this->_renderer = new BasicRenderer();
                this->_mesh = new Mesh();
                this->_mesh->setPositions(std::vector<glm::vec3>{
                        glm::vec3(-1.0f, -1.0f, 0.0f),
                        glm::vec3(1.0f, -1.0f, 0.0f),
                        glm::vec3(0.0f,  1.0f, 0.0f),

                        glm::vec3(-1.0, -1.0, -1.0),
                        glm::vec3(-1.0, -1.0, 1.0),
                        glm::vec3(-1.0, 1.0, 1.0),

                        glm::vec3(-1.0f, -1.0f, 0.0f),
                        glm::vec3(1.0f, -1.0f, 0.0f),
                        glm::vec3(0.0f,  1.0f, 0.0f),

                        glm::vec3(1.0, -1.0, 1.0),
                        glm::vec3(-1.0, -1.0, -1.0),
                        glm::vec3(1.0, -1.0, -1.0),

                        glm::vec3(1.0, 1.0, -1.0),
                        glm::vec3(1.0, -1.0, -1.0),
                        glm::vec3(-1.0, -1.0, -1.0),

                        glm::vec3(-1.0, -1.0, -1.0),
                        glm::vec3(-1.0, 1.0, 1.0),
                        glm::vec3(-1.0, 1.0, -1.0),

                        glm::vec3(1.0, -1.0, 1.0),
                        glm::vec3(-1.0, -1.0, 1.0),
                        glm::vec3(-1.0, -1.0, -1.0),

                        glm::vec3(-1.0, 1.0, 1.0),
                        glm::vec3(-1.0, -1.0, 1.0),
                        glm::vec3(1.0, -1.0, 1.0),

                        glm::vec3(1.0, 1.0, 1.0),
                        glm::vec3(1.0, -1.0, -1.0),
                        glm::vec3(1.0, 1.0, -1.0),

                        glm::vec3(1.0, -1.0, -1.0),
                        glm::vec3(1.0, 1.0, 1.0),
                        glm::vec3(1.0, -1.0, 1.0),

                        glm::vec3(1.0, 1.0, 1.0),
                        glm::vec3(1.0, 1.0, -1.0),
                        glm::vec3(-1.0, 1.0, -1.0),

                        glm::vec3(1.0, 1.0, 1.0),
                        glm::vec3(-1.0, 1.0, -1.0),
                        glm::vec3(-1.0, 1.0, 1.0),

                        glm::vec3(1.0, 1.0, 1.0),
                        glm::vec3(-1.0, 1.0, 1.0),
                        glm::vec3(1.0, -1.0, 1.0)

                });
                this->_mesh->update();
                this->_material = new Material();
                this->_material->SetShaderProgram(ShaderProgramManager::Get(DEFAULT_SHADER_PROGRAM));
                return true;
            }

            void    Cube::draw(const glm::mat4 &projection, const glm::mat4 &view)
            {
                glm::mat4   model = this->_transform.GetMatrix();
                this->_renderer->draw(this, projection, view, model);
            }

            void    Cube::update(void)
            {
                const glm::vec3 &position = this->_transform.GetPosition();
                if (position.y < 20.0)
                    this->_transform.SetPosition(position + glm::vec3(0.0, 0.1, 0.0));
                else
                    this->_transform.SetPosition(glm::vec3(0.0, -20.0, 0.0));
            }

        }
    }
}
