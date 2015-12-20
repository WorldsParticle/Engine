
#ifndef         __MODEL_HPP__
# define        __MODEL_HPP__

#include    "GameObject.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        class       Model : public GameObject
        {
            public:
                Model(const glm::vec3 &position = glm::vec3(0.0),
                        const glm::vec3 &rotation = glm::vec3(0.0),
                        const glm::vec3 &scale = glm::vec3(1.0));
                ~Model(void);

            public:
                bool    initialise(void);
                void    draw(const glm::mat4 &projection, const glm::mat4 &view);
                void    update(void);
        };
    }
}

#endif /* !__MODEL_HPP__ */
