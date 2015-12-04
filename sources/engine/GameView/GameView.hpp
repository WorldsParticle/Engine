#ifndef     __GAMEVIEW_HPP__
# define    __GAMEVIEW_HPP__

#include    <memory>
#include    <list>

#include    "GameObject.hpp"
#include    "Camera.hpp"
#include    "Light.hpp"

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
                virtual ~GameView(void);

            public:

                ///
                /// \brief This operator is used to push a camera into the gameview.
                ///
                GameView    &operator<<(const std::shared_ptr<Camera> &camera);

                ///
                /// \brief This operator is used to push a gameobject into the gameview.
                ///
                GameView    &operator<<(const std::shared_ptr<GameObject> &gameobject);

                ///
                /// \brief This operator is used to push a light into the gameview.
                ///
                GameView    &operator<<(const std::shared_ptr<Light> &light);

            public:
                ///
                /// \brief This function is used to update the gameview
                ///
                void    Update(void);

                ///
                /// \brief This function is used to draw the gameview on the screen.
                ///
                void    Draw(void);

                /// TODO : add event processing

            public:
                ///
                /// \brief Add gameobject into the gameview
                ///
                void    AddGameObject(const std::shared_ptr<GameObject> &gameobject);

                ///
                /// \brief Add a camera into the gameview.
                ///
                void    AddCamera(const std::shared_ptr<Camera> &camera);

                ///
                /// \brief Add a light into the gameview.
                ///
                void    AddLight(const std::shared_ptr<Light> &light);

            public:
                ///
                /// \brief Getter for the layer number attribute.
                ///
                int     GetLayerNumber(void) const
                {
                    return this->_layerNumber;
                }

            public:
                ///
                /// \brief Setter for the layer number attribute.
                ///
                void    SetLayerNumber(int layerNumber)
                {
                     this->_layerNumber = layerNumber;
                }

            private:
                ///
                /// \brief List of all gameobject present in this gameview.
                ///
                std::list<std::shared_ptr<GameObject>>  _gameobjectList;

                ///
                /// \brief List of all cameras in the gameview.
                ///
                std::list<std::shared_ptr<Camera>>      _cameraList;

                ///
                /// \brief List of all light in the gameview.
                ///
                std::list<std::shared_ptr<Light>>       _lightList;

                ///
                /// \brief This attribute is used to store the layer number.
                ///
                int                                     _layerNumber;
        };

    }
}

#endif /* !__GAMEVIEW_HPP__ */
