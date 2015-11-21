#include    "CubeRenderer.hpp"

#include    <QOpenGLContext>
#include <QtOpenGL>
#include <QtOpenGL/QGLFunctions>
#include    "glwindow.h"
#include "qopenglcontext.h"
#include <iostream>
#include <glm/gtc/type_ptr.hpp>

CubeRenderer::CubeRenderer()
{
}

void    CubeRenderer::Draw(const Mesh &mesh,
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

    GLWindow::m_funcs->glDrawArrays(GL_TRIANGLES, 0, 3);
    GLWindow::m_funcs->glDisableVertexAttribArray(0);


//    static const GLfloat g_vertex_buffer_data[] = {
//        -1.0f, -1.0f, 0.0f,
//        1.0f, -1.0f, 0.0f,
//        0.0f,  1.0f, 0.0f,
//     };


//    GLuint vertexbuffer;
//    GLWindow::m_funcs->glGenBuffers(1, &vertexbuffer);
//     // The following commands will talk about our 'vertexbuffer' buffer
//    GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//     // Give our vertices to OpenGL.
//    GLWindow::m_funcs->glBufferData(GL_ARRAY_BUFFER, sizeof(g_vertex_buffer_data), g_vertex_buffer_data, GL_STATIC_DRAW);

//    GLWindow::m_funcs->glEnableVertexAttribArray(0);
//    GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vertexbuffer);
//    GLWindow::m_funcs->glVertexAttribPointer(
//          0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
//          3,                  // size
//          GL_FLOAT,           // type
//         GL_FALSE,           // normalized?
//          0,                  // stride
//         (void*)0            // array buffer offset
//      );
//      // Draw the triangle !
//    GLWindow::m_funcs->glDrawArrays(GL_TRIANGLES, 0, 3); // Starting from vertex 0; 3 vertices total -> 1 triangle
//    GLWindow::m_funcs->glDisableVertexAttribArray(0);


}
