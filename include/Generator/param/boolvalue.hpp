/* 
 * File:   boolvalue.hpp
 * Author: marie
 *
 * Created on 6 juillet 2016, 20:41
 */

#ifndef BOOLVALUE_HPP
#define BOOLVALUE_HPP

#include "param.hpp"

namespace gen
{

class BoolValue : public Param
{
public:

    BoolValue(const std::string &namee = "") :
        Param(BOOLVALUE, namee),
        m_value(false)
    {}

    virtual ~BoolValue() {}

    inline  void    setValue(bool valuee)
    { m_value = valuee; }

    inline bool      value()
    { return m_value; }


private:
    bool     m_value;
};

}

#endif /* BOOLVALUE_HPP */

