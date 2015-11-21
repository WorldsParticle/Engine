#include    "CubeRenderer.hpp"
#include <glm/ext.hpp>

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


<<<<<<< HEAD
    GLuint VertexShaderID = GLWindow::m_funcs->glCreateShader(GL_VERTEX_SHADER);
    GLuint FragmentShaderID = GLWindow::m_funcs->glCreateShader(GL_FRAGMENT_SHADER);

    char *vert = "#version 420\n"
                 "layout(location = 0) in vec3 position;\n"
                 "uniform mat4 mvp;\n"
                 "void main(void) {\n"
                 "  gl_Position = mvp * vec4(position, 1.0);\n"
                 "}\n";
    GLWindow::m_funcs->glShaderSource(VertexShaderID, 1, &vert,NULL);
    GLWindow::m_funcs->glCompileShader(VertexShaderID);
    GLint Result = GL_FALSE;
    int InfoLogLength;

    GLWindow::m_funcs->glGetShaderiv(VertexShaderID, GL_COMPILE_STATUS, &Result);
    GLWindow::m_funcs->glGetShaderiv(VertexShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        GLWindow::m_funcs->glGetShaderInfoLog(VertexShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        std::cout << (char *)(&VertexShaderErrorMessage[0]) << std::endl;
    }

    char *frag = "#version 420\n"
                 "out vec3 color;\n"
                 "void main(void) {\n"
                 "  color = vec3(1.0, 0.0, 0.0);\n"
                 "}\n";
    GLWindow::m_funcs->glShaderSource(FragmentShaderID, 1, &frag,NULL);
    GLWindow::m_funcs->glCompileShader(FragmentShaderID);

    GLWindow::m_funcs->glGetShaderiv(FragmentShaderID, GL_COMPILE_STATUS, &Result);
    GLWindow::m_funcs->glGetShaderiv(FragmentShaderID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> VertexShaderErrorMessage(InfoLogLength+1);
        GLWindow::m_funcs->glGetShaderInfoLog(FragmentShaderID, InfoLogLength, NULL, &VertexShaderErrorMessage[0]);
        std::cout << (char *)(&VertexShaderErrorMessage[0]) << std::endl;
    }

    GLuint ProgramID = GLWindow::m_funcs->glCreateProgram();
    GLWindow::m_funcs->glAttachShader(ProgramID, VertexShaderID);
    GLWindow::m_funcs->glAttachShader(ProgramID, FragmentShaderID);
    GLWindow::m_funcs->glLinkProgram(ProgramID);

    GLWindow::m_funcs->glGetProgramiv(ProgramID, GL_LINK_STATUS, &Result);
    GLWindow::m_funcs->glGetProgramiv(ProgramID, GL_INFO_LOG_LENGTH, &InfoLogLength);
    if ( InfoLogLength > 0 ){
        std::vector<char> ProgramErrorMessage(InfoLogLength+1);
        GLWindow::m_funcs->glGetProgramInfoLog(ProgramID, InfoLogLength, NULL, &ProgramErrorMessage[0]);
        std::cout << (char *)(&ProgramErrorMessage[0]) << std::endl;
    }

    GLWindow::m_funcs->glDetachShader(ProgramID, VertexShaderID);
    GLWindow::m_funcs->glDetachShader(ProgramID, FragmentShaderID);

    GLWindow::m_funcs->glDeleteShader(VertexShaderID);
    GLWindow::m_funcs->glDeleteShader(FragmentShaderID);
    GLWindow::m_funcs->glUseProgram(ProgramID);

    glm::mat4 MVP = projection * view * model;

    GLWindow::m_funcs->glUniformMatrix4fv(GLWindow::m_funcs->glGetUniformLocation(ProgramID, "mvp"), 1, GL_FALSE, glm::value_ptr(MVP));
=======
    glm::mat4 MVP = projection * view * model;

    int location = shaderProgram.uniformLocation("MVP");
    std::cout << location << std::endl;
    shaderProgram.setUniformValue(location, QMatrix4x4(&MVP[0][0]).transposed());
>>>>>>> origin/master

    GLWindow::m_funcs->glDrawArrays(GL_TRIANGLES, 0, 3 * vertices.size());
    GLWindow::m_funcs->glDisableVertexAttribArray(0);


<<<<<<< HEAD
=======


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


>>>>>>> origin/master
}
