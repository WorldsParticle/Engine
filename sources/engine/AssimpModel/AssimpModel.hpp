#ifndef ASSIMPMODEL_H_
# define ASSIMPMODEL_H_

#include    "GameObject.hpp"
#include "../Renderer/AssimpModelRenderer/AssimpModelRenderer.hpp"
#include    "worldparticles.hpp"

class   AssimpModel : public GameObject
{
    public:
	AssimpModel(const glm::vec3 &position = glm::vec3(0.0),
		const glm::vec3 &rotation = glm::vec3(0.0),
		const glm::vec3 &scale = glm::vec3(1.0));

    public:
	void    Draw(const glm::mat4 &projection, const glm::mat4 &view);
	void    Update(void);

    public:
	void fromFile(const std::string&);

    private:
	GLuint _vertexArray;
	AssimpModelRenderer *renderer;
	void _getAllFaces(const struct aiScene *, const struct aiNode*);
};


#endif /* !ASSIMPMODEL_H_ */
