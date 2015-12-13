
#include    <glm/glm.hpp>
#include    <algorithm>

#include    "GameView.hpp"
#include    "Cube.hpp"

namespace WorldParticles
{
    namespace Engine
    {

        /// TODO : delete push object
        GameView::GameView(void)
        {
        }

        GameView::~GameView(void)
        {
            // nothing to do
        }



        GameView    &GameView::operator<<(const std::shared_ptr<Camera> &camera)
        {
            this->AddCamera(camera);
            return *this;
        }

        GameView    &GameView::operator<<(const std::shared_ptr<GameObject> &gameobject)
        {
            this->AddGameObject(gameobject);
            return *this;
        }

        GameView    &GameView::operator<<(const std::shared_ptr<Light> &light)
        {
            this->AddLight(light);
            return *this;
        }


        bool    GameView::initialise(void)
        {
            std::shared_ptr<Camera> camera_ptr = std::make_shared<Camera>(glm::vec3(5.0, 5.0, 5.0));
            this->_cameraList.push_back(camera_ptr);
            std::shared_ptr<GameObject> gameobject = std::make_shared<Primitives::Cube>();
            this->_gameobjectList.push_back(gameobject);

            std::for_each(this->_cameraList.begin(), this->_cameraList.end(), [](auto &e){
                e->initialise();
            });
            std::for_each(this->_gameobjectList.begin(), this->_gameobjectList.end(), [](auto &e){
                e->initialise();
            });
            return true;
        }

        void    GameView::Update(void)
        {
            std::for_each(this->_cameraList.begin(), this->_cameraList.end(), [](auto &e) {
                e->Update();
            });
            std::for_each(this->_gameobjectList.begin(), this->_gameobjectList.end(), [](auto &e){
                e->Update();
            });
        }

        void    GameView::Draw(void)
        {
            for (std::shared_ptr<Camera> &camera : this->_cameraList)
            {
                camera->Draw();
                glm::mat4 &&projection = camera->GetProjection();
                glm::mat4 &&view = camera->GetView();
                for (std::shared_ptr<GameObject> &gameobject : this->_gameobjectList)
                {
                    gameobject->Draw(projection, view);
                }
            }
        }



        void    GameView::AddGameObject(const std::shared_ptr<GameObject> &gameobject)
        {
            this->_gameobjectList.push_back(gameobject);
        }

        /// TODO order by
        void    GameView::AddCamera(const std::shared_ptr<Camera> &camera)
        {
            this->_cameraList.push_back(camera);
        }

        void    GameView::AddLight(const std::shared_ptr<Light> &light)
        {
            this->_lightList.push_back(light);
        }

    }
}
