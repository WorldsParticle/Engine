#include    "worldparticles.hpp"

#include    "Skybox.hpp"

namespace WorldParticles
{
    namespace Engine
    {
	Skybox::Skybox(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
	    GameObject(position, rotation, scale)
	{
	    this->mesh.SetVertices(std::vector<glm::vec3>{

		    glm::vec3(-5.0f,  5.0f, -5.0f),
		    glm::vec3(-5.0f, -5.0f, -5.0f),
		    glm::vec3(5.0f, -5.0f, -5.0f),
		    glm::vec3(5.0f, -5.0f, -5.0f),
		    glm::vec3(5.0f,  5.0f, -5.0f),
		    glm::vec3(-5.0f,  5.0f, -5.0f),

		    glm::vec3(-5.0f, -5.0f,  5.0f),
		    glm::vec3(-5.0f, -5.0f, -5.0f),
		    glm::vec3(-5.0f,  5.0f, -5.0f),
		    glm::vec3(-5.0f,  5.0f, -5.0f),
		    glm::vec3(-5.0f,  5.0f,  5.0f),
		    glm::vec3(-5.0f, -5.0f,  5.0f),

		    glm::vec3(5.0f, -5.0f, -5.0f),
		    glm::vec3(5.0f, -5.0f,  5.0f),
		    glm::vec3(5.0f,  5.0f,  5.0f),
		    glm::vec3(5.0f,  5.0f,  5.0f),
		    glm::vec3(5.0f,  5.0f, -5.0f),
		    glm::vec3(5.0f, -5.0f, -5.0f),

		    glm::vec3(-5.0f, -5.0f,  5.0f),
		    glm::vec3(-5.0f,  5.0f,  5.0f),
		    glm::vec3(5.0f,  5.0f,  5.0f),
		    glm::vec3(5.0f,  5.0f,  5.0f),
		    glm::vec3(5.0f, -5.0f,  5.0f),
		    glm::vec3(-5.0f, -5.0f,  5.0f),

		    glm::vec3(-5.0f,  5.0f, -5.0f),
		    glm::vec3(5.0f,  5.0f, -5.0f),
		    glm::vec3(5.0f,  5.0f,  5.0f),
		    glm::vec3(5.0f,  5.0f,  5.0f),
		    glm::vec3(-5.0f,  5.0f,  5.0f),
		    glm::vec3(-5.0f,  5.0f, -5.0f),

		    glm::vec3(-5.0f, -5.0f, -5.0f),
		    glm::vec3(-5.0f, -5.0f,  5.0f),
		    glm::vec3(5.0f, -5.0f, -5.0f),
		    glm::vec3(5.0f, -5.0f, -5.0f),
		    glm::vec3(-5.0f, -5.0f,  5.0f),
		    glm::vec3(5.0f, -5.0f,  5.0f)
	    });
	    this->renderer = new SkyboxRenderer();
	}

	void Skybox::Draw(const glm::mat4 &projection, const glm::mat4 &view)
	{
	    this->renderer->Draw(this->mesh, this->material, projection, view, this->transform.GetMatrix());
	}

	void    Skybox::Update(void)
	{
	}
    }
}
