#ifdef _WIN32
# include "engine/gameengine.h"
# include "engine/gameclock.h"
#else
# include "gameengine.h"
# include "gameclock.h"
#endif

GameEngine::GameEngine() :
    _painter()
{
}

void    GameEngine::setModel(Model *model)
{
    //Initialisation & tt a faire ici
    _model = model;
}

void    GameEngine::update()
{
    //GameClock::elapsedTime() pour le temps depuis dernière update
}

void    GameEngine::draw()
{
    _painter.draw();
}
