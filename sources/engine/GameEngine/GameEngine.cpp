#include "GameEngine.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        GameEngine::GameEngine(void)
        {
            this->_gameviewList.push_back(new GameView());
        }

        GameEngine::~GameEngine(void)
        {

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

    }
}
