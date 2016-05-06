#pragma once

#include    <list>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Entity.hpp"

namespace   Engine
{

	class   Mesh;

	///
	/// \brief This class is used to represent a physical entity.
	///
	class ENGINE_EXPORTS Terrain : public Entity
	{
	public:
		///
		/// \brief Default constructor.
		/// \param node the node related to the terrain.
		///
		Terrain(SceneGraphNode *node); // TODO GSL NOT NULL

		///
		/// \brief Copy constructor.
		///
		Terrain(const Terrain &other) = default;

		///
		/// \brief Move constructor.
		///
		Terrain(Terrain &&other) noexcept = default;

		///
		/// \brief Destructor.
		///
		virtual ~Terrain(void) noexcept;

	public:
		///
		/// \brief Copy assignment operator.
		///
		Terrain  &operator=(const Terrain &other) = default;

		///
		/// \brief Move assigment operator.
		///
		Terrain  &operator=(Terrain &&other) noexcept = default;

	public:
		///
		/// \brief This method is used to clone the terrain.
		///
		Terrain  *clone(void) const override;

		///
		/// \brief Update the terrain.
		///
		void    update(void) override;

	public:

	protected:
	};
}