#include <istream>
#include <fstream>
#include <iostream>

#include <assimp/scene.h>
#include <assimp/Importer.hpp>
#include <assimp/postprocess.h>
#include <assimp/ProgressHandler.hpp>
#include "AssimpModel.hpp"

AssimpModel::AssimpModel(const glm::vec3 &position, const glm::vec3 &rotation, const glm::vec3 &scale) :
    GameObject(position, rotation, scale), _vertexArray(0)
{
    std::cout << "CreateMesh" << std::endl;

    fromFile("/models/monkey.dae");
    this->renderer = new AssimpModelRenderer();
}

void AssimpModel::Draw(const glm::mat4 &projection, const glm::mat4 &view)
{
    this->renderer->Draw(this->mesh,
                         this->material,
                         projection,
                         view,
                         this->transform.GetMatrix());
}

void AssimpModel::Update()
{
}

void AssimpModel::fromFile(const std::string& fname_) {
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

    renderer->getVertexArray().clear();
    renderer->getElementArray().clear();
    _getAllFaces(scene, scene->mRootNode);
    importer.FreeScene();

    renderer->setBuffer();
    renderer->regenVboEbo();
}

void AssimpModel::_getAllFaces(const struct aiScene *sc, const struct aiNode* nd) {
    if (!renderer->getVertexArray().empty()) {
	return;
    }
    unsigned int n = 0;
    decltype(renderer->getVertexArray())&& vertexArray = renderer->getVertexArray();
    decltype(renderer->getElementArray())&& elementArray = renderer->getElementArray();

    for (; n < nd->mNumMeshes; ++n) {
	const struct aiMesh* aMesh = sc->mMeshes[nd->mMeshes[n]];
	if (vertexArray.size() + aMesh->mNumFaces * 6 > vertexArray.capacity()) {
	    vertexArray.reserve(vertexArray.capacity() + aMesh->mNumFaces * 8);
	}
	for (unsigned int i = 0; i < aMesh->mNumVertices; ++i) {
	    vertexArray.push_back(aMesh->mVertices[i].z);
	    vertexArray.push_back(aMesh->mVertices[i].y);
	    vertexArray.push_back(aMesh->mVertices[i].x);
	    if (aMesh->HasNormals()) {
		vertexArray.push_back(aMesh->mNormals[i].z);
		vertexArray.push_back(aMesh->mNormals[i].y);
		vertexArray.push_back(aMesh->mNormals[i].x);
		renderer->setHasNormals(true);
	    }
	    if (aMesh->HasTextureCoords(0)) {
		vertexArray.push_back(aMesh->mTextureCoords[0][i].x);
		vertexArray.push_back(aMesh->mTextureCoords[0][i].y);
		renderer->setHasTexture(true);
	    }
	}
	if (elementArray.size() + aMesh->mNumFaces > elementArray.capacity()) {
	    elementArray.reserve(elementArray.capacity() + aMesh->mNumFaces);
	}
	for (unsigned int t = 0; t < aMesh->mNumFaces; ++t) {
	    const struct aiFace* face = &aMesh->mFaces[t];
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
