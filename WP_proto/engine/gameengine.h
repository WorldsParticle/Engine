#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#ifdef _WIN32
# include "model/model.h"
# include "graphic/myglpainter.h"
#else
# include "../model/model.h"
# include "../graphic/myglpainter.h"
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
};

#endif // GAMEENGINE_H
