///
/// \file gameengine.h
/// \brief TODO fill gameengine.h brief
/// \author Martin-Pierrat Louis (mart_p)
/// \version 1.0.0
/// \date Oct 18, 2015
///
/// TODO fill gameengine.h description
///

#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include    "worldparticles.hpp"

#include    "GameView.hpp"

class GameEngine
{
public:
    GameEngine();

    void    update();
    void    draw();

private:
    std::list<GameView *>     _gameviewList;

};

#endif // GAMEENGINE_H
