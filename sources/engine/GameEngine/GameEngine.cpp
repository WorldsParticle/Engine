#include "GameEngine.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {

        GameEngine::GameEngine(void)
        {
            this->AddGameView(std::make_shared<GameView>());
	    //sound test
	    _soundManager.initAudio();
	    _soundManager.createBuffers();
	    _soundManager.createSources();
	    _soundManager.fillBuffer(0, RESOURCES_PATH "/audio/lol.wav");
	    _soundManager.attachBuffer(0, 0);
	    _soundManager.setSourceValue(0, AL_POSITION, 0, 0, 0);
	    _soundManager.setListenerValue(AL_POSITION, 50, 50, 50);
	    _soundManager.sourceState(0, 1);
        }

        GameEngine::~GameEngine(void)
        {
            // nothing to do
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

	//besoin de ca pour close l'audio proprement apparemment
	void	GameEngine::closeAudio()
	{
	    _soundManager.closeAudio();
	}

    }
}
