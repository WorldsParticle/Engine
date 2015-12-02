#include "GameEngine.hpp"

GameEngine::GameEngine(void)
{
    this->_gameviewList.push_back(new GameView());
}

void    GameEngine::update(void)
{
    for (GameView *gameview : this->_gameviewList)
    {
        gameview->Update();
    }
}

void    GameEngine::draw(void)
{
    for (GameView *gameview : this->_gameviewList)
    {
        gameview->Draw();
    }
}

// TODO : event handling
void    GameEngine::changeRatio(float f)
{
    for (GameView *gameview : this->_gameviewList)
    {
        gameview->changeRatio(f);
    }
}
