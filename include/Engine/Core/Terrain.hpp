#pragma once

#include    <list>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Entity.hpp"
#include 	"Generator/heightmap.hpp"
#include 	"Generator/generator.hpp"

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
		Terrain(Scene *scene,/*SceneGraphNode *node, */ShaderProgramLibrary const& shaderprograms); // TODO GSL NOT NULL

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
		std::vector<float> const& getVertex() {
			return _heightmap->getPoints();
		}
		std::vector<unsigned int> const& getIndices() {
			return _heightmap->getIndices();
		}
		std::vector<float> const& getNormals() {
			return _heightmap->getNormals();
		}

	    Mesh *     getMesh() {
	    	return _mesh;
	    }

	protected:

	private:
		map::HeightMap* _heightmap;
		gen::Generator*	_generator;

        ///
        /// \brief The mesh associated with the terrain.
        ///
        Mesh *     _mesh; // TODO opti by not using a mesh

		std::vector<float> vertices;
   		std::vector<unsigned int> indices;


	};
}