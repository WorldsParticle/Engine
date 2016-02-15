//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 3 of the License, or
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License along
// with this program; If not, see <http://www.gnu.org/licenses/>.
//
// Copyright (C) 2016 Martin-Pierrat Louis (louismartinpierrat@gmail.com)
//

/*#include    <GL/glew.h>*/
//#include    <log4cpp/Category.hh>

//#include    "Engine/Core/OldMesh.hpp"
//#include    "Engine/Core/Material.hpp"
//#include    "Engine/Core/ShaderProgram.hpp"

//using namespace log4cpp;

//namespace   Engine
//{

    //Mesh::Mesh(Material *material) :
        //m_name(""),
        //m_positions(),
        //m_normals(),
        //m_uvs(),
        //m_indices(),
        //m_vertexBuffer(std::make_shared<BufferObject>(
                    //BufferObject::Type::ARRAY_BUFFER,
                    //BufferObject::Usage::STATIC_DRAW)),
        //m_elementBuffer(std::make_shared<BufferObject>(
                    //BufferObject::Type::ELEMENT_ARRAY_BUFFER,
                    //BufferObject::Usage::STATIC_DRAW)),
        //m_arrayObject(std::make_shared<ArrayObject>()),
        //m_material(material)
    //{
        //// nothing to do
    //}

////#warning check si plusieurs type de primitives différente sont présente & si elles sont soit TRIANGLE, soit LINE, soit POINT.
    //Mesh::Mesh(const aiMesh *am, Material *material) :
        //m_name(""),
        //m_positions(),
        //m_normals(),
        //m_uvs(),
        //m_indices(),
        //m_vertexBuffer(std::make_shared<BufferObject>(
                    //BufferObject::Type::ARRAY_BUFFER,
                    //BufferObject::Usage::STATIC_DRAW)),
        //m_elementBuffer(std::make_shared<BufferObject>(
                    //BufferObject::Type::ELEMENT_ARRAY_BUFFER,
                    //BufferObject::Usage::STATIC_DRAW)),
        //m_arrayObject(std::make_shared<ArrayObject>()),
        //m_material(material)
    //{
        //this->m_name = am->mName.C_Str();
        //this->setPositions(am->mVertices, am->mNumVertices);
        //this->setNormals(am->mNormals, am->mNumVertices);
        //if (am->HasTextureCoords(0))
            //this->setUVs(am->mTextureCoords[0], am->mNumUVComponents[0]);
        //this->setIndices(am->mFaces, am->mNumFaces);
        //this->update();
    //}

    //Mesh::~Mesh(void)
    //{

    //}


////#warning rework, c est totalement dégeulasse.
    //void
    //Mesh::update(void)
    //{

        //std::vector<float>  vertices = this->m_positions;
        //if (this->hasNormals())
            //vertices.insert(vertices.end(), this->m_normals.begin(), this->m_normals.end());
        //if (this->hasUVs())
            //vertices.insert(vertices.end(), this->m_uvs.begin(), this->m_uvs.end());
        //this->m_vertexBuffer->update(vertices.data(), vertices.size() * sizeof(float));
        //if (this->hasIndices())
            //this->m_elementBuffer->update(this->m_indices.data(), this->m_indices.size() * sizeof(unsigned int));

        //this->m_arrayObject->bind();

        //this->m_vertexBuffer->bind();
        //glEnableVertexAttribArray(0);
        //glEnableVertexAttribArray(1);
        //glEnableVertexAttribArray(2);

        //std::uintptr_t pointer_offset = 0;
        //glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void *>(pointer_offset));
        //pointer_offset += this->m_positions.size() * sizeof(float);
        //if (this->hasNormals())
        //{
            //glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void *>(pointer_offset));
            //pointer_offset += this->m_normals.size() * sizeof(float);
        //}
        //if (this->hasUVs())
        //{
            //glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 0, reinterpret_cast<void *>(pointer_offset));
            //pointer_offset += this->m_uvs.size() * sizeof(float);
        //}
        //if (this->hasIndices())
            //this->m_elementBuffer->bind();

        //this->m_arrayObject->unbind();

        //this->m_vertexBuffer->unbind();

        //if (this->hasIndices())
            //this->m_elementBuffer->unbind();
    //}

    //void
    //Mesh::bind(void) const
    //{
        //this->m_arrayObject->bind();
    //}

    //void
    //Mesh::unbind(void) const
    //{
        //this->m_arrayObject->unbind();
    //}

    //void
    //Mesh::draw(const glm::mat4 &model, const glm::mat4 &view,
        //const glm::mat4 &projection) const
    //{
        //const auto &shaderprogram = this->m_material->getShaderProgram();

        //this->bind();
        //this->m_material->bind();
        //shaderprogram->setUniform("model", model);
        //shaderprogram->setUniform("view", view);
        //shaderprogram->setUniform("projection", projection);
        //if (this->hasIndices())
        //{
            //std::uintptr_t  pointer_offset = 0;
            //glDrawElements(GL_TRIANGLES, static_cast<int>(this->m_indices.size()), GL_UNSIGNED_INT, reinterpret_cast<void *>(pointer_offset));
        //}
        //else
        //{
            //glDrawArrays(GL_TRIANGLES, 0, static_cast<int>(this->m_positions.size()));
        //}
        //this->m_material->unbind();
        //this->unbind();
    //}



    //bool
    //Mesh::hasPositions(void) const
    //{
        //return !this->m_positions.empty();
    //}

    //bool
    //Mesh::hasNormals(void) const
    //{
         //return !this->m_normals.empty();
    //}

    //bool
    //Mesh::hasUVs(void) const
    //{
        //return !this->m_uvs.empty();
    //}

    //bool
    //Mesh::hasIndices(void) const
    //{
        //return !this->m_indices.empty();
    //}



    //const std::vector<float> &
    //Mesh::getPositions(void) const
    //{
        //return this->m_positions;
    //}

    //const std::vector<float> &
    //Mesh::getNormals(void) const
    //{
        //return this->m_normals;
    //}

    //const std::vector<float> &
    //Mesh::getUVs(void) const
    //{
        //return this->m_uvs;
    //}

    //const std::vector<unsigned int> &
    //Mesh::getIndices(void) const
    //{
        //return this->m_indices;
    //}



    //void
    //Mesh::setPositions(const std::vector<float> &positions)
    //{
        //this->m_positions = positions;
    //}

    //void
    //Mesh::setNormals(const std::vector<float> &normals)
    //{
        //this->m_normals = normals;
    //}

    //void
    //Mesh::setUVs(const std::vector<float> &uvs)
    //{
        //this->m_uvs = uvs;
    //}

    //void
    //Mesh::setIndices(const std::vector<unsigned int> &indices)
    //{
        //this->m_indices = indices;
    //}



    //void
    //Mesh::setPositions(const aiVector3D *v, unsigned int numberElements)
    //{
        //this->m_positions.clear();
        //this->m_positions.reserve(numberElements * 3);
        //for (unsigned int i = 0 ; i < numberElements ; ++i)
        //{
             //this->m_positions.push_back(v[i].x);
             //this->m_positions.push_back(v[i].y);
             //this->m_positions.push_back(v[i].z);
        //}
    //}

    //void
    //Mesh::setNormals(const aiVector3D *n, unsigned int numberElements)
    //{
        //this->m_normals.clear();
        //this->m_normals.reserve(numberElements * 3);
        //for (unsigned int i = 0 ; i < numberElements ; ++i)
        //{
             //this->m_normals.push_back(n[i].x);
             //this->m_normals.push_back(n[i].y);
             //this->m_normals.push_back(n[i].z);
        //}
    //}

    //void
    //Mesh::setUVs(const aiVector3D *u, unsigned int numberElements)
    //{
        //this->m_uvs.clear();
        //this->m_uvs.reserve(numberElements * 3);
        //for (unsigned int i = 0 ; i < numberElements ; ++i)
        //{
            //this->m_uvs.push_back(u[i].x);
            //this->m_uvs.push_back(u[i].y);
            //this->m_uvs.push_back(u[i].z);
        //}
    //}

    //void
    //Mesh::setIndices(const aiFace *faces, unsigned int numberElements)
    //{
        //this->m_indices.clear();
        //this->m_indices.reserve(numberElements * 3);
        //for (unsigned int i = 0 ; i < numberElements ; ++i) {
            //if (faces[i].mNumIndices == 3)
            //{
                 //this->m_indices.push_back(faces[i].mIndices[0]);
                 //this->m_indices.push_back(faces[i].mIndices[1]);
                 //this->m_indices.push_back(faces[i].mIndices[2]);
            //}
        //}
    //}

//}

