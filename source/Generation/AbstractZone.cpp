#include "Engine/Generation/AbstractZone.hpp"

#include <math.h>

namespace Engine
{

AbstractZone::AbstractZone(ZoneType type, AbstractZone *parent, unsigned int depth) :
    _type(type),
    _parent(parent),
    _depth(depth),
    _childs()
{
    for (int i = 0; i < pow(_depth + 1, 2); ++i)
        _childs.push_back(nullptr);
}

AbstractZone::~AbstractZone()
{
    for (int i = 0; i <= _depth; ++i)
    {
        for (int j = 0; j <= _depth; ++j)
        {
            if (_childs.at(i + j * (_depth+1)))
                delete (_childs[i + j * (_depth+1)]);
        }
    }
    _childs.clear();
}

}
