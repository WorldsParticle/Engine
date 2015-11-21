#include "GPUBuffer.hh"

#define VERTEX_LOCATION_ 0
#define NORMAL_LOCATION_ 1
#define UV_LOCATION_ 2

GPUBuffer::GPUBuffer() : _vbo(0), _ebo(0), _hasNormals(false), _hasTexture(false) {
}

GPUBuffer::GPUBuffer(const GPUBuffer& o_) : _vbo(o_._vbo), _ebo(o_._ebo), _hasNormals(o_._hasNormals), _hasTexture(o_._hasTexture) {
    if (_vbo == 0) {
	_vertexArray = o_._vertexArray;
    }
    if (_ebo == 0) {
	_elementArray = o_._elementArray;
    }
}

void GPUBuffer::operator=(const GPUBuffer& o_) {
    _vbo = o_._vbo;
    _ebo = o_._ebo;
    _hasNormals = o_._hasNormals;
    _hasTexture = o_._hasTexture;
    if (_vbo) {
	return;
    }
    _vertexArray = o_._vertexArray;
    _elementArray = o_._elementArray;
}

void GPUBuffer::regenVboEbo() {
    if (_vbo) {
	GLWindow::m_funcs->glDeleteBuffers(1, &_vbo);
	GLWindow::m_funcs->glDeleteBuffers(1, &_ebo);
    }
    GLWindow::m_funcs->glGenBuffers(1, &_vbo);
    GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, _vbo);
    GLWindow::m_funcs->glBufferData(GL_ARRAY_BUFFER, _vertexArray.size() * sizeof(decltype(_vertexArray)::value_type), &(_vertexArray[0]), GL_STATIC_DRAW);

    GLWindow::m_funcs->glGenBuffers(1, &_ebo);
    GLWindow::m_funcs->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    GLWindow::m_funcs->glBufferData(GL_ELEMENT_ARRAY_BUFFER, _elementArray.size() * sizeof(decltype(_vertexArray)::value_type), &(_elementArray[0]), GL_STATIC_DRAW);

    int numberFloatsPerVertex = 3 + (3 * _hasNormals) + (2 * _hasTexture); // there are always the 3 coord of the vertex
    GLWindow::m_funcs->glVertexAttribPointer(VERTEX_LOCATION_, 3, GL_FLOAT, GL_FALSE, numberFloatsPerVertex * sizeof(decltype(_vertexArray)::value_type), (void*)0); // vertex
    if (_hasNormals) {
	GLWindow::m_funcs->glVertexAttribPointer(NORMAL_LOCATION_, 3, GL_FLOAT, GL_FALSE, numberFloatsPerVertex * sizeof(decltype(_vertexArray)::value_type), (void*)(3 * sizeof(decltype(_vertexArray)::value_type))); //normal
    }
    if (_hasTexture) {
	GLWindow::m_funcs->glVertexAttribPointer(UV_LOCATION_, 2, GL_FLOAT, GL_FALSE, numberFloatsPerVertex * sizeof(decltype(_vertexArray)::value_type), (void*)(6 * sizeof(decltype(_vertexArray)::value_type))); //uv
    }
}

void GPUBuffer::setBuffer() {
    if (_vbo) {
	GLWindow::m_funcs->glDeleteBuffers(1, &_vbo);
    }
    regenVboEbo();
}

GPUBuffer::~GPUBuffer() {
    GPUFree();
}

void GPUBuffer::GPUFree() {
    GLWindow::m_funcs->glDeleteBuffers(1, &_vbo);
    GLWindow::m_funcs->glDeleteBuffers(1, &_ebo);
}

void GPUBuffer::CPUFree() {
    _vertexArray.clear();
    _elementArray.clear();
}

void GPUBuffer::draw(GLenum drawStyle_) const {
    GLWindow::m_funcs->glEnableVertexAttribArray(VERTEX_LOCATION_); // enable vertex shader parameter value
    GLWindow::m_funcs->glEnableVertexAttribArray(NORMAL_LOCATION_); // enable normal shader parameter value
    GLWindow::m_funcs->glEnableVertexAttribArray(UV_LOCATION_);

    GLWindow::m_funcs->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    // draw the polygon with the shader on the OpenGL draw buffer
    GLWindow::m_funcs->glDrawElements(drawStyle_, _elementArray.size(), GL_UNSIGNED_INT, 0);
    GLWindow::m_funcs->glDisableVertexAttribArray(VERTEX_LOCATION_);
    GLWindow::m_funcs->glDisableVertexAttribArray(NORMAL_LOCATION_);
    GLWindow::m_funcs->glDisableVertexAttribArray(UV_LOCATION_);
}
