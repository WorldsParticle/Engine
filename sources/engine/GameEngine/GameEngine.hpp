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

<<<<<<< HEAD:sources/engine/GameEngine/GameEngine.hpp
=======
#include <string>
#include "model.h"
#include "myglpainter.h"
#include "mesh.hh"
#include "camera.h"

>>>>>>> origin/master:sources/engine/gameengine.h
#include    "worldparticles.hpp"

#include    "GameView.hpp"

class GameEngine
{
public:
    GameEngine();

    void    update();
    void    draw();

private:
<<<<<<< HEAD:sources/engine/GameEngine/GameEngine.hpp
    std::list<GameView *>     _gameviewList;
=======
    MyGLPainter		_painter;
    Camera		_cam;
    Model		*_model; // représente l'ensemble du monde
    Material		_mat;
    std::vector<Mesh>	_mesh;
>>>>>>> origin/master:sources/engine/gameengine.h
};

#endif // GAMEENGINE_H
