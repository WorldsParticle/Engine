#ifndef     __RENDERER_HPP__
# define    __RENDERER_HPP__

#include    <glm/glm.hpp>
#include    <memory>

#include    "worldparticles.hpp"

namespace WorldParticles
{
    namespace Engine
    {

        class   GameObject;

        ///
        /// \brief This class is used to store the whole rendering part into a class. This class should be inherited.
        ///
        class       IRenderer
        {
            public:
                ///
                /// \brief This method is used to draw a gameobject.
                /// \param gameobject, the gameobject that will be draw.
                /// \param projection, the projection matrix used to draw the object.
                /// \param view, the view matrix used to draw the object.
                /// \param model, the view model used to draw the object.
                ///
                virtual void    draw(const GameObject *gameobject,
                        const glm::mat4 &projection,
                        const glm::mat4 &view,
                        const glm::mat4 &model) = 0;
        };
    }
}

#endif /* !__RENDERER_HPP__ */
