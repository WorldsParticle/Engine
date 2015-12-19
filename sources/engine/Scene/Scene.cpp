
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
            for (Camera *camera : this->cameras)
            {
                camera->initialise();
            }
            for (GameObject *gameobject : this->gameobjects)
            {
                gameobject->initialise();
            }
            return true;
        }

        void    Scene::update(void)
        {
            for (Camera *camera : this->cameras)
            {
                 camera->update();
            }
            for (GameObject *gameobject : this->gameobjects)
            {
                gameobject->update();
            }
        }

        void    Scene::draw(void)
        {
            for (Camera *camera : this->cameras)
            {
                camera->draw();
                const glm::mat4 &projection = camera->getProjection();
                const glm::mat4 &view = camera->getView();
                for (GameObject *gameobject : this->gameobjects)
                {
                    gameobject->draw(projection, view);
                }
            }
        }



        void    Scene::add(GameObject *gameobject)
        {
            this->gameobjects.push_back(gameobject);
        }

        /// TODO order by
        void    Scene::add(Camera *camera)
        {
            this->cameras.push_back(camera);
        }

        void    Scene::add(Light *light)
        {
            this->lights.push_back(light);
        }


        int
        Scene::getLayerNumber(void) const
        {
             return this->layerNumber;
        }

        void
        Scene::setLayerNumber(int layerNumber)
        {
            this->layerNumber = layerNumber;
        }

    }
}
