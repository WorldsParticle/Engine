#include    <log4cpp/Category.hh>

#include    "Engine/Core/Terrain.hpp"
#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/Mesh.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"

using namespace     log4cpp;

namespace   Engine
{
	Terrain::Terrain(SceneGraphNode *node, ShaderProgramLibrary const& shaderprograms) :
		Entity(node),
		_heightmap(nullptr)
//		_generator()
//		_mesh()
	{
		this->m_scene->add(this);
		_generator = new gen::Generator();

		_generator->generate(10, 10, 2);
		_heightmap = _generator->getHeightmap();
		_heightmap->generateMesh();

		const auto& myShader = shaderprograms.get(DEFAULT_SHADER_PROGRAM);

		Material* myMaterial = new Material(myShader);

		_mesh = new Mesh(myMaterial);

//		_mesh->setPositions(getVertex());
//		_mesh->setNormals(getNormals());
//		_mesh->setIndices(getIndices());
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
		//Category    &root = Category::getRoot();

		//root << Priority::DEBUG << "Terrain - update()";
		// nothing to do actually.
	}

}
