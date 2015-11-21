#ifndef GPUBUFFER_H_
# define GPUBUFFER_H_
#include <vector>
#include <QOpenGLContext>
#include <QtOpenGL>
#include <QtOpenGL/QGLFunctions>
#include "glwindow.h"
#include "qopenglcontext.h"

class GPUBuffer {
    private:
	GLuint _vbo;
	GLuint _ebo;
	bool _hasNormals;
	bool _hasTexture;
	std::vector<GLfloat> _vertexArray;
	std::vector<GLuint> _elementArray;
    public:
	explicit GPUBuffer();
	GPUBuffer(const GPUBuffer&);
	~GPUBuffer();
	void operator=(const GPUBuffer&);
	inline decltype(_vertexArray)& getVertexArray() { return _vertexArray; }
	inline decltype(_elementArray)& getElementArray() { return _elementArray; }
	inline void setHasNormals(bool&& b_) { _hasNormals = b_; }
	inline void setHasTexture(bool&& b_) { _hasTexture = b_; }
	void setBuffer();
	void regenVboEbo();
	void GPUFree();
	void CPUFree();
	void draw(GLenum drawStyle_) const;
};

#endif /* !GPUBUFFER_H_ */
