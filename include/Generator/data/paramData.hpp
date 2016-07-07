/* 
 * File:   paramData.hpp
 * Author: marie
 *
 * Created on 7 juillet 2016, 14:43
 */

#ifndef PARAMDATA_HPP
#define PARAMDATA_HPP

#include "../param/param.hpp"

using gen::Param;

namespace GenData
{

class ParamData
{
protected:
    ParamData()
    : _params()
    {}

public:

    inline std::vector<Param *>   &params()
    { return _params; }

//    Param   *paramFromName(const std::string &n)
//    {
//        for (const auto &p: _params)
//            if (p->name() == n)
//                return p;
//        return (nullptr);
//    }

protected:
    ///
    /// \brief user disposable parameters
    ///
    std::vector<Param *>  _params;    
};

}

#endif /* PARAMDATA_HPP */

