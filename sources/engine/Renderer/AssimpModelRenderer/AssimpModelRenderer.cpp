#include "AssimpModelRenderer.hpp"
#include <glm/ext.hpp>

#include <QOpenGLContext>
#include <QtOpenGL>
#include <QtOpenGL/QGLFunctions>
#include "glwindow.h"
#include "qopenglcontext.h"
#include <iostream>

#define VERTEX_LOCATION_ 0
#define NORMAL_LOCATION_ 1
#define UV_LOCATION_ 2

AssimpModelRenderer::AssimpModelRenderer() : _vbo(0), _ebo(0), _hasNormals(false), _hasTexture(false) {
}

AssimpModelRenderer::~AssimpModelRenderer() {
    GLWindow::m_funcs->glDeleteBuffers(1, &_vbo);
    GLWindow::m_funcs->glDeleteBuffers(1, &_ebo);
}

AssimpModelRenderer::AssimpModelRenderer(const AssimpModelRenderer& o_) : _vbo(o_._vbo), _ebo(o_._ebo), _hasNormals(o_._hasNormals), _hasTexture(o_._hasTexture) {
    if (_vbo == 0) {
	_vertexArray = o_._vertexArray;
    }
    if (_ebo == 0) {
	_elementArray = o_._elementArray;
    }
}

void AssimpModelRenderer::operator=(const AssimpModelRenderer& o_) {
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

void AssimpModelRenderer::regenVboEbo() {
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

void AssimpModelRenderer::setBuffer() {
    if (_vbo) {
	GLWindow::m_funcs->glDeleteBuffers(1, &_vbo);
    }
    regenVboEbo();
}

void AssimpModelRenderer::Draw(const Mesh &mesh,
	Material &material,
	const glm::mat4 &projection,
	const glm::mat4 &view,
	const glm::mat4 &model)
{
    QOpenGLShaderProgram shaderProgram;
    GLWindow::m_funcs->glEnableVertexAttribArray(VERTEX_LOCATION_); // enable vertex shader parameter value
    GLWindow::m_funcs->glEnableVertexAttribArray(NORMAL_LOCATION_); // enable normal shader parameter value
    GLWindow::m_funcs->glEnableVertexAttribArray(UV_LOCATION_);

    GLWindow::m_funcs->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, _ebo);
    GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, _vbo);

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, RESOURCES_PATH "/shaders/default.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, RESOURCES_PATH "/shaders/default.frag");
    shaderProgram.link();
    shaderProgram.create();

    shaderProgram.bind();


    glm::mat4 MVP = projection * view * model;

    int location = shaderProgram.uniformLocation("MVP");
    std::cout << location << std::endl;
    shaderProgram.setUniformValue(location, QMatrix4x4(&MVP[0][0]).transposed());

    // draw the polygon with the shader on the OpenGL draw buffer
    GLWindow::m_funcs->glDrawElements(GL_TRIANGLES, _elementArray.size(), GL_UNSIGNED_INT, 0);
    GLWindow::m_funcs->glDisableVertexAttribArray(VERTEX_LOCATION_);
    GLWindow::m_funcs->glDisableVertexAttribArray(NORMAL_LOCATION_);
    GLWindow::m_funcs->glDisableVertexAttribArray(UV_LOCATION_);
}

/*void    AssimpModelRenderer::Draw(const Mesh &mesh,
	Material &material,
	const glm::mat4 &projection,
	const glm::mat4 &view,
	const glm::mat4 &model)
{
    const std::vector<glm::vec3> &vertices = mesh.GetVertices();
    QOpenGLShaderProgram shaderProgram;

    GLuint vbo;
    GLWindow::m_funcs->glGenBuffers(1, &vbo);
    GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
    GLWindow::m_funcs->glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

    GLWindow::m_funcs->glEnableVertexAttribArray(0);
    GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
    GLWindow::m_funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Vertex, RESOURCES_PATH "/shaders/default.vert");
    shaderProgram.addShaderFromSourceFile(QOpenGLShader::Fragment, RESOURCES_PATH "/shaders/default.frag");
    shaderProgram.link();
    shaderProgram.create();

    shaderProgram.bind();


    glm::mat4 MVP = projection * view * model;

    int location = shaderProgram.uniformLocation("MVP");
    std::cout << location << std::endl;
    shaderProgram.setUniformValue(location, QMatrix4x4(&MVP[0][0]).transposed());

    GLWindow::m_funcs->glDrawArrays(GL_TRIANGLES, 0, 3 * vertices.size());
    GLWindow::m_funcs->glDisableVertexAttribArray(0);
}*/
