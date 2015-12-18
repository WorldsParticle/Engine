#include    "Mesh.hpp"
#include    "glwindow.h"

namespace   WorldParticles
{
    namespace   Engine
    {

        ///
        /// PUBLIC CONSTRUCTORS
        ///

        Mesh::Mesh(void)
        {
            // nothing to do
        }

        /// TODO check si plusieurs type de primitives différente sont présente & si elles sont soit TRIANGLE, soit LINE, soit POINT.
        Mesh::Mesh(const aiMesh *am)
        {
            if (am == nullptr) throw std::invalid_argument("assimpMesh is null.");
            this->name = am->mName.C_Str();
            if (am->HasPositions()) {
                this->setPositions(am->mVertices, am->mNumVertices);
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


        ///
        /// PUBLIC METHOD
        ///

        void
        Mesh::update(void)
        {
            if (!this->vertexBuffer)
                this->vertexBuffer = std::make_shared<BufferObject>();
            if (!this->elementBuffer && !this->indices.empty())
                this->elementBuffer = std::make_shared<BufferObject>();

            std::vector<float>  vertices;
/*            std::vector<float> vertices = this->positions;*/
            //vertices.insert(vertices.end(), this->normals.begin(), this->normals.end());

            //this->vertexBuffer->setData(vertices);
            /*this->elementBuffer->setData(this->indices);*/
            this->updated = true;
        }

        void
        Mesh::bind(void)
        {
            if (this->vertexBuffer) this->vertexBuffer->bind();
            if (this->elementBuffer) this->elementBuffer->bind();
        }

        void
        Mesh::unbind(void)
        {
            if (this->vertexBuffer) this->vertexBuffer->unbind();
            if (this->elementBuffer) this->elementBuffer->unbind();
        }


        bool
        Mesh::hasPositions(void) const
        {
            return !this->positions.empty();
        }

        bool
        Mesh::hasNormals(void) const
        {
             return !this->normals.empty();
        }

        bool
        Mesh::hasIndices(void) const
        {
            return !this->indices.empty();
        }

        ///
        /// PUBLIC GETTER
        ///

        const std::vector<glm::vec3> &
        Mesh::getPositions(void) const
        {
            return this->positions;
        }

        const std::vector<glm::vec3> &
        Mesh::getNormals(void) const
        {
            return this->normals;
        }

        const std::vector<unsigned int> &
        Mesh::getIndices(void) const
        {
            return this->indices;
        }

        ///
        /// PUBLIC SETTER
        ///

        void
        Mesh::setPositions(const std::vector<glm::vec3> &positions)
        {
            this->positions = positions;
        }

        void
        Mesh::setNormals(const std::vector<glm::vec3> &normals)
        {
            this->normals = normals;
        }

        void
        Mesh::setIndices(const std::vector<unsigned int> &indices)
        {
            this->indices = indices;
        }

        ///
        /// PRIVATE SETTER
        ///

        void
        Mesh::setPositions(const aiVector3D *positions, unsigned int numberElements)
        {
            if (positions == nullptr) throw std::invalid_argument("positions is null");
            auto convert = [&](const aiVector3D &v){ return glm::vec3(v.x, v.y, v.z); };
            this->positions.clear();
            this->positions.reserve(numberElements);
            for (unsigned int i = 0 ; i < numberElements ; ++i) {
                 this->positions.push_back(convert(positions[i]));
            }
        }

        void
        Mesh::setNormals(const aiVector3D *normals, unsigned int numberElements)
        {
            if (normals == nullptr) throw std::invalid_argument("normals is null");
            auto convert = [&](const aiVector3D &v) { return glm::vec3(v.x, v.y, v.z); };
            this->normals.clear();
            this->normals.reserve(numberElements);
            for (unsigned int i = 0 ; i < numberElements ; ++i) {
                 this->normals.push_back(convert(normals[i]));
            }
        }

        void
        Mesh::setIndices(const aiFace *faces, unsigned int numberElements)
        {
            if (faces == nullptr) throw std::invalid_argument("faces is null");
            this->indices.clear();
            this->indices.reserve(numberElements * 3);
            for (unsigned int i = 0 ; i < numberElements ; ++i) {
                if (faces[i].mNumIndices == 3)
                {
                     this->indices.push_back(faces[i].mIndices[0]);
                     this->indices.push_back(faces[i].mIndices[1]);
                     this->indices.push_back(faces[i].mIndices[2]);
                }
            }
        }

/*        void*/
        //Mesh::initialise(void)
        //{
            //GLWindow::m_funcs->glGenBuffers(1, &vbo);
            //GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
            //GLWindow::m_funcs->glBufferData(GL_ARRAY_BUFFER,
                    //_vertices.size() * sizeof(glm::vec3), _vertices.data(), GL_STATIC_DRAW);
            //GLWindow::m_funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);

            //GLWindow::m_funcs->glGenBuffers(1, &vbo_normals);
            //GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
            //GLWindow::m_funcs->glBufferData(GL_ARRAY_BUFFER,
                    //_normals.size() * sizeof(glm::vec3), _normals.data(), GL_STATIC_DRAW);
            //GLWindow::m_funcs->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, 0);

            //GLWindow::m_funcs->glGenBuffers(1, &element_buffer);
            //GLWindow::m_funcs->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
            //GLWindow::m_funcs->glBufferData(GL_ELEMENT_ARRAY_BUFFER,
                    //_indices.size() * sizeof(unsigned int), _indices.data(), GL_STATIC_DRAW);
       //}

        //void
        //Mesh::bind(void) const
        //{
            //GLWindow::m_funcs->glEnableVertexAttribArray(0);
            //GLWindow::m_funcs->glEnableVertexAttribArray(1);

            //GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo);
            //GLWindow::m_funcs->glBindBuffer(GL_ARRAY_BUFFER, vbo_normals);
            //GLWindow::m_funcs->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, element_buffer);
        //}

        //void
        //Mesh::unbind(void) const
        //{
            //GLWindow::m_funcs->glDisableVertexAttribArray(0);
            //GLWindow::m_funcs->glDisableVertexAttribArray(1);
        /*}*/

    }
}

