#include "Generator/heightmap.hpp"

#include <cstdlib>
#include <iostream>

#include "Generator/map/map.hpp"
#include "Generator/tools/simplexnoise.hpp"

namespace MAP
{


HeightMap::HeightMap(int width, int height) : _width(width), _height(height), _zoneLookUp(), image(width, height)
{
}

HeightMap::~HeightMap()
{
}

void    HeightMap::init(MAP::Map & m)
{
    int seed = rand() % 1000000;

    _points.resize((_width) * (_height));
    _zoneLookUp.createCloud(m);
    for (int i = 0; i < _height; ++i)
    {
     for (int j = 0; j < _width; ++j)
     {
         _points[i * _width + j].x = (double)j;
         _points[i * _width + j].y = (double)i;
         MAP::Zone * z;
         z = _zoneLookUp.getNearestZone((double)(j), (double)(i));
         _points[i * _width + j].zone = z;

         float  additionalNoise = octave_noise_2d(8, 0.5, 0.012, (float)j + seed, (float)i + seed);
         additionalNoise = additionalNoise / 10.0;


         _points[i * _width + j].z = (double)z->elevation; //+ additionalNoise;
         if (_points[i * _width + j].z > 1.0)
             _points[i * _width + j].z = 1.0;

     }
    }
}

void    HeightMap::paintByMoisture()
{
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
        {
            HeightPoint & p = _points[i * _width + j];
            if (p.zone->ocean)
                image.set_pixel(j, _height - i - 1, 0, 0, 125);
            else
                image.set_pixel(j, _height - i - 1, (int)(p.zone->moisture * 255.0), (int)(p.zone->moisture * 255.0), (int)(p.zone->moisture * 255.0));
        }
    image.save_image("mapmoisture.bmp");
}

void    HeightMap::paintByHeight()
{
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
        {
            HeightPoint & p = _points[i * _width + j];
            if (p.zone->ocean)
                image.set_pixel(j, _height - i - 1, 0, 0, 125);
            else
                image.set_pixel(j, _height - i - 1, (int)(p.z * 255.0), (int)(p.z * 255.0), (int)(p.z * 255.0));
        }
    image.save_image("mapheight.bmp");
}

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

void    HeightMap::paintByBiome()
{
    for (int i = 0; i < _height; ++i)
        for (int j = 0; j < _width; ++j)
        {
            HeightPoint & p = _points[i * _width + j];
            if (p.zone->biome == MAP::BEACH)
                image.set_pixel(j, _height - i - 1, 255, 255, 204);
            else if (p.zone->biome == MAP::OCEAN)
                image.set_pixel(j, _height - i - 1, 26, 0, 153);
            else if (p.zone->biome == MAP::MARSH)
                image.set_pixel(j, _height - i - 1, 0, 204, 153);
            else if (p.zone->biome == MAP::ICE)
                image.set_pixel(j, _height - i - 1, 220, 250, 255);
            else if (p.zone->biome == MAP::LAKE)
                image.set_pixel(j, _height - i - 1, 61, 139, 255);
            else if (p.zone->biome == MAP::SNOW)
                image.set_pixel(j, _height - i - 1, 248, 248, 248);
            else if (p.zone->biome == MAP::TUNDRA)
                image.set_pixel(j, _height - i - 1, 208, 208, 176);
            else if (p.zone->biome == MAP::BARE)
                image.set_pixel(j, _height - i - 1, 176, 176, 176);
            else if (p.zone->biome == MAP::SCORCHED)
                image.set_pixel(j, _height - i - 1, 144, 144, 144);
            else if (p.zone->biome == MAP::TAIGA)
                image.set_pixel(j, _height - i - 1, 204, 212, 187);
            else if (p.zone->biome == MAP::SHRUBLAND)
                image.set_pixel(j, _height - i - 1, 196, 204, 187);
            else if (p.zone->biome == MAP::TEMPERATE_DESERT)
                image.set_pixel(j, _height - i - 1, 228, 232, 202);
            else if (p.zone->biome == MAP::TEMPERATE_RAIN_FOREST)
                image.set_pixel(j, _height - i - 1, 164, 196, 168);
            else if (p.zone->biome == MAP::TEMPERATE_DECIDUOUS_FOREST)
                image.set_pixel(j, _height - i - 1, 180, 196, 169);
            else if (p.zone->biome == MAP::GRASSLAND)
                image.set_pixel(j, _height - i - 1, 196, 212, 170);
            else if (p.zone->biome == MAP::TROPICAL_SEASONAL_FOREST)
                image.set_pixel(j, _height - i - 1, 169, 204, 164);
            else if (p.zone->biome == MAP::TROPICAL_RAIN_FOREST)
                image.set_pixel(j, _height - i - 1, 228, 232, 202);
            else if (p.zone->biome == MAP::SUBTROPICAL_DESERT)
                image.set_pixel(j, _height - i - 1, 233, 221, 199);

        }
    image.save_image("mapbiome.bmp");
}



void    HeightMap::generateMesh()
{
    _vertices = new std::vector<float>[_height * _width * 3];
    _indices = new std::vector<int>[(_height - 1) * (_width - 1) * 6];
    _normals = new std::vector<float>[(_height - 1) * (_width - 1) * 2 * 3];

    std::vector<float> & v = *_vertices;
    std::vector<int> &   ind = *_indices;
    std::vector<float> & n = *_normals;

    for (int i = 0; i < (_height - 1); ++i)
        for (int j = 0; j < (_width - 1); ++j)
        {
            v[((i) * _width + (j)) * 3] = (float)(_points[i * _width + j].x);
            v[((i) * _width + (j)) * 3 + 1] = (float)(_points[i * _width + j].z);
            v[((i) * _width + (j)) * 3 + 2] = (float)(_points[i * _width + j].y);

            ind[((i) * _width + (j)) * 6] = j + i * _width;
            ind[((i) * _width + (j)) * 6 + 1] = j + 1 + (i + 1) * _width;
            ind[((i) * _width + (j)) * 6 + 2] = j + (i + 1) * _width;

            ind[((i) * _width + (j)) * 6 + 3] = j + i * _width;
            ind[((i) * _width + (j)) * 6 + 4] = j + 1 + i * _width;
            ind[((i) * _width + (j)) * 6 + 5] = j + 1 + (i + 1) * _width;

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

            n[(j + i * _width) * 6] = result.x;
            n[(j + i * _width) * 6 + 1] = result.y;
            n[(j + i * _width) * 6 + 2] = result.z;

            result = glm::cross(b, c);

            n[(j + i * _width) * 6 + 3] = result.x;
            n[(j + i * _width) * 6 + 4] = result.y;
            n[(j + i * _width) * 6 + 5] = result.z;

        }
}

std::vector<float> * HeightMap::getPoints()     { return _vertices; }
std::vector<int>     * HeightMap::getIndices()   { return _indices; }
std::vector<float> * HeightMap::getNormals()     { return _normals; }

}
