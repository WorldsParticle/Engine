#include    <log4cpp/Category.hh>

#include    "Engine/Core/Terrain.hpp"
#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/Mesh.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"
#include    "Engine/Core/Scene.hpp"

using namespace     log4cpp;

namespace   Engine
{
    Terrain::Terrain(map::HeightMap &map, Scene *scene,/*SceneGraphNode *node, */ShaderProgramLibrary const& shaderprograms) :
		Entity(scene),
        m_heightmap(map)
//		_mesh()
	{
		this->m_scene->add(this);

		const auto& myShader = shaderprograms.get(DEFAULT_SHADER_PROGRAM);

		Material* myMaterial = new Material(myShader);
        m_mesh = new Mesh(myMaterial);

//		float v[] = {
//		     0.0f,  0.0f, 0.0f, // Vertex 1 (X, Y,Z)
//		     0.5f, -0.5f, 0.0f, // Vertex 2 (X, Y)
//		    -0.5f, -0.5f, 0.0f,  // Vertex 3 (X, Y)
//		};
//
//		unsigned int indices_[] = {
//			0,1,2//,3,4,5,6,7,8
//		};
//
//		for (int i=0; i< 9; i++)
//			vertices.push_back(v[i]);
//
//		for (int i=0; i< 3; i++)
//			indices.push_back(indices_[i]);
//
//		_mesh->setPositions(vertices);
//		//_mesh->setNormals(vertices);
//		//_mesh->setIndices(indices);

        m_mesh->setPositions(getVertex());
        m_mesh->setNormals(getNormals());
        m_mesh->setIndices(getIndices());
        m_mesh->update();
	}
	//const Resource  &get(const Key &key) const;
//ShaderProgramLibrary : public Library<ShaderProgramName, std::shared_ptr<ShaderProgram>>
	Terrain::~Terrain(void)
	{

	}



	Terrain *
		Terrain::clone(void) const
	{
		return new Terrain(*this);
	}

	void
		Terrain::update(void)
	{
        //m_mesh->update();
		Category    &root = Category::getRoot();

		root << Priority::DEBUG << "Terrain - update()";
		// nothing to do actually.
	}

}
