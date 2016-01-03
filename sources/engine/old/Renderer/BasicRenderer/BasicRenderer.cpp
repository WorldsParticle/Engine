#include    "BasicRenderer.hpp"
#include    "glwindow.h"

#include    <glm/gtc/type_ptr.hpp>
#include    <QOpenGLShaderProgram>
#include    <log4cpp/Category.hh>

using namespace log4cpp;

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
                const auto      &shaderProgram = gameobject->getShaderProgram();
                const auto      &material = gameobject->getMaterial();
                const auto      &mesh = gameobject->getMesh();

                if (shaderProgram && mesh && material)
                {
                    shaderProgram->bind();
                    shaderProgram->setUniform("projection", projection);
                    shaderProgram->setUniform("view", view);
                    shaderProgram->setUniform("model", model);
                    mesh->bind();
                    if (mesh->hasIndices())
                    {
                        GLWindow::m_funcs->glDrawElements(GL_TRIANGLES,
                                mesh->getIndices().size(), GL_UNSIGNED_INT, 0);
                    }
                    else
                    {
                        GLWindow::m_funcs->glDrawArrays(GL_TRIANGLES, 0,
                                mesh->getPositions().size());
                    }
                    mesh->unbind();
                    shaderProgram->unbind();
                }
            }
        }

    }
}