
#include    <log4cpp/Category.hh>

#include    "Mesh.hpp"

using namespace log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {

        Mesh::Mesh(void)
            /*arrayObject(std::make_shared<ArrayObject>())*/
        {
            // nothing to do
        }

        /// TODO check si plusieurs type de primitives différente sont présente & si elles sont soit TRIANGLE, soit LINE, soit POINT.
        Mesh::Mesh(const aiMesh *am)
            /*arrayObject(std::make_shared<ArrayObject>())*/
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
            this->update();
        }

        Mesh::~Mesh(void)
        {

        }


        ///
        /// PUBLIC METHOD
        ///

        /// TODO Optimisations
        void
        Mesh::update(void)
        {
/*            if (!this->vertexBuffer) {*/
                /*this->vertexBuffer = std::make_shared<BufferObject>(*/
                        /*BufferObject::Type::ARRAY_BUFFER,*/
                        /*BufferObject::Usage::STATIC_DRAW*/
                /*);*/
            /*}*/
            /*if (!this->elementBuffer && !this->indices.empty()) {*/
                /*this->elementBuffer = std::make_shared<BufferObject>(*/
                        /*BufferObject::Type::ELEMENT_ARRAY_BUFFER,*/
                        /*BufferObject::Usage::STATIC_DRAW*/
                /*);*/
            /*}*/
/*            this->arrayObject->bind();*/
            /*float *data = reinterpret_cast<float *>(this->positions.data());*/
            /*std::vector<float>  vertices(data, data + this->positions.size() * 3);*/
            /*data = reinterpret_cast<float *>(this->normals.data());*/
            /*vertices.insert(vertices.end(), data, data + this->normals.size() * 3);*/
            /*this->vertexBuffer->update(vertices.data(), vertices.size() * sizeof(float));*/
            /*this->vertexBuffer->bind();*/
            /*GLWindow::m_funcs->glEnableVertexAttribArray(0);*/
            /*GLWindow::m_funcs->glEnableVertexAttribArray(1);*/
            /*GLWindow::m_funcs->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (void *)0);*/
            /*GLWindow::m_funcs->glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, (void *)(this->positions.size() * 3 * sizeof(float)));*/
            /*this->vertexBuffer->unbind();*/
            /*if (!this->indices.empty()) {*/
                /*this->elementBuffer->update(this->indices.data(), this->indices.size() * sizeof(int));*/
                /*this->elementBuffer->bind();*/
            /*}*/
            /*this->arrayObject->unbind();*/
            this->updated = true;
        }

        void
        Mesh::bind(void)
        {
            /*this->arrayObject->bind();*/
        }

        void
        Mesh::unbind(void)
        {
            /*this->arrayObject->unbind();*/
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

    }
}

