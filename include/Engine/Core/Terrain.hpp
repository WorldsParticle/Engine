#pragma once

#include    <list>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Entity.hpp"
#include 	"Generator/map/heightmap.hpp"

namespace   Engine
{

	class   Mesh;
	class	ShaderProgramLibrary;
	class	Scene;

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
        Terrain(map::HeightMap &map, Scene *scene,/*SceneGraphNode *node, */ShaderProgramLibrary const& shaderprograms); // TODO GSL NOT NULL

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

        inline std::vector<float> const& getVertex()
        { return m_heightmap.vertices(); }

        inline std::vector<unsigned int> const& getIndices()
        { return m_heightmap.indices(); }

        inline std::vector<float> const& getNormals()
        { return m_heightmap.normals(); }

        inline Mesh *mesh()
        { return m_mesh; }

	protected:

	private:
        map::HeightMap  &m_heightmap;

        ///
        /// \brief The mesh associated with the terrain.
        ///
        Mesh *          m_mesh; // TODO opti by not using a mesh

        std::vector<float>          m_vertices;
        std::vector<unsigned int>   m_indices;


	};
}
