#ifndef     __GAMEVIEW_HPP__
# define    __GAMEVIEW_HPP__

#include    "worldparticles.hpp"

#include    <list>

#include    "GameObject.hpp"
#include    "Camera.hpp"


class       GameView
{
public:
    GameView();

public:
    void    Update(void);
    void    Draw(void);
    void    GameView::changeRatio(float ratio);

private:
    std::list<GameObject *>     _gameobjectList;
    std::list<Camera *>         _cameraList;
};

#endif /* !__GAMEVIEW_HPP__ */
