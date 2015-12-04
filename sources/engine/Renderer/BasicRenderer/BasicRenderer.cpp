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

        void    BasicRenderer::Draw(const std::shared_ptr<Mesh> &mesh,
                const Material &material,
                const glm::mat4 &projection,
                const glm::mat4 &view,
                const glm::mat4 &model)
        {
            const std::shared_ptr<ShaderProgram>    &shaderProgram = material.GetShaderProgram();
            const std::vector<glm::vec3>            &vertices = mesh->GetVertices();

            GLuint vbo;
            GLWindow::m_funcs->glGenBuffers(1, &vbo);
            GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
            GLWindow::m_funcs->glBufferData(GL_ARRAY_BUFFER, vertices.size() * sizeof(glm::vec3), vertices.data(), GL_STATIC_DRAW);

            GLWindow::m_funcs->glEnableVertexAttribArray(0);
            GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
            GLWindow::m_funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);

            shaderProgram->Bind();

            shaderProgram->SetUniform("MVP", projection * view * model);

            //shaderProgram->SetUniform("projection", projection);
            //shaderProgram->SetUniform("modelview", view * model);

            GLWindow::m_funcs->glDrawArrays(GL_TRIANGLES, 0, 3 * vertices.size());
            GLWindow::m_funcs->glDisableVertexAttribArray(0);

            shaderProgram->Unbind();

        }

    }
}
