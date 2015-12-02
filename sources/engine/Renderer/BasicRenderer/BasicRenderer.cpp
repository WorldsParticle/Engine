#include    "BasicRenderer.hpp"

#include    "glwindow.h"

#include    <glm/gtc/type_ptr.hpp>
#include    <QOpenGLShaderProgram>

namespace WorldParticles
{
    namespace Engine
    {

        BasicRenderer::BasicRenderer(void)
        {
        }

        BasicRenderer::~BasicRenderer(void)
        {
        }

        void    BasicRenderer::Draw(const Mesh &mesh,
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
            shaderProgram.setUniformValue(location, QMatrix4x4(&MVP[0][0]).transposed());

            GLWindow::m_funcs->glDrawArrays(GL_TRIANGLES, 0, 3*vertices.size());
            GLWindow::m_funcs->glDisableVertexAttribArray(0);

        }

    }
}
