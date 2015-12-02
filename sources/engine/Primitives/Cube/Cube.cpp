#include    "worldparticles.hpp"

#include    "Cube.hpp"
#include    "BasicRenderer.hpp"

namespace WorldParticles
{
    namespace Engine
    {
        namespace Primitives
        {

            Cube::Cube(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
                GameObject(position, rotation, scale)
            {
                this->mesh.SetVertices(std::vector<glm::vec3>{
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
                this->renderer = new BasicRenderer();
            }

            void Cube::Draw(const glm::mat4 &projection, const glm::mat4 &view)
            {
                this->renderer->Draw(this->mesh, this->material, projection, view, this->transform.GetMatrix());
            }

            void    Cube::Update(void)
            {
            }

        }
    }
}
