
#include    <glm/glm.hpp>

#include    "GameView.hpp"
#include    "Cube.hpp"

GameView::GameView()
{
    this->_cameraList.push_back(new Camera(glm::vec3(5.0, 5.0, 5.0)));
    this->_gameobjectList.push_back(new Cube());
}

GameView::~GameView(void)
{

}

void    GameView::Draw()
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

void    GameView::Update()
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

