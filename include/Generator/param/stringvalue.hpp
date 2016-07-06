/* 
 * File:   stringvalue.hpp
 * Author: marie
 *
 * Created on 6 juillet 2016, 20:37
 */

#ifndef STRINGVALUE_HPP
#define STRINGVALUE_HPP

#include "param.hpp"

namespace gen
{

class StringValue : public Param
{
public:

    StringValue(const std::string &namee = "") :
        Param(STRINGVALUE, namee),
        m_value("")
    {}

    virtual ~StringValue() {}

    inline  void    setValue(std::string valuee)
    { m_value = valuee; }

    inline std::string      value()
    { return m_value; }


private:
    std::string     m_value;
};

}

#endif /* STRINGVALUE_HPP */

