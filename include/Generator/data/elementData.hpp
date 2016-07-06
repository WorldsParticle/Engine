/* 
 * File:   elementData.hpp
 * Author: marie
 *
 * Created on 6 juillet 2016, 20:02
 */

#ifndef ELEMENTDATA_HPP
#define ELEMENTDATA_HPP

namespace GenData
{
    struct ElementData
    {
        std::string name;
        int         density;//intparam
        int         altitude;//min, max
        
    private:
        std::string filename;
        //map::Biome    environment;//useful ?
    };
}

#endif /* ELEMENTDATA_HPP */

