#include "Engine/Generation/Voronoi.hpp"

namespace Engine
{
	Voronoi::Voronoi(SceneGraphNode *node) :
		Entity(node)
	{}

	Voronoi::Voronoi(SceneGraphNode *node, int pointMax) :
		Entity(node), _pointMax(pointMax)
	{
		placePoints();
		genereCells();
	}

	Voronoi::~Voronoi(void)
	{
	}

	void	Voronoi::placePoints()//TODO
	{

	}
	void	Voronoi::genereCells()//TODO
	{

	}

}