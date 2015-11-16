///
/// \file gameengine.cpp
/// \brief TODO fill gameengine.cpp brief
/// \author Martin-Pierrat Louis (mart_p)
/// \version 1.0.0
/// \date Oct 18, 2015
///
/// TODO fill gameengine.cpp description
///

#include <vector>
#include <QOpenGLShader>
#include "gameengine.h"
#include "gameclock.h"
#include "material.hh"
#include <iostream>

#include    "worldparticles.hpp"

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
    _mat.addShader(QOpenGLShader::Fragment, RESOURCES_PATH "/shaders/phongFrag.glsl");
    _mat.addShader(QOpenGLShader::Vertex, RESOURCES_PATH "/shaders/phongVert.glsl");
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
