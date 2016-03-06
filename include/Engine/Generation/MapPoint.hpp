#pragma once

#include "Engine/Configuration.hpp"
#include "Engine/Core/Entity.hpp"

namespace Engine
{
	class ENGINE_EXPORTS MapPoint : public Entity
	{
	public:
		///
		/// \brief Default constructor.
		///
		MapPoint(SceneGraphNode *node);

		///
		/// \brief Destructor.
		///
		~MapPoint(void);

	public:
		///
		/// \brief clone pattern
		///
		MapPoint  *clone(void) const
		{
			return new MapPoint(*this);
		}

	public:
		///
		/// \brief method used to update the entity.
		///
		virtual void    update(void)
		{}

	private:

	};


}
