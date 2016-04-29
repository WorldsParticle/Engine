#pragma once

#include    <list>

#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Entity.hpp"
#include 	"Generator/map/heightmap.hpp"
#include 	"Generator/generator.hpp"
#include    "Engine/Core/ShaderProgram.hpp"

namespace   Engine
{

	class   Mesh;
	class	ShaderProgramLibrary;
	class	Scene;

	///
	/// \brief This class is used to represent a physical entity.
	///
    class ENGINE_EXPORTS Nuages : public Entity
	{
	public:
		///
		/// \brief Default constructor.
        /// \param node the node related to the Nuages.
		///
        Nuages(Scene *scene,/*SceneGraphNode *node, */ShaderProgramLibrary const& shaderprograms); // TODO GSL NOT NULL

		///
		/// \brief Copy constructor.
		///
        Nuages(const Nuages &other) = default;

		///
		/// \brief Move constructor.
		///
        Nuages(Nuages &&other) noexcept = default;

		///
		/// \brief Destructor.
		///
        virtual ~Nuages(void) noexcept;

	public:
		///
		/// \brief Copy assignment operator.
		///
        Nuages  &operator=(const Nuages &other) = default;

		///
		/// \brief Move assigment operator.
		///
        Nuages  &operator=(Nuages &&other) noexcept = default;

	public:
		///
        /// \brief This method is used to clone the Nuages.
		///
        Nuages  *clone(void) const override;

		///
        /// \brief Update the Nuages.
		///
		void    update(void) override;

	public:

        inline std::vector<float> const& getVertex()
        { return m_vertices; }

        inline std::vector<unsigned int> const& getIndices()
        { return m_indices; }

        inline std::vector<float> const& getNormals()
        { return m_normals; }

        inline Mesh *mesh()
        { return m_mesh; }

	protected:

	private:

        ///
        /// \brief The mesh associated with the Nuages.
        ///
        Mesh *          m_mesh; // TODO opti by not using a mesh

        std::vector<float>          m_vertices;
        std::vector<unsigned int>   m_indices;
        std::vector<float>   m_normals;
        const std::shared_ptr<Engine::ShaderProgram> _shader;


	};
}
