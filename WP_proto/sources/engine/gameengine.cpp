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
#include <iostream>

GameEngine::GameEngine() :
    _painter()
{
}

void    GameEngine::setModel(Model *model)
{
    //Initialisation & tt a faire ici
    _model = model;
}

void GameEngine::addShader() {
    _mat.addShader(QOpenGLShader::Fragment, "./graphic/shaders/phongFrag.glsl");
    _mat.addShader(QOpenGLShader::Vertex, "./graphic/shaders/phongVert.glsl");
    _mat.link();

}

void GameEngine::addMesh(const std::string &fileName) {
    _mesh.emplace_back(_mat);
    _mesh.back().fromFile(fileName);
}

void    GameEngine::update()
{
    //GameClock::elapsedTime() pour le temps depuis dernière update
}

void    GameEngine::draw()
{
    _painter.draw();
    for (unsigned int i = 0; i < _mesh.size(); i++) {
	_mesh[i].render();
    }
}
