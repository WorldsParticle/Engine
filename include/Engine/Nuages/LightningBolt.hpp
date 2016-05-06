#pragma once

#include    <list>

#include    <glm/glm.hpp>
#include    "Engine/Configuration.hpp"
#include    "Engine/Core/Object.hpp"
#include    "Engine/Core/ShaderProgram.hpp"

namespace   Engine
{

	class   Mesh;
	class	ShaderProgramLibrary;
	class	Scene;

	///
	/// \brief This class is used to represent a physical entity.
	///
    class ENGINE_EXPORTS LightningBolt : public Object
	{
	public:
		///
		/// \brief Default constructor.
        /// \param node the node related to the LightningBolt.
		///
        LightningBolt(Scene *scene,/*SceneGraphNode *node, */ShaderProgramLibrary const& shaderprograms); // TODO GSL NOT NULL

		///
		/// \brief Copy constructor.
		///
        LightningBolt(const LightningBolt &other) = default;

		///
		/// \brief Move constructor.
		///
        LightningBolt(LightningBolt &&other) noexcept = default;

		///
		/// \brief Destructor.
		///
        virtual ~LightningBolt(void) noexcept;

	public:
		///
		/// \brief Copy assignment operator.
		///
        LightningBolt  &operator=(const LightningBolt &other) = default;

		///
		/// \brief Move assigment operator.
		///
        LightningBolt  &operator=(LightningBolt &&other) noexcept = default;

	public:
		///
        /// \brief This method is used to clone the LightningBolt.
		///
        LightningBolt  *clone(void) const override;

		///
        /// \brief Update the LightningBolt.
		///
		void    update(void) override;

        ///
        /// \brief Generates the LightningBolt.
        ///
        void    generate(glm::vec3 start, glm::vec3 to, glm::vec3 & displacementFactors, float detail = 9.0, float boltWidthFactor = 0.1f);

    private:

        ///
        /// \brief Generates the LightningBolt's mesh with 3D cylinders.
        ///
        void    generateMesh(unsigned int size, float scale = 1);

        ///
        /// \brief Midpoint displacement for arc generation.
        ///
        void simpleDisplacement(glm::vec3 from,
                                glm::vec3 to,
                                unsigned int size,
                                float displace,
                                unsigned int idx);

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
        /// \brief The mesh associated with the LightningBolt.
        ///
        Mesh *          m_mesh; // TODO opti by not using a mesh

        std::vector<float>          m_vertices;
        std::vector<unsigned int>   m_indices;
        std::vector<float>   m_normals;
        const std::shared_ptr<Engine::ShaderProgram> _shader;

        std::vector<glm::vec3>          m_points;

        glm::vec3                       m_displacementFactors;



	};
}
