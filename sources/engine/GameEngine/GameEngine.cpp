///
/// \file gameengine.cpp
/// \brief TODO fill gameengine.cpp brief
/// \author Martin-Pierrat Louis (mart_p)
/// \version 1.0.0
/// \date Oct 18, 2015
///
/// TODO fill gameengine.cpp description
///

#include "GameEngine.hpp"

GameEngine::GameEngine()
{
    this->_gameviewList.push_back(new GameView());
}

void    GameEngine::update()
{
    for (GameView *gameview : this->_gameviewList)
    {
        gameview->Update();
    }
}

void    GameEngine::draw()
{
    for (GameView *gameview : this->_gameviewList)
    {
        gameview->Draw();
    }
}

void    GameEngine::changeRatio(float f)
{
    for (GameView *gameview : this->_gameviewList)
    {
        gameview->changeRatio(f);
    }
}
