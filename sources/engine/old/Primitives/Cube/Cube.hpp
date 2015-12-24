#ifndef     __CUBE_HPP__
# define    __CUBE_HPP__

#include    "GameObject.hpp"

namespace WorldParticles
{
    namespace Engine
    {
        namespace Primitives
        {
            ///
            /// \brief This class represent the cube primitive.
            ///
            class   Cube : public GameObject
            {
                public:
                    ///
                    /// \brief Default Constructor
                    ///
                    Cube(const glm::vec3 &position = glm::vec3(0.0),
                            const glm::vec3 &rotation = glm::vec3(0.0),
                            const glm::vec3 &scale = glm::vec3(1.0));

                public:
                    ///
                    /// \brief This method is used to initialise the cube.
                    ///
                    bool    initialise(void);

                    ///
                    /// \brief This method is used to draw the cube in the screen.
                    ///
                    void    draw(const glm::mat4 &projection, const glm::mat4 &view);

                    ///
                    /// \brief This cube is used to update the cube in the scene.
                    ///
                    void    update(void);
            };
        }
    }
}

#endif /* !__CUBE_HPP__ */
