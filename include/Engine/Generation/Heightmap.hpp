#ifndef HEIGHTMAP_NAMESPACE_HPP
#define HEIGHTMAP_NAMESPACE_HPP

#include <vector>
#include "HeightTile.hpp"

#include "Engine/Configuration.hpp"

namespace   Engine
{

///
/// \brief The Heightmap class
///
class ENGINE_EXPORTS Heightmap
{
public:

    ///
    /// \brief Default constructor, global x and y being the position of the tile on the world map.
    ///
    Heightmap(int width, int height, int tileWidth, int tileHeight);

    ///
    /// \brief Destructor
    ///
    virtual ~Heightmap();

    ///
    /// \brief This methods returns the value of a point(x, y) on the heightmap.
    ///
    float   get(int x, int y) const;

    ///
    /// \brief This methods sets a particular point(x, y) on the map to value.
    ///
    void    set(int x, int y, float value);

protected:
    ///
    /// \brief width in # of points of the tile.
    ///
    int                     _width;

    ///
    /// \brief height in # of points of the tile.
    ///
    int                     _height;

    ///
    /// \brief x position on the world map
    ///
    int                     _tileWidth;

    ///
    /// \brief y position on the world map
    ///
    int                     _tileHeight;

    ///
    /// \brief 1D HeightTile array containing the different heightmap's tiles.
    ///
    std::vector<HeightTile>  _tiles;
};

}

#endif /* HEIGHTMAP_NAMESPACE */
