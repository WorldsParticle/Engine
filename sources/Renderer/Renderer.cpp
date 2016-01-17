///
/// \file Renderer.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 17:55:39
///
/// \version 1.0.6
///

#include    <GL/glew.h>
#include    <log4cpp/Category.hh>

#include    "Renderer.hpp"
#include    "Object.hpp"
#include    "Camera.hpp"
#include    "Light.hpp"
#include    "Transform.hpp"
#include    "Mesh.hpp"

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {
        Renderer::Renderer(Scene *scene) :
            scene(scene)
        {

        }

        Renderer::Renderer(const Renderer &other) :
            scene(other.scene)
        {

        }

        Renderer::Renderer(Renderer &&other) noexcept :
            scene(std::move(other.scene))
        {

        }

        Renderer::~Renderer(void) noexcept
        {

        }



        Renderer &
        Renderer::operator=(const Renderer &other)
        {
            this->scene = other.scene;
            return *this;
        }

        Renderer &
        Renderer::operator=(Renderer &&other) noexcept
        {
            this->scene = std::move(other.scene);
            return *this;
        }



        void
        Renderer::add(Object *object)
        {
            //Category &root = Category::getRoot();

            //root << Priority::DEBUG << "Renderer - add object()" << object->getName();
            this->objects.push_back(object);
        }

        void
        Renderer::add(Camera *camera)
        {
            //Category &root = Category::getRoot();

            //root << Priority::DEBUG << "Renderer - add camera()" << camera->getName();
            this->cameras.push_back(camera);
        }

        void
        Renderer::add(Light *light)
        {
            //Category &root = Category::getRoot();

            //root << Priority::DEBUG << "Renderer - add light() : " << light->getName();
            this->lights.push_back(light);
        }



        void
        Renderer::render(void)
        {
            Category    &root = Category::getRoot();

            glEnable(GL_DEPTH_TEST);
            //root << Priority::DEBUG << "Renderer - render()";
            for (Camera *camera : this->cameras)
            {
                //root << Priority::DEBUG << "Renderer - render - camera()";
                const glm::mat4 &projection = camera->getProjection();
                const glm::mat4 &view = camera->getView();

                glClearColor(156.0f / 255.0f , 0, 76.0f / 255.0f, 1.0);
                glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
                glViewport(0, 0, 1024, 768);

                for (Object *object : this->objects)
                {
                    //root << Priority::DEBUG << "Draw => " << object->getName();
                    const glm::mat4 &model = object->getTransform().getMatrix();
                    const std::list<Mesh *>     &meshes = object->getMeshes();
                    for (Mesh *part : meshes)
                    {
                        //root << Priority::DEBUG << "Renderer - mesh - draw()";
                        part->draw(model, view, projection);
                    }
                }
            }
            this->cameras.clear();
            this->objects.clear();
            this->lights.clear();
        }
    }
}
