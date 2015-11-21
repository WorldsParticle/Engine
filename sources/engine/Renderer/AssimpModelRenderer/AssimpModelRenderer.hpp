#ifndef ASSIMPMODELRENDERER_H_
# define ASSIMPMODELRENDERER_H_

#include    "Renderer.hpp"

class   AssimpModelRenderer : public Renderer
{
    private:
	GLuint _vbo;
	GLuint _ebo;
	bool _hasNormals;
	bool _hasTexture;
	std::vector<GLfloat> _vertexArray;
	std::vector<GLuint> _elementArray;
    public:
	inline decltype(_vertexArray)& getVertexArray() { return _vertexArray; }
	inline decltype(_elementArray)& getElementArray() { return _elementArray; }
	inline void setHasNormals(bool&& b_) { _hasNormals = b_; }
	inline void setHasTexture(bool&& b_) { _hasTexture = b_; }
	void setBuffer();
	void regenVboEbo();
    public:
	AssimpModelRenderer();
	AssimpModelRenderer(const AssimpModelRenderer&);
	~AssimpModelRenderer();
	void operator=(const AssimpModelRenderer&);

    public:
	void    Draw(const Mesh &mesh,
		Material &material,
		const glm::mat4 &projection,
		const glm::mat4 &view,
		const glm::mat4 &model);
};

#endif /* !ASSIMPMODELRENDERER_H_ */
