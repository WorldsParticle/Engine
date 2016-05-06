#include    <log4cpp/Category.hh>

#include    "Engine/Nuages/LightningBolt.hpp"
#include    "Engine/Core/Scene.hpp"
#include    "Engine/Core/Mesh.hpp"
#include    "Engine/Core/ShaderProgramLibrary.hpp"
#include    "Engine/Nuages/LightningBoltMaterial.hpp"

using namespace     log4cpp;

namespace   Engine
{
    LightningBolt::LightningBolt(Scene *scene,/*SceneGraphNode *node, */ShaderProgramLibrary const& shaderprograms) :
        Entity(scene),
        m_mesh(nullptr),
        m_vertices(),
        m_indices(),
        m_normals(),
        _shader(shaderprograms.get(LIGHTNINGBOLT_SHADER_PROGRAM)),
        m_points(),
        m_displacementFactors()
	{
		this->m_scene->add(this);

       // const auto& myShader = shaderprograms.get(LightningBolt_SHADER_PROGRAM);

        Material* myMaterial = new LightningBoltMaterial(_shader);
        m_mesh = new Mesh(myMaterial);

        m_mesh->setPositions(getVertex());
        m_mesh->setNormals(getNormals());
        m_mesh->setIndices(getIndices());
        m_mesh->update();
	}
	//const Resource  &get(const Key &key) const;
//ShaderProgramLibrary : public Library<ShaderProgramName, std::shared_ptr<ShaderProgram>>
    LightningBolt::~LightningBolt(void)
	{

	}



    LightningBolt *
        LightningBolt::clone(void) const
	{
        return new LightningBolt(*this);
	}

	void
        LightningBolt::update(void)
	{
        //m_mesh->update();


        Category    &root = Category::getRoot();

        root << Priority::DEBUG << "LightningBolt - update()";
		// nothing to do actually.
	}

    void
        LightningBolt::generateMesh(unsigned int size, float scale)
    {
        glm::vec3  lookup[] = {{0.0, 0.0, 1.0},
                            {0.7071067, 0.0, 0.7071067},
                            {1.0, 0.0, 0.0},
                            {0.7071067, 0.0, -0.7071067},
                            {0.0, 0.0, -1.0},
                            {-0.7071067, 0.0, -0.7071067},
                            {-1.0, 0.0, 0.0},
                            {-0.7071067, 0.0, 0.7071067}};

        for (glm::vec3 & v : lookup)
            v *= scale;

        m_vertices.resize(8 * size * 3);
        m_indices.resize(8 * 2 * 3 * (size - 1));
        m_normals.resize(8 * 2 * 3 * (size - 1));

        for (unsigned int i = 0; i < (size - 1); ++i)
        {
            glm::vec3 p(m_points[i].x, m_points[i].y, m_points[i].z);
            for (unsigned int j = 0; j < 7; ++j)
            {
                m_vertices[i * 3 * 8 + j * 3] = p.x + lookup[j].x;
                m_vertices[i * 3 * 8 + j * 3 + 1] = p.y + lookup[j].y;
                m_vertices[i * 3 * 8 + j * 3 + 2] = p.z + lookup[j].z;

                m_indices[i * 3 * 8 * 2 + j * 3 * 2] = i * 8 + j;
                m_indices[i * 3 * 8 * 2 + j * 3 * 2 + 1] = i * 8 + j + 8;
                m_indices[i * 3 * 8 * 2 + j * 3 * 2 + 2] = i * 8 + j + 8 + 1;

                m_indices[i * 3 * 8 * 2 + j * 3 * 2 + 3] = i * 8 + j + 1;
                m_indices[i * 3 * 8 * 2 + j * 3 * 2 + 4] = i * 8 + j;
                m_indices[i * 3 * 8 * 2 + j * 3 * 2 + 5] = i * 8 + j + 8 + 1;
            }

            m_vertices[i * 3 * 8 + 7 * 3] = p.x + lookup[7].x;
            m_vertices[i * 3 * 8 + 7 * 3 + 1] = p.y + lookup[7].y;
            m_vertices[i * 3 * 8 + 7 * 3 + 2] = p.z + lookup[7].z;

            m_indices[i * 3 * 8 * 2 + 7 * 3 * 2] = i * 8 + 7;
            m_indices[i * 3 * 8 * 2 + 7 * 3 * 2 + 1] = i * 8 + 7 + 8;
            m_indices[i * 3 * 8 * 2 + 7 * 3 * 2 + 2] = i * 8 + 8;

            m_indices[i * 3 * 8 * 2 + 7 * 3 * 2 + 3] = i * 8;
            m_indices[i * 3 * 8 * 2 + 7 * 3 * 2 + 4] = i * 8 + 7;
            m_indices[i * 3 * 8 * 2 + 7 * 3 * 2 + 5] = i * 8 + 8;
        }

        glm::vec3 p(m_points[(size - 1)].x, m_points[(size - 1)].y, m_points[(size - 1)].z);

        for (unsigned int j = 0; j < 8; ++j)
        {
            m_vertices[(size - 1) * 3 * 8 + j * 3] = p.x + lookup[j].x;
            m_vertices[(size - 1) * 3 * 8 + j * 3 + 1] = p.y + lookup[j].y;
            m_vertices[(size - 1) * 3 * 8 + j * 3 + 2] = p.z + lookup[j].z;
        }

        m_mesh->setPositions(getVertex());
        m_mesh->setNormals(getNormals());
        m_mesh->setIndices(getIndices());
        m_mesh->update();
    }


    void
        LightningBolt::simpleDisplacement(glm::vec3 from,
                                      glm::vec3 to,
                                      unsigned int size,
                                      float displace,
                                      unsigned int idx)
    {
        if (size == 0)
            return;
        size /= 2;
        glm::vec3 middle = (from + to) / 2.0f;
        middle.x += (static_cast<float>(random() % 50 - 25) / 100.0f) *
                    (displace) * m_displacementFactors.x;
        middle.y += (static_cast<float>(random() % 50 - 25) / 100.0f) *
                (displace) * m_displacementFactors.y;
        middle.z += (static_cast<float>(random() % 50 - 25) / 100.0f) *
                (displace) * m_displacementFactors.z;

        m_points[idx] = middle;
        displace /= 2.0f;
        simpleDisplacement(from, middle, size, displace, idx - size / 2);
        simpleDisplacement(middle, to, size, displace, idx + size / 2);
    }


    void
        LightningBolt::generate(glm::vec3 start, glm::vec3 to,
                                glm::vec3 & displacementFactors,
                                float detail,
                                float boltWidthFactor)
    {
        this->m_displacementFactors = displacementFactors;

        unsigned int size = static_cast<unsigned int>(pow(2, detail)) + 1;
        m_points.resize(size);

        m_points[0] = start;
        m_points[size - 1] = to;
        simpleDisplacement(start, to, size, 512.0, size / 2);

        generateMesh(size, boltWidthFactor);
    }

}

