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

#include <string>
#include "model.h"
#include "myglpainter.h"
#include "mesh.hh"

#include    "worldparticles.hpp"

class GameEngine
{
public:
    GameEngine();

    void    setModel(Model *model);
    void    addShader();
    void    addMesh(const std::string & = RESOURCES_PATH "/models/monkey.dae");

    void    update();
    void    draw();

private:
    Model		*_model; // représente l'ensemble du monde
    Material		_mat;
    MyGLPainter		_painter;
    std::vector<Mesh>	_mesh;
};

#endif // GAMEENGINE_H
