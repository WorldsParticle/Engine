#include    "Mesh.hpp"
#include    "glwindow.h"

#include    <log4cpp/Category.hh>

using namespace     log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {

        Mesh::Mesh(const std::vector<glm::vec3> &vertices,
                const std::vector<glm::vec3> &uvs,
                const std::vector<glm::vec3> &normals) :
            _vertices(vertices),
            _uvs(uvs),
            _normals(normals)
        {


        }

        Mesh::~Mesh(void)
        {

        }

        void
        Mesh::initialise(void)
        {
            GLWindow::m_funcs->glGenBuffers(1, &vbo);
            GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
            GLWindow::m_funcs->glBufferData(GL_ARRAY_BUFFER,
                    _vertices.size() * sizeof(glm::vec3), _vertices.data(), GL_STATIC_DRAW);
            GLWindow::m_funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

            GLWindow::m_funcs->glGenBuffers(1, &vbo_normals);
            GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
            GLWindow::m_funcs->glBufferData(GL_ARRAY_BUFFER,
                    _normals.size() * sizeof(glm::vec3), _normals.data(), GL_STATIC_DRAW);
            GLWindow::m_funcs->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

            GLWindow::m_funcs->glGenBuffers(1, &element_buffer);
            GLWindow::m_funcs->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
            GLWindow::m_funcs->glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                    _indices.size() * sizeof(unsigned int), _indices.data(), GL_STATIC_DRAW);
       }

        void
        Mesh::bind(void) const
        {
            GLWindow::m_funcs->glEnableVertexAttribArray(0);
            GLWindow::m_funcs->glEnableVertexAttribArray(1);

            GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
            GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
            GLWindow::m_funcs->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
        }

        void
        Mesh::unbind(void) const
        {
            GLWindow::m_funcs->glDisableVertexAttribArray(0);
            GLWindow::m_funcs->glDisableVertexAttribArray(1);
        }

    }
}

