
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
                this->_mesh = std::make_shared<Mesh>();
                this->_mesh->SetVertices(std::vector<glm::vec3>{
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
                this->_material.SetShaderProgram(ShaderProgramManager::Get(DEFAULT_SHADER_PROGRAM));
                return true;
            }

            void Cube::Draw(const glm::mat4 &projection, const glm::mat4 &view)
            {
                glm::mat4   model = this->_transform.GetMatrix();
                this->_renderer->Draw(this->_mesh, this->_material, projection, view, model);
            }

            void    Cube::Update(void)
            {
            }

        }
    }
}
