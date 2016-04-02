#ifndef ABSTRACTZONE_HPP
#define ABSTRACTZONE_HPP

#include <list>
#include <vector>

namespace   Engine
{

///
/// \brief The AbstractZone class
///
class AbstractZone
{
public:
    enum    ZoneType
    {
        SEA = 0,
        LAKE,
        PLAIN,
        HILL,
        MOUTAIN,
        FOREST
    };

    ///
    /// \brief AbstractZone
    /// \param depth
    ///
    AbstractZone(ZoneType type, AbstractZone *parent, unsigned int depth);

    ///
    /// \brief ~AbstractZone
    ///
    virtual ~AbstractZone();

    ///
    /// \brief generate the zone, the childs zone, construct the heightmap and fill it with assets.
    ///
    virtual void    generate() = 0;

protected:
    ///
    /// \brief _type
    ///
    ZoneType                    _type;

    ///
    /// \brief _parent. if NULL then this zone is the main one.
    ///
    AbstractZone*               _parent;

    ///
    /// \brief _depth
    ///
    unsigned int                _depth;
    ///
    /// \brief _childs is a 2D map. if _childs[x + (depth+1) * y] = NULL, this zone is generated
    ///
    std::vector<AbstractZone*> _childs;
};

}

#endif /* ABSTRACTZONE_HPP */
