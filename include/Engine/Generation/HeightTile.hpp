#ifndef HEIGHTTILE_HPP
#define HEIGHTTILE_HPP

#include <vector>

#include "Engine/Configuration.hpp"

namespace   Engine
{

///
/// \brief The HeightTile class
///
class HeightTile
{
public:

    ///
    /// \brief Default constructor, global x and y being the position of the tile on the world map.
    ///
    HeightTile(int width, int height, int globalX, int globalY);

    ///
    /// \brief Destructor
    ///
    virtual ~HeightTile();

    ///
    /// \brief This methods returns the value of a point(x, y) on the tile.
    ///
    float   get(int x, int y) const;

    ///
    /// \brief This methods sets a particular point(x, y) on the tile to value.
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
    int                     _x;

    ///
    /// \brief y position on the world map
    ///
    int                     _y;

    ///
    /// \brief 1D float array depicting the height of each points on the tile
    ///
    std::vector<float>      _tile;
};

}

#endif /* HEIGHTTILE */
