#ifndef SKYBOX_H_
# define SKYBOX_H_

#include    "GameObject.hpp"
#include    "Renderer/Renderer.hpp"
#include    "Renderer/SkyboxRenderer/SkyboxRenderer.hpp"

namespace WorldParticles
{
    namespace Engine
    {
	class   Skybox : public GameObject
	{
	    public:
		Skybox(const glm::vec3 &position = glm::vec3(0.0),
			const glm::vec3 &rotation = glm::vec3(0.0),
			const glm::vec3 &scale = glm::vec3(1.0));

	    public:
		void    Draw(const glm::mat4 &projection, const glm::mat4 &view);
		void    Update(void);

	    private:
		Renderer    *renderer;
	};
    }
}

#endif /* !SKYBOX_H_ */
