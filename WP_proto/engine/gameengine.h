#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#ifdef _WIN32
# include "model/model.h"
# include "graphic/myglpainter.h"
# include "graphic/mesh.hh"
#else
# include "../model/model.h"
# include "../graphic/myglpainter.h"
# include "../graphic/mesh.hh"
#endif

class GameEngine
{
public:
    GameEngine();

    void    setModel(Model *model);

    void    update();
    void    draw();

private:
    Model       *_model; // représente l'ensemble du monde
    MyGLPainter _painter;
    std::vector<Mesh> _mesh;
};

#endif // GAMEENGINE_H
