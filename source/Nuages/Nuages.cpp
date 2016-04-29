#include    <log4cpp/Category.hh>

#include    "Engine/Nuages/Nuages.hpp"
#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/Mesh.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"
#include    "Engine/Nuages/NuagesMaterial.hpp"

using namespace     log4cpp;

namespace   Engine
{
    Nuages::Nuages(Scene *scene,/*SceneGraphNode *node, */ShaderProgramLibrary const& shaderprograms) :
        Entity(scene),
        m_mesh(nullptr),
        m_vertices({5000.0, 500.0, 5000.0,
                   5000.0, 500.0, -5000.0,
                    -5000.0, 500.0, -5000.0,
                   -5000.0, 500.0, 5000.0}),
        m_indices({0, 1, 3,
                  1, 3, 2}),
        m_normals({0.0, 0.0, 0.0,
                    0.0, 0.0, 0.0}),
        _shader(shaderprograms.get(NUAGES_SHADER_PROGRAM))
	{
		this->m_scene->add(this);

       // const auto& myShader = shaderprograms.get(NUAGES_SHADER_PROGRAM);

        Material* myMaterial = new NuagesMaterial(_shader);
        m_mesh = new Mesh(myMaterial);

        m_mesh->setPositions(getVertex());
        m_mesh->setNormals(getNormals());
        m_mesh->setIndices(getIndices());
        m_mesh->update();
	}
	//const Resource  &get(const Key &key) const;
//ShaderProgramLibrary : public Library<ShaderProgramName, std::shared_ptr<ShaderProgram>>
    Nuages::~Nuages(void)
	{

	}



    Nuages *
        Nuages::clone(void) const
	{
        return new Nuages(*this);
	}

	void
        Nuages::update(void)
	{
        //m_mesh->update();


        Category    &root = Category::getRoot();

        root << Priority::DEBUG << "Nuages - update()";
		// nothing to do actually.
	}

}
