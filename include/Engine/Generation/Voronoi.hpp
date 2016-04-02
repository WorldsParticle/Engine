#pragma once

#include <vector>
#include "Engine/Core/Entity.hpp"
#include "Engine/Generation/MapPoint.hpp"

namespace Engine
{
	///
	/// \brief This class implement the Voronoi algorithm to place the generation zones.
	///
	class Voronoi : public Entity
	{
	public:
		///
		/// \brief Default constructor.
		///
		Voronoi(SceneGraphNode *node);

		///
		/// \brief Constructor with max points of number and cells
		///
		Voronoi(SceneGraphNode *node, int pointMax);

		///
		/// \brief Destructor.
		///
		~Voronoi(void);

	private:
		void	placePoints();//TODO
		void	genereCells();//TODO

	private:
		///
		/// \brief The initial points for each zone
		///
		std::vector<MapPoint>	_points;

		///
		/// \brief The maximum number of points and zone in the scene
		///
		int	_pointMax;
	};
}

