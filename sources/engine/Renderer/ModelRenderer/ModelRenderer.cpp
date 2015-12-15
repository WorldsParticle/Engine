
#include    "ModelRenderer.hpp"

namespace   WorldParticles
{
    namespace   Engine
    {
        ModelRenderer::ModelRenderer(void)
        {

        }

        ModelRenderer::~ModelRenderer(void)
        {

        }

        void
        ModelRenderer::draw(const GameObject *gameobject,
                const glm::mat4 &projection,
                const glm::mat4 &view,
                const glm::mat4 &model)
        {
            const Material  *material = gameobject->getMaterial();
            const Mesh      *mesh = gameobject->getMesh();
            auto            &shaderProgram = material->GetShaderProgram();
            auto            &vertices = mesh->GetVertices();
            auto            &indices = mesh->getIndices();

            shaderProgram->Bind();

            shaderProgram->SetUniform("model", model);
            shaderProgram->SetUniform("view", view);
            shaderProgram->SetUniform("projection", projection);

            mesh->bind();
            GLWindow::m_funcs->glDrawElements(GL_TRIANGLES, indices.size(), GL_UNSIGNED_INT, 0);
            mesh->unbind();
            shaderProgram->Unbind();
        }
    }
}
