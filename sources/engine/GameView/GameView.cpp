
#include    <glm/glm.hpp>

#include    "GameView.hpp"
#include    "Cube.hpp"
#include    "ParticleGenerator.hpp"

namespace WorldParticles
{
    namespace Engine
    {

        GameView::GameView(void)
        {
            this->_cameraList.push_back(new Camera(glm::vec3(5.0, 5.0, 5.0)));
            //this->_gameobjectList.push_back(new Primitives::Cube());
            this->_gameobjectList.push_back(new ParticleGenerator());
        }

        GameView::~GameView(void)
        {

        }

        void    GameView::Draw(void)
        {
            glm::mat4   projection;
            glm::mat4   view;

            for (Camera *camera : this->_cameraList)
            {
                camera->Draw();
                projection = camera->GetProjection();
                view = camera->GetView();
                for (GameObject *gameobject : this->_gameobjectList)
                {
                    gameobject->Draw(projection, view);
                }
            }
        }

        void    GameView::Update(void)
        {
            for (Camera *camera : this->_cameraList)
            {
                camera->Update();
            }
            for (GameObject *gameobject : this->_gameobjectList)
            {
                gameobject->Update();
            }
        }

    }
}
