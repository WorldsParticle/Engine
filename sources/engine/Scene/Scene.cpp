
#include    <glm/glm.hpp>
#include    <algorithm>

#include    "Scene.hpp"
#include    "Cube.hpp"

namespace WorldParticles
{
    namespace Engine
    {

        /// TODO : delete push object
        Scene::Scene(void)
        {
        }

        Scene::~Scene(void)
        {
            // nothing to do
        }



        Scene       &Scene::operator<<(Camera *camera)
        {
            this->add(camera);
            return *this;
        }

        Scene    &Scene::operator<<(GameObject *gameobject)
        {
            this->add(gameobject);
            return *this;
        }

        Scene    &Scene::operator<<(Light *light)
        {
            this->add(light);
            return *this;
        }


        bool    Scene::initialise(void)
        {
            for (Camera *camera : this->_cameras)
            {
                camera->initialise();
            }
            for (GameObject *gameobject : this->_gameobjects)
            {
                gameobject->initialise();
            }
            return true;
        }

        void    Scene::update(void)
        {
            for (Camera *camera : this->_cameras)
            {
                 camera->update();
            }
            for (GameObject *gameobject : this->_gameobjects)
            {
                gameobject->update();
            }
        }

        void    Scene::draw(void)
        {
            for (Camera *camera : this->_cameras)
            {
                camera->draw();
                const glm::mat4 &projection = camera->GetProjection();
                const glm::mat4 &view = camera->GetView();
                for (GameObject *gameobject : this->_gameobjects)
                {
                    gameobject->draw(projection, view);
                }
            }
        }



        void    Scene::add(GameObject *gameobject)
        {
            this->_gameobjects.push_back(gameobject);
        }

        /// TODO order by
        void    Scene::add(Camera *camera)
        {
            this->_cameras.push_back(camera);
        }

        void    Scene::add(Light *light)
        {
            this->_lights.push_back(light);
        }

    }
}
