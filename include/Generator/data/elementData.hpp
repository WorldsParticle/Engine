/* 
 * File:   elementData.hpp
 * Author: marie
 *
 * Created on 6 juillet 2016, 20:02
 */

#ifndef ELEMENTDATA_HPP
#define ELEMENTDATA_HPP

#include "paramData.hpp"
#include "../param/intvalue.hpp"

namespace GenData
{

class ElementData : public ParamData
{
public:
    ElementData(std::string const& n, std::string const& file)
    : ParamData(),
    name(n), density("density"), _filename(file)
    {
        density.setMinValue(1);
        density.setMaxValue(100);
        density.setValue(50);

        _params.push_back(&density);
    }

    //name
    std::string name;//TODO how to display list ?

    //params
    gen::IntValue   density;

public:
    inline std::string const&  filename() {
        return _filename;
    }
    
private:
    std::string     _filename;
    //map::Biome    environment;//useful ?
};
}

#endif /* ELEMENTDATA_HPP */

