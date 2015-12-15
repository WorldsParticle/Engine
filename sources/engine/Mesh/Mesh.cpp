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
            GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, 0);
/*            Category &root = Category::getRoot();*/
            //void *vertices = _vertices.data();
            //float *test = static_cast<float *>(vertices);
            //for (unsigned int i = 0 ; i < _vertices.size()* 3 ; ++i)
            //{
                //root << Priority::DEBUG << test[i];
            /*}*/
        }

        void
        Mesh::bind(void) const
        {
            GLWindow::m_funcs->glEnableVertexAttribArray(0);
            GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
            GLWindow::m_funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
        }

        void
        Mesh::unbind(void) const
        {
            GLWindow::m_funcs->glDisableVertexAttribArray(0);
        }

    }
}

