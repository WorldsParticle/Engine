#ifndef     __SCENE_HPP__
# define    __SCENE_HPP__

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
        /// \brief This class is used to represent a scene, with camera / light & gameobject.
        ///
        /// The scene could be used to draw a GUI in the screen, with a good gameobject separation.
        ///
        class       Scene
        {
            public:
                ///
                /// \brief Default constructor
                ///
                Scene(void);

                ///
                /// \brief Destructor
                ///
                virtual ~Scene(void);

            public:

                ///
                /// \brief This operator is used to push a camera in the scene.
                ///
                Scene       &operator<<(Camera *camera);

                ///
                /// \brief This operator is used to push a gameobject in the scene.
                ///
                Scene       &operator<<(GameObject *gameobject);

                ///
                /// \brief This operator is used to push a light in the scene.
                ///
                Scene       &operator<<(Light *light);

            public:
                ///
                /// \brief This method is used to initialise the scene.
                ///
                bool        initialise(void);

                ///
                /// \brief This function is used to update the scene.
                ///
                void        update(void);

                ///
                /// \brief This function is used to draw the scene on the screen.
                ///
                void        draw(void);

            public:
                ///
                /// \brief Add gameobject in the scene.
                ///
                void        add(GameObject *gameobject);

                ///
                /// \brief Add a camera in the scene.
                ///
                void        add(Camera *camera);

                ///
                /// \brief Add a light in the scene.
                ///
                void        add(Light *light);

            public:
                ///
                /// \brief Getter for the layer number attribute.
                ///
                int     getLayerNumber(void) const;

            public:
                ///
                /// \brief Setter for the layer number attribute.
                ///
                void    setLayerNumber(int layerNumber);

            private:
                ///
                /// \brief List of all gameobject present in the scene.
                ///
                std::list<GameObject *>     gameobjects;

                ///
                /// \brief List of all cameras in the scene.
                ///
                std::list<Camera *>         cameras;

                ///
                /// \brief List of all light in the scene.
                ///
                std::list<Light *>          lights;

                ///
                /// \brief This attribute is used to store the layer number.
                ///
                int                         layerNumber;
        };

    }
}

#endif /* !__GAMEVIEW_HPP__ */
