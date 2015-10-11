#include <vector>
#include <QOpenGLShader>
#ifdef _WIN32
# include "engine/gameengine.h"
# include "engine/gameclock.h"
# include "graphic/material.hh"
#else
# include "gameengine.h"
# include "gameclock.h"
# include "../graphic/material.hh"
#endif

GameEngine::GameEngine() :
    _painter()
{
}

void    GameEngine::setModel(Model *model)
{
    //Initialisation & tt a faire ici
    _model = model;
    Material mat;

    mat.addShader(QOpenGLShader::Fragment, "./graphic/shaders/phongFrag.glsl");
    mat.addShader(QOpenGLShader::Vertex, "./graphic/shaders/phongVert.glsl");
    mat.link();
    _mesh.emplace_back(mat);
    _mesh[0].fromFile("../testModels/monkey.dae");
}

void    GameEngine::update()
{
    //GameClock::elapsedTime() pour le temps depuis dernière update
}

void    GameEngine::draw()
{
    for (unsigned int i = 0; i < _mesh.size(); i++) {
	_mesh[i].render();
    }
    _painter.draw();
}
