#include "Generator/steps/heightmapingstep.hpp"
#include "Generator/map/heightmap.hpp"

namespace gen
{

HeightMapingStep::HeightMapingStep() :
    GenerationStep("Construction de la heightmap"),
    m_zoneLookUp()
{

}

HeightMapingStep::~HeightMapingStep()
{

}

void    HeightMapingStep::run()
{
    // seed pour le bruit
    //int seed = rand() % 1000000;

    m_zoneLookUp.createCloud(m_map);

    for (unsigned int i = 0; i < m_map->xMax(); ++i)
    {
        for (unsigned int j = 0; j < m_map->yMax(); ++j)
        {
            map::HeightPoint &p = m_map->heightMap().pointAt(i, j);
            p.x = static_cast<double>(j);
            p.y = static_cast<double>(i);

            map::Zone *z;
            // trouve la zone à laquelle appartient le pixel en (j, i)
            z = m_zoneLookUp.getNearestZone(static_cast<double>(j), static_cast<double>(i));
            p.zone = z;

            float elevation = 0.0;
            for (auto & e : z->borders)
            {
                glm::vec3 a, b, c;
                a.x = static_cast<float>(z->point.x);
                a.y = static_cast<float>(z->point.y);
                a.z = z->elevation;

                b.x = static_cast<float>(e->c0->point.x);
                b.y = static_cast<float>(e->c0->point.y);
                b.z = e->c0->elevation;

                c.x = static_cast<float>(e->c1->point.x);
                c.y = static_cast<float>(e->c1->point.y);
                c.z = e->c1->elevation;

                if (map::HeightMap::pointInsideTrigon(glm::vec3(static_cast<float>(j), static_cast<float>(i), 0.0), a, b, c))
                {
                    glm::vec3 cross;
                    float d;
                    b = b - a;
                    c = c - a;
                    cross = glm::cross(b, c);
                    d = cross.x * a.x + cross.y * a.y + cross.z * a.z;
                    elevation = (d - cross.x * static_cast<float>(j) - static_cast<float>(i) * cross.y) / cross.z;
                    break;
                }
            }


            // génère du bruit aléatoire
            /*float  additionalNoise = octave_noise_2d(8.0f, 0.5f, 0.012f, static_cast<float>(j) + static_cast<float>(seed), static_cast<float>(i) + static_cast<float>(seed));
            additionalNoise = additionalNoise / 10.0f;*/

            // set le z du point sur la heightmap
            p.z = static_cast<double>(elevation); //+ additionalNoise;
            if (p.z > 1.0)
                p.z = 1.0;

        }
    }

    m_map->heightMap().generateMesh();
}

}
