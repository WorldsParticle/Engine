#ifndef     __GAMEVIEW_HPP__
# define    __GAMEVIEW_HPP__

#include    <list>

#include    "GameObject.hpp"
#include    "Camera.hpp"

namespace WorldParticles
{
    namespace Engine
    {
        ///
        /// \brief This class is used to represent a view, like a layer, in the screen.
        ///
        /// The gameview could be used to draw a GUI in the screen, with a good gameobject separation.
        ///
        class       GameView
        {
            public:
                ///
                /// \brief Default constructor
                ///
                GameView(void);

                ///
                /// \brief Destructor
                ///
                ~GameView(void);

            public:
                ///
                /// \brief This function is used to update the gameview
                ///
                void    Update(void);

                ///
                /// \brief This function is used to draw the gameview on the screen.
                ///
                void    Draw(void);

            private:
                ///
                /// \brief List of all gameobject present in this gameview.
                ///
                std::list<GameObject *>     _gameobjectList;

                ///
                /// \brief List of all cameras in the gameview.
                ///
                std::list<Camera *>         _cameraList;
        };

    }
}

#endif /* !__GAMEVIEW_HPP__ */
