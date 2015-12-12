#include "GameEngine.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        GameEngine::GameEngine(void)
        {
            this->AddGameView(std::make_shared<GameView>());
        }

        GameEngine::~GameEngine(void)
        {
            // nothing to do
        }


        bool    GameEngine::initialise(void)
        {
            bool    result = true;

            for (std::shared_ptr<GameView> &gameview : this->_gameviewList)
            {
                result = gameview->initialise() && result;
            }
            return result;
        }

        void    GameEngine::update(void)
        {
            for (std::shared_ptr<GameView> &gameview : this->_gameviewList)
            {
                gameview->Update();
            }
        }

        void    GameEngine::draw(void)
        {
            for (std::shared_ptr<GameView> &gameview : this->_gameviewList)
            {
                gameview->Draw();
            }
        }



        /// TODO should be tested
        void    GameEngine::AddGameView(const std::shared_ptr<GameView> &gameview)
        {
            this->_gameviewList.push_back(gameview);
            this->_gameviewList.sort([](const auto &a, const auto &b) {return a->GetLayerNumber() > b->GetLayerNumber();});
        }

    }
}
