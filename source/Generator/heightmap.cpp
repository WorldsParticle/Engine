#include "Generator/heightmap.hpp"

#include <cstdlib>
#include <iostream>

#include "Generator/map/map.hpp"
#include "Generator/tools/simplexnoise.hpp"

namespace MAP_NAMESPACE
{


HeightMap::HeightMap(int width, int height) : _width(width), _height(height), _points(), _zoneLookUp(), image(width, height), _vertices(), _indices(), _normals()
{
}

HeightMap::~HeightMap()
{
}

// assigne l'altitude de chaque point de la heightmap, peut ajouter du bruit pour rendre le résultat un peu plus random
void    HeightMap::init(MAP_NAMESPACE::Map & m)
{
    // seed pour le bruit
    int seed = rand() % 1000000;

    _points.resize((_width + 2) * (_height + 2));
    _zoneLookUp.createCloud(m);
    for (int i = 0; i < _height; ++i)
    {
     for (int j = 0; j < _width; ++j)
     {
         _points[i * _width + j].x = static_cast<double>(j);
         _points[i * _width + j].y = static_cast<double>(i);

	 std::shared_ptr<MAP_NAMESPACE::Zone> z;
         // trouve la zone à laquelle appartient le pixel en (j, i)
         z = _zoneLookUp.getNearestZone(static_cast<double>(j), static_cast<double>(i));
         _points[i * _width + j].zone = z;

         // génère du bruit aléatoire
         float  additionalNoise = octave_noise_2d(8.0f, 0.5f, 0.012f, static_cast<float>(j) + static_cast<float>(seed), static_cast<float>(i) + static_cast<float>(seed));
         additionalNoise = additionalNoise / 10.0f;

        // set le z du point sur la heightmap
         _points[i * _width + j].z = static_cast<double>(z->elevation); //+ additionalNoise;
         if (_points[i * _width + j].z > 1.0)
             _points[i * _width + j].z = 1.0;

     }
    }
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
            if (p.zone->biome == MAP_NAMESPACE::BEACH)
                image.set_pixel(j, _height - i - 1, 255, 255, 204);
            else if (p.zone->biome == MAP_NAMESPACE::OCEAN)
                image.set_pixel(j, _height - i - 1, 26, 0, 153);
            else if (p.zone->biome == MAP_NAMESPACE::MARSH)
                image.set_pixel(j, _height - i - 1, 0, 204, 153);
            else if (p.zone->biome == MAP_NAMESPACE::ICE)
                image.set_pixel(j, _height - i - 1, 220, 250, 255);
            else if (p.zone->biome == MAP_NAMESPACE::LAKE)
                image.set_pixel(j, _height - i - 1, 61, 139, 255);
            else if (p.zone->biome == MAP_NAMESPACE::SNOW)
                image.set_pixel(j, _height - i - 1, 248, 248, 248);
            else if (p.zone->biome == MAP_NAMESPACE::TUNDRA)
                image.set_pixel(j, _height - i - 1, 208, 208, 176);
            else if (p.zone->biome == MAP_NAMESPACE::BARE)
                image.set_pixel(j, _height - i - 1, 176, 176, 176);
            else if (p.zone->biome == MAP_NAMESPACE::SCORCHED)
                image.set_pixel(j, _height - i - 1, 144, 144, 144);
            else if (p.zone->biome == MAP_NAMESPACE::TAIGA)
                image.set_pixel(j, _height - i - 1, 204, 212, 187);
            else if (p.zone->biome == MAP_NAMESPACE::SHRUBLAND)
                image.set_pixel(j, _height - i - 1, 196, 204, 187);
            else if (p.zone->biome == MAP_NAMESPACE::TEMPERATE_DESERT)
                image.set_pixel(j, _height - i - 1, 228, 232, 202);
            else if (p.zone->biome == MAP_NAMESPACE::TEMPERATE_RAIN_FOREST)
                image.set_pixel(j, _height - i - 1, 164, 196, 168);
            else if (p.zone->biome == MAP_NAMESPACE::TEMPERATE_DECIDUOUS_FOREST)
                image.set_pixel(j, _height - i - 1, 180, 196, 169);
            else if (p.zone->biome == MAP_NAMESPACE::GRASSLAND)
                image.set_pixel(j, _height - i - 1, 196, 212, 170);
            else if (p.zone->biome == MAP_NAMESPACE::TROPICAL_SEASONAL_FOREST)
                image.set_pixel(j, _height - i - 1, 169, 204, 164);
            else if (p.zone->biome == MAP_NAMESPACE::TROPICAL_RAIN_FOREST)
                image.set_pixel(j, _height - i - 1, 228, 232, 202);
            else if (p.zone->biome == MAP_NAMESPACE::SUBTROPICAL_DESERT)
                image.set_pixel(j, _height - i - 1, 233, 221, 199);

        }
    image.save_image("mapbiome.bmp");
}


// génère la mesh du terrain en procédant deux triangles par deux triangles (ou carré par carré)
void    HeightMap::generateMesh()
{
    _vertices.reserve(_height * _width * 3);
    _indices.reserve((_height - 1) * (_width - 1) * 6);
    _normals.reserve((_height - 1) * (_width - 1) * 2 * 3);

    for (int i = 0; i < (_height - 1); ++i)
        for (int j = 0; j < (_width - 1); ++j)
        {
            _vertices[((i) * _width + (j)) * 3] = static_cast<float>(_points[i * _width + j].x);
            _vertices[((i) * _width + (j)) * 3 + 1] = static_cast<float>(_points[i * _width + j].z);
            _vertices[((i) * _width + (j)) * 3 + 2] = static_cast<float>(_points[i * _width + j].y);

            _indices[((i) * _width + (j)) * 6] = j + i * _width;
            _indices[((i) * _width + (j)) * 6 + 1] = j + 1 + (i + 1) * _width;
            _indices[((i) * _width + (j)) * 6 + 2] = j + (i + 1) * _width;

            _indices[((i) * _width + (j)) * 6 + 3] = j + i * _width;
            _indices[((i) * _width + (j)) * 6 + 4] = j + 1 + i * _width;
            _indices[((i) * _width + (j)) * 6 + 5] = j + 1 + (i + 1) * _width;

            glm::vec3 a, b, c, result;
            a = {_points[(i + 1) * _width + j].x - _points[i * _width + j].x,
                _points[(i + 1) * _width + j].z - _points[i * _width + j].z,
                _points[(i + 1) * _width + j].y - _points[i * _width + j].y};
            b = {_points[(i + 1) * _width + j + 1].x - _points[i * _width + j].x,
                _points[(i + 1) * _width + j + 1].z - _points[i * _width + j].z,
                _points[(i + 1) * _width + j + 1].y - _points[i * _width + j].y};
            c = {_points[i * _width + j + 1].x - _points[i * _width + j].x,
                _points[i * _width + j + 1].z - _points[i * _width + j].z,
                _points[i * _width + j + 1].y - _points[i * _width + j].y};

            result = glm::cross(a, b);

            _normals[(j + i * _width) * 6] = result.x;
            _normals[(j + i * _width) * 6 + 1] = result.y;
            _normals[(j + i * _width) * 6 + 2] = result.z;

            result = glm::cross(b, c);

            _normals[(j + i * _width) * 6 + 3] = result.x;
            _normals[(j + i * _width) * 6 + 4] = result.y;
            _normals[(j + i * _width) * 6 + 5] = result.z;

        }
}

// get les arrays à envoyer à la carte graphique via le renderer
std::vector<float> const &HeightMap::getPoints()     { return _vertices; }
std::vector<unsigned int> const &HeightMap::getIndices()   { return _indices; }
std::vector<float> const &HeightMap::getNormals()     { return _normals; }

}
