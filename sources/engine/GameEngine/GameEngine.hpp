#ifndef __GAMEENGINE_HPP__
#define __GAMEENGINE_HPP__

#include    "worldparticles.hpp"

#include    "GameView.hpp"

class GameEngine
{
public:
    ///
    /// \brief Default constructor
    ///
    GameEngine(void);

    /// \brief Destructor
    ~GameEngine(void);

    ///
    /// \brief This function is use to update the scene.
    ///
    void    update();

    ///
    /// \brief This function is used to draw the scene on the screen.
    ///
    void    draw();

    /// TODO : Event handling
    void    changeRatio(float f);

private:
    std::list<GameView *>     _gameviewList;
};

#endif // __GAMEENGINE_HPP__
