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

        void    BasicRenderer::draw(const GameObject *gameobject,
                const glm::mat4 &projection,
                const glm::mat4 &view,
                const glm::mat4 &model)
        {
            if (gameobject != nullptr)
            {
                const Material  *material = gameobject->GetMaterial();
                const Mesh      *mesh = gameobject->GetMesh();

                if (mesh != nullptr && material != nullptr)
                {
                    auto        &shaderProgram = material->GetShaderProgram();
                    auto        &vertices = mesh->getVertices();

                    shaderProgram->Bind();

                    shaderProgram->SetUniform("projection", projection);
                    shaderProgram->SetUniform("view", view);
                    shaderProgram->SetUniform("model", model);

                    mesh->bind();

                    GLWindow::m_funcs->glDrawArrays(GL_TRIANGLES, 0, vertices.size());

                    mesh->unbind();

                    shaderProgram->Unbind();

                }
            }

        }

    }
}
