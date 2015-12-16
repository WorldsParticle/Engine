#include    "Mesh.hpp"
#include    "glwindow.h"

namespace   WorldParticles
{
    namespace   Engine
    {

        Mesh::Mesh(void)
        {
            // nothing to do
        }

        /// TODO check si plusieurs type de primitives différente sont présente & si elles sont soit TRIANGLE, soit LINE, soit POINT.
        Mesh::Mesh(const aiMesh *am)
        {
            if (am == nullptr) throw std::invalid_argument("assimpMesh is null.");
            this->_name = am->mName.C_Str();
            if (am->HasPositions()) {
                this->setVertices(am->mVertices, am->mNumVertices);
            }
            if (am->HasNormals()) {
                this->setNormals(am->mNormals, am->mNumVertices);
            }
            if (am->HasFaces()) {
                this->setIndices(am->mFaces, am->mNumFaces);
            }
        }

        Mesh::~Mesh(void)
        {

        }


        void
        Mesh::setVertices(const aiVector3D *vertices, unsigned int numberElements)
        {
            if (vertices == nullptr) throw std::invalid_argument("vertices is null");
            auto convert = [&](const aiVector3D &v){return glm::vec3(v.x, v.y, v.z);};
            this->_vertices.clear();
            this->_vertices.reserve(numberElements);
            for (unsigned int i = 0 ; i < numberElements ; ++i) {
                 this->_vertices.push_back(convert(vertices[i]));
            }
        }

        void
        Mesh::setNormals(const aiVector3D *normals, unsigned int numberElements)
        {
            if (normals == nullptr) throw std::invalid_argument("normals is null");
            auto convert = [&](const aiVector3D &v){return glm::vec3(v.x, v.y, v.z);};
            this->_normals.clear();
            this->_normals.reserve(numberElements);
            for (unsigned int i = 0 ; i < numberElements ; ++i) {
                 this->_normals.push_back(convert(normals[i]));
            }
        }

        void
        Mesh::setIndices(const std::vector<unsigned int> &indices)
        {

        }

        void
        Mesh::setIndices(const aiFace *faces, unsigned int numberElements)
        {
            if (faces == nullptr) throw std::invalid_argument("faces is null");
            this->_indices.clear();
            this->_indices.reserve(numberElements * 3);
            for (unsigned int i = 0 ; i < numberElements ; ++i) {
                for (unsigned int j = 0 ; j < faces[i].mNumIndices ; ++j) {
                     this->_indices.push_back(faces[i].mIndices[j]);
                }
            }
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

