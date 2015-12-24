
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
                this->renderer = new BasicRenderer();
                this->mesh = std::make_shared<Mesh>();
                this->mesh->setPositions(std::vector<glm::vec3>{
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
                this->mesh->update();
                this->material = std::make_shared<Material>();
                this->shaderprogram = ShaderProgramManager::Get(DEFAULT_SHADER_PROGRAM);
                return true;
            }

            void    Cube::draw(const glm::mat4 &projection, const glm::mat4 &view)
            {
                this->renderer->draw(this, projection, view, this->transform.getMatrix());
            }

            void    Cube::update(void)
            {
            }

        }
    }
}
