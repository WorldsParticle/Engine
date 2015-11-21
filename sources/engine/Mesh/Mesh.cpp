#include <istream>
#include <fstream>
#include <iostream>

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>

#include "Mesh.hpp"

Mesh::Mesh() : _vertexArray(0) {
    std::cout << "add mesh " << std::endl;
}

void Mesh::set(const GPUBuffer& b_)
{
    _gb = b_;
    uploadBuffer();
}

void Mesh::fromFile(const std::string& fname_) {
    Assimp::Importer importer;

    std::ifstream fin(fname_.c_str());
    if (!fin.fail()) {
	fin.close();
    } else {
	std::cout << "Couldn't open file: " << fname_ << std::endl;
	if (fin.badbit) {
	    std::cout << "badbit" << std::endl;
	}
	return;
    }
    const aiScene* scene = importer.ReadFile(fname_.c_str(), aiProcessPreset_TargetRealtime_Quality | aiProcess_Triangulate);
    if (!scene) {
	std::cout << importer.GetErrorString() << std::endl;
	return;
    }

    _gb.getVertexArray().clear();
    _gb.getElementArray().clear();
    _getAllFaces(scene, scene->mRootNode);
    importer.FreeScene();

    _gb.setBuffer();
    uploadBuffer();
}

void Mesh::_getAllFaces(const struct aiScene *sc, const struct aiNode* nd) {
    if (!_gb.getVertexArray().empty()) {
	return;
    }
    unsigned int n = 0;
    decltype(_gb.getVertexArray())&& vertexArray = _gb.getVertexArray();
    decltype(_gb.getElementArray())&& elementArray = _gb.getElementArray();

    for (; n < nd->mNumMeshes; ++n) {
	const struct aiMesh* mesh = sc->mMeshes[nd->mMeshes[n]];
	if (vertexArray.size() + mesh->mNumFaces * 6 > vertexArray.capacity()) {
	    vertexArray.reserve(vertexArray.capacity() + mesh->mNumFaces * 8);
	}
	for (unsigned int i = 0; i < mesh->mNumVertices; ++i) {
	    vertexArray.push_back(mesh->mVertices[i].z);
	    vertexArray.push_back(mesh->mVertices[i].y);
	    vertexArray.push_back(mesh->mVertices[i].x);
	    if (mesh->HasNormals()) {
		vertexArray.push_back(mesh->mNormals[i].z);
		vertexArray.push_back(mesh->mNormals[i].y);
		vertexArray.push_back(mesh->mNormals[i].x);
		_gb.setHasNormals(true);
	    }
	    if (mesh->HasTextureCoords(0)) {
		vertexArray.push_back(mesh->mTextureCoords[0][i].x);
		vertexArray.push_back(mesh->mTextureCoords[0][i].y);
		_gb.setHasTexture(true);
	    }
	}
	if (elementArray.size() + mesh->mNumFaces > elementArray.capacity()) {
	    elementArray.reserve(elementArray.capacity() + mesh->mNumFaces);
	}
	for (unsigned int t = 0; t < mesh->mNumFaces; ++t) {
	    const struct aiFace* face = &mesh->mFaces[t];
	    for (unsigned int i = 0; i < face->mNumIndices; i++) { // go through all vertices in face
		unsigned int tmp = face->mIndices[i];
		elementArray.push_back(tmp);
	    }
	}
    }
    for (n = 0; n < nd->mNumChildren; ++n) {
	_getAllFaces(sc, nd->mChildren[n]);
    }
}

void Mesh::render() const
{
    _gb.draw(GL_TRIANGLES);
}

void Mesh::uploadBuffer()
{
    _gb.regenVboEbo();
}
