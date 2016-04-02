#include    <log4cpp/Category.hh>

#include    "Engine/Core/Terrain.hpp"
#include    "Engine/Core/Scene.hpp"

using namespace     log4cpp;

namespace   Engine
{
	Terrain::Terrain(SceneGraphNode *node) :
		Entity(node)
	{
		this->m_scene->add(this);
	}

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
