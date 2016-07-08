/* 
 * File:   elementContent.hpp
 * Author: marie
 *
 * Created on 9 juillet 2016, 00:09
 */

#ifndef ELEMENTCONTENT_HPP
#define ELEMENTCONTENT_HPP

#include "Engine/Core/Transform.hpp"

//namespace Engine
//{
//class Transform;
//}

namespace GenContent
{
class ElementContent
{
public:
    ElementContent(std::string const& n, std::string const& file)
    : name(n), filename(file)
    {
    }

    std::string name;
    std::string filename;

    inline Engine::Transform const&   getTransform() {
        return _transform;
    }
    inline void   setTransform(Engine::Transform const& t) {
        _transform = t;
    }
private:
    Engine::Transform   _transform;
};
}

#endif /* ELEMENTCONTENT_HPP */

