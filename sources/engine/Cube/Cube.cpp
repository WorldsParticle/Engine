#include    "worldparticles.hpp"

#include    "Cube.hpp"
#include    "CubeRenderer.hpp"

#include <glm/ext.hpp>
#include    <iostream>

Cube::Cube(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
    GameObject(position, rotation, scale)
{
    std::cout << "CreateCube" << std::endl;

    this->mesh.SetVertices(std::vector<glm::vec3>{
<<<<<<< HEAD

//                               glm::vec3(-1.0f, -1.0f, 0.0f),
//                               glm::vec3(1.0f, -1.0f, 0.0f),
//                               glm::vec3(0.0f,  1.0f, 0.0f),
=======
                               glm::vec3(-1.0f, -1.0f, 0.0f),
                               glm::vec3(1.0f, -1.0f, 0.0f),
                               glm::vec3(0.0f,  1.0f, 0.0f),
>>>>>>> origin/master
                               glm::vec3(-1.0, -1.0, -1.0),
                               glm::vec3(-1.0, -1.0, 1.0),
                               glm::vec3(-1.0, 1.0, 1.0),

                               glm::vec3(1.0, 1.0, -1.0),
                               glm::vec3(-1.0, -1.0, -1.0),
                               glm::vec3(-1.0, 1.0, -1.0),

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
<<<<<<< HEAD

                               glm::vec3(1.0, 1.0, 1.0),
                               glm::vec3(-1.0, 1.0, 1.0),
                               glm::vec3(1.0, -1.0, 1.0)
=======
>>>>>>> origin/master

                               glm::vec3(1.0, 1.0, 1.0),
                               glm::vec3(-1.0, 1.0, 1.0),
                               glm::vec3(1.0, -1.0, 1.0),
                           });
    this->renderer = new CubeRenderer();
}

void Cube::Draw(const glm::mat4 &projection, const glm::mat4 &view)
{
    this->renderer->Draw(this->mesh,
                         this->material,
                         projection,
                         view,
                         this->transform.GetMatrix());
}

void    Cube::Update()
{
}
