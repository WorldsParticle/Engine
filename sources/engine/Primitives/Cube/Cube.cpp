
#include <string>
#include <fstream>
#include <streambuf>

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
                this->_renderer = new BasicRenderer();

                std::shared_ptr<ShaderProgram> shaderProgram = std::make_shared<ShaderProgram>();

                std::ifstream t(RESOURCES_PATH "/shaders/default.vert");
                std::string str((std::istreambuf_iterator<char>(t)), std::istreambuf_iterator<char>());

                std::ifstream t2(RESOURCES_PATH "/shaders/default.frag");
                std::string str2((std::istreambuf_iterator<char>(t2)), std::istreambuf_iterator<char>());

                std::shared_ptr<Shader>     vertexShader = std::make_shared<Shader>(Shader::Type::VERTEX_SHADER, str);
                vertexShader->Compile();

                std::shared_ptr<Shader>     fragmentShader = std::make_shared<Shader>(Shader::Type::FRAGMENT_SHADER, str2);
                fragmentShader->Compile();


                shaderProgram->AddShader(vertexShader);
                shaderProgram->AddShader(fragmentShader);

                shaderProgram->Link();

                this->_material.SetShaderProgram(shaderProgram);
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
