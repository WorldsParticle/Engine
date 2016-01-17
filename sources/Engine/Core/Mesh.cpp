///
/// \file Mesh.cpp
///
/// \author Martin-Pierrat Louis (mart_p)
///
/// \date Sat, 16 Jan 2016 20:48:36
///
/// \version 1.0.7
///

#include    <GL/glew.h>
#include    <log4cpp/Category.hh>

#include    <Engine/Mesh.hpp>
#include    <Engine/Material.hpp>
#include    <Engine/ShaderProgram.hpp>

using namespace log4cpp;

namespace   WorldParticles
{
    namespace   Engine
    {

        Mesh::Mesh(Material *material) :
            vertexBuffer(std::make_shared<BufferObject>(
                        BufferObject::Type::ARRAY_BUFFER,
                        BufferObject::Usage::STATIC_DRAW)),
            elementBuffer(std::make_shared<BufferObject>(
                        BufferObject::Type::ELEMENT_ARRAY_BUFFER,
                        BufferObject::Usage::STATIC_DRAW)),
            arrayObject(std::make_shared<ArrayObject>()),
            material(material)
        {
            // nothing to do
        }

        /// TODO check si plusieurs type de primitives différente sont présente & si elles sont soit TRIANGLE, soit LINE, soit POINT.
        Mesh::Mesh(const aiMesh *am, Material *material) :
            vertexBuffer(std::make_shared<BufferObject>(
                        BufferObject::Type::ARRAY_BUFFER,
                        BufferObject::Usage::STATIC_DRAW)),
            elementBuffer(std::make_shared<BufferObject>(
                        BufferObject::Type::ELEMENT_ARRAY_BUFFER,
                        BufferObject::Usage::STATIC_DRAW)),
            arrayObject(std::make_shared<ArrayObject>()),
            material(material)
        {
            this->name = am->mName.C_Str();
            this->setPositions(am->mVertices, am->mNumVertices);
            this->setNormals(am->mNormals, am->mNumVertices);
            if (am->HasTextureCoords(0))
                this->setUVs(am->mTextureCoords[0], am->mNumUVComponents[0]);
            this->setIndices(am->mFaces, am->mNumFaces);
            this->update();
        }

        Mesh::~Mesh(void)
        {

        }


        /// TODO rework, c'est totalmenet dégeulasse.
        void
        Mesh::update(void)
        {

            std::vector<float>  vertices = this->positions;
            if (this->hasNormals())
                vertices.insert(vertices.end(), this->normals.begin(), this->normals.end());
            if (this->hasUVs())
                vertices.insert(vertices.end(), this->uvs.begin(), this->uvs.end());
            this->vertexBuffer->update(vertices.data(), vertices.size() * sizeof(float));
            if (this->hasIndices())
                this->elementBuffer->update(this->indices.data(), this->indices.size() * sizeof(int));

            this->arrayObject->bind();

            this->vertexBuffer->bind();
            glEnableVertexAttribArray(0);
            glEnableVertexAttribArray(1);
            glEnableVertexAttribArray(2);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE,
                0, (void *)0);
            if (this->hasNormals()) {
                glVertexAttribPointer(1, 3, GL_FLOAT,
                    GL_FALSE, 0, (void *)(this->positions.size() * sizeof(float)));
            }
            if (this->hasUVs()) {
                glVertexAttribPointer(2, 2, GL_FLOAT,
                    GL_FALSE, 0, (void *)((this->positions.size()
                        + this->normals.size()) * sizeof(float)));
            }
            if (this->hasIndices())
                this->elementBuffer->bind();

            this->arrayObject->unbind();

            this->vertexBuffer->unbind();

            if (this->hasIndices())
                this->elementBuffer->unbind();
        }

        void
        Mesh::bind(void) const
        {
            this->arrayObject->bind();
        }

        void
        Mesh::unbind(void) const
        {
            this->arrayObject->unbind();
        }

        void
        Mesh::draw(const glm::mat4 &model, const glm::mat4 &view,
            const glm::mat4 &projection) const
        {
            const auto &shaderprogram = this->material->getShaderProgram();

            this->bind();
            this->material->bind();
            shaderprogram->setUniform("model", model);
            shaderprogram->setUniform("view", view);
            shaderprogram->setUniform("projection", projection);
            if (this->hasIndices())
            {
                glDrawElements(GL_TRIANGLES, this->indices.size(), GL_UNSIGNED_INT, 0);
            }
            else
            {
                glDrawArrays(GL_TRIANGLES, 0, this->positions.size());
            }
            this->material->unbind();
            this->unbind();
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
        Mesh::hasUVs(void) const
        {
            return !this->uvs.empty();
        }

        bool
        Mesh::hasIndices(void) const
        {
            return !this->indices.empty();
        }



        const std::vector<float> &
        Mesh::getPositions(void) const
        {
            return this->positions;
        }

        const std::vector<float> &
        Mesh::getNormals(void) const
        {
            return this->normals;
        }

        const std::vector<float> &
        Mesh::getUVs(void) const
        {
            return this->uvs;
        }

        const std::vector<unsigned int> &
        Mesh::getIndices(void) const
        {
            return this->indices;
        }



        void
        Mesh::setPositions(const std::vector<float> &positions)
        {
            this->positions = positions;
        }

        void
        Mesh::setNormals(const std::vector<float> &normals)
        {
            this->normals = normals;
        }

        void
        Mesh::setUVs(const std::vector<float> &uvs)
        {
            this->uvs = uvs;
        }

        void
        Mesh::setIndices(const std::vector<unsigned int> &indices)
        {
            this->indices = indices;
        }



        void
        Mesh::setPositions(const aiVector3D *v, unsigned int numberElements)
        {
            this->positions.clear();
            this->positions.reserve(numberElements * 3);
            for (unsigned int i = 0 ; i < numberElements ; ++i)
            {
                 this->positions.push_back(v[i].x);
                 this->positions.push_back(v[i].y);
                 this->positions.push_back(v[i].z);
            }
        }

        void
        Mesh::setNormals(const aiVector3D *n, unsigned int numberElements)
        {
            this->normals.clear();
            this->normals.reserve(numberElements * 3);
            for (unsigned int i = 0 ; i < numberElements ; ++i)
            {
                 this->normals.push_back(n[i].x);
                 this->normals.push_back(n[i].y);
                 this->normals.push_back(n[i].z);
            }
        }

        void
        Mesh::setUVs(const aiVector3D *u, unsigned int numberElements)
        {
            this->uvs.clear();
            this->uvs.reserve(numberElements * 3);
            for (unsigned int i = 0 ; i < numberElements ; ++i)
            {
                this->uvs.push_back(u[i].x);
                this->uvs.push_back(u[i].y);
                this->uvs.push_back(u[i].z);
            }
        }

        void
        Mesh::setIndices(const aiFace *faces, unsigned int numberElements)
        {
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

