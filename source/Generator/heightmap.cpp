#include "Generator/heightmap.hpp"

#include <cstdlib>
#include <log4cpp/Category.hh>

#include "Generator/map/map.hpp"
#include "Generator/map/point.hpp"
#include "Generator/tools/simplexnoise.hpp"

using namespace log4cpp;

namespace map
{


HeightMap::HeightMap(int width, int height) : _width(width), _height(height), _points(), _zoneLookUp(), image(width, height), _vertices(), _indices(), _normals()
{
    Category& root = Category::getRoot();
    root << Priority::DEBUG << "construct heightmap";
}

HeightMap::~HeightMap()
{
}


// assigne l'altitude de chaque point de la heightmap, peut ajouter du bruit pour rendre le résultat un peu plus random
void    HeightMap::init(map::MapGraph & m)
{
    // seed pour le bruit
    int seed = rand() % 1000000;

    _points.resize((_width) * (_height));
    _zoneLookUp.createCloud(m);
    for (int i = 0; i < _height; ++i)
    {
     for (int j = 0; j < _width; ++j)
     {
         _points[i * _width + j].x = static_cast<double>(j);
         _points[i * _width + j].y = static_cast<double>(i);

     map::Zone *z;
         // trouve la zone à laquelle appartient le pixel en (j, i)
         z = _zoneLookUp.getNearestZone(static_cast<double>(j), static_cast<double>(i));
         _points[i * _width + j].zone = z;

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

              if (pointInsideTrigon(glm::vec3(static_cast<float>(j), static_cast<float>(i), 0.0), a, b, c))
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
         _points[i * _width + j].z = static_cast<double>(elevation); //+ additionalNoise;
         if (_points[i * _width + j].z > 1.0)
             _points[i * _width + j].z = 1.0;

     }
    }
}

// vérifie qu'un point s appartient au triangle a,b,c
bool HeightMap::pointInsideTrigon(glm::vec3 s, glm::vec3 a, glm::vec3 b, glm::vec3 c)
{
    float as_x = s.x-a.x;
    float as_y = s.y-a.y;

    bool s_ab = (b.x-a.x)*as_y-(b.y-a.y)*as_x >= 0;

    if(((c.x-a.x)*as_y-(c.y-a.y)*as_x > 0) == s_ab) return false;

    if(((c.x-b.x)*(s.y-b.y)-(c.y-b.y)*(s.x-b.x) > 0) != s_ab) return false;

    return true;
}

// crée une bitmap coloriée en en greyscale selon l'humidité des points
void    HeightMap::paintByMoisture()
{
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
        {
            HeightPoint & p = _points[i * _width + j];
            if (p.zone->ocean)
                image.set_pixel(j, _height - i - 1, 0, 0, 125);
            else
                image.set_pixel(j, _height - i - 1, static_cast<unsigned char>(p.zone->moisture * 255.0f), static_cast<unsigned char>(p.zone->moisture * 255.0f), static_cast<unsigned char>(p.zone->moisture * 255.0f));
        }
    image.save_image("mapmoisture.bmp");
}

// crée une bitmap coloriée en greyscale selon la hauteur des points
void    HeightMap::paintByHeight()
{
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
        {
            HeightPoint & p = _points[i * _width + j];
            if (p.zone->ocean)
                image.set_pixel(j, _height - i - 1, 0, 0, 125);
            else
                image.set_pixel(j, _height - i - 1, static_cast<unsigned char>(p.z * 255.0), static_cast<unsigned char>(p.z * 255.0), static_cast<unsigned char>(p.z * 255.0));
        }
    image.save_image("mapheight.bmp");
}

// crée une bitmap qui assigne différentes couleures selon le land time (bordure, océan, beach/coast et water
void    HeightMap::paintByLandType()
{
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
        {
            HeightPoint & p = _points[i * _width + j];
            if (p.zone->border)
                image.set_pixel(j, _height - i - 1, 200, 50, 50);
            else if (p.zone->ocean)
                image.set_pixel(j, _height - i - 1, 50, 50, 200);
            else if (p.zone->coast)
                image.set_pixel(j, _height - i - 1, 255, 255, 204);
            else if (p.zone->water)
                image.set_pixel(j, _height - i - 1, 0, 255, 255);
        }
    image.save_image("maptype.bmp");
}

// crée une bitmap qui colorie les zones selon leur biome
void    HeightMap::paintByBiome()
{
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
        {
            HeightPoint & p = _points[i * _width + j];
            if (p.zone->biome == map::BEACH)
                image.set_pixel(j, _height - i - 1, 255, 255, 204);
            else if (p.zone->biome == map::OCEAN)
                image.set_pixel(j, _height - i - 1, 26, 0, 153);
            else if (p.zone->biome == map::MARSH)
                image.set_pixel(j, _height - i - 1, 0, 204, 153);
            else if (p.zone->biome == map::ICE)
                image.set_pixel(j, _height - i - 1, 220, 250, 255);
            else if (p.zone->biome == map::LAKE)
                image.set_pixel(j, _height - i - 1, 61, 139, 255);
            else if (p.zone->biome == map::SNOW)
                image.set_pixel(j, _height - i - 1, 248, 248, 248);
            else if (p.zone->biome == map::TUNDRA)
                image.set_pixel(j, _height - i - 1, 208, 208, 176);
            else if (p.zone->biome == map::BARE)
                image.set_pixel(j, _height - i - 1, 176, 176, 176);
            else if (p.zone->biome == map::SCORCHED)
                image.set_pixel(j, _height - i - 1, 144, 144, 144);
            else if (p.zone->biome == map::TAIGA)
                image.set_pixel(j, _height - i - 1, 204, 212, 187);
            else if (p.zone->biome == map::SHRUBLAND)
                image.set_pixel(j, _height - i - 1, 196, 204, 187);
            else if (p.zone->biome == map::TEMPERATE_DESERT)
                image.set_pixel(j, _height - i - 1, 228, 232, 202);
            else if (p.zone->biome == map::TEMPERATE_RAIN_FOREST)
                image.set_pixel(j, _height - i - 1, 164, 196, 168);
            else if (p.zone->biome == map::TEMPERATE_DECIDUOUS_FOREST)
                image.set_pixel(j, _height - i - 1, 180, 196, 169);
            else if (p.zone->biome == map::GRASSLAND)
                image.set_pixel(j, _height - i - 1, 196, 212, 170);
            else if (p.zone->biome == map::TROPICAL_SEASONAL_FOREST)
                image.set_pixel(j, _height - i - 1, 169, 204, 164);
            else if (p.zone->biome == map::TROPICAL_RAIN_FOREST)
                image.set_pixel(j, _height - i - 1, 228, 232, 202);
            else if (p.zone->biome == map::SUBTROPICAL_DESERT)
                image.set_pixel(j, _height - i - 1, 233, 221, 199);

        }
    image.save_image("mapbiome.bmp");
}


// génère la mesh du terrain en procédant deux triangles par deux triangles (ou carré par carré)
void    HeightMap::generateMesh()
{
    Category& root = Category::getRoot();
    root << Priority::DEBUG << "yo " << _points.size();
    _vertices.reserve(_height * _width * 3);
    _indices.reserve(_height * _width * 3 / 2);
    _normals.reserve(_height * _width * 3 / 2);

    for (int i = 0; i < (_height - 1); ++i)
        for (int j = 0; j < (_width - 1); j += 4)
        {
            glm::vec3 p1 = glm::vec3(static_cast<float>(_points[i * _width + j].x),
                                     static_cast<float>(_points[i * _width + j].z),
                                     static_cast<float>(_points[i * _width + j].y));
	    glm::vec3 p2 = glm::vec3(static_cast<float>(_points[i * _width + j + 1].x),
                                     static_cast<float>(_points[i * _width + j + 1].z),
                                     static_cast<float>(_points[i * _width + j + 1].y));
	    glm::vec3 p3 = glm::vec3(static_cast<float>(_points[i * _width + j + 2].x),
                                     static_cast<float>(_points[i * _width + j + 2].z),
                                     static_cast<float>(_points[i * _width + j + 2].y));
	    glm::vec3 p4 = glm::vec3(static_cast<float>(_points[i * _width + j + 3].x),
                                     static_cast<float>(_points[i * _width + j + 3].z),
                                     static_cast<float>(_points[i * _width + j + 3].y));

            _vertices.push_back(p1.x);
            _vertices.push_back(p1.y);
            _vertices.push_back(p1.z);

            _vertices.push_back(p2.x);
            _vertices.push_back(p2.y);
            _vertices.push_back(p2.z);

            _vertices.push_back(p3.x);
            _vertices.push_back(p3.y);
            _vertices.push_back(p3.z);

            _vertices.push_back(p4.x);
            _vertices.push_back(p4.y);
            _vertices.push_back(p4.z);

            _indices.push_back(j + i * _width);
            _indices.push_back(j + 1 + i * _width);
            _indices.push_back(j + 2 + i * _width);

            _indices.push_back(j + i * _width);
            _indices.push_back(j + 1 + i * _width);
            _indices.push_back(j + 3 + i * _width);

	    glm::vec3 result = glm::cross(p2 -p1, p3 - p1);

            _normals.push_back(result.x);
            _normals.push_back(result.y);
            _normals.push_back(result.z);

            result = glm::cross(p2 - p1, p4 - p1);

            _normals.push_back(result.x);
            _normals.push_back(result.y);
            _normals.push_back(result.z);
        }
}

// get les arrays à envoyer à la carte graphique via le renderer
std::vector<float> const &HeightMap::getPoints()     { return _vertices; }
std::vector<unsigned int> const &HeightMap::getIndices()   { return _indices; }
std::vector<float> const &HeightMap::getNormals()     { return _normals; }

}
