#ifndef INTVALUE_HPP
#define INTVALUE_HPP

#include "param.hpp"

namespace gen
{

class IntValue : public Param
{
public:

    ///
    /// \brief IntValue default constructor
    /// \param name
    ///
    IntValue(const std::string &name = "") :
        Param(intvalue, name),
        m_minValue(0),
        m_maxValue(100),
        m_value(0)
    {}

    ///
    /// \brief ~IntValue
    ///
    virtual ~IntValue() {}

    ///
    /// \brief setMinValue
    ///
    inline  void    setMinValue(int minValue)
    { m_minValue = minValue; }

    ///
    /// \brief setMaxValue
    ///
    inline  void    setMaxValue(int maxValue)
    { m_maxValue = maxValue; }

    ///
    /// \brief setValue
    ///
    inline  void    setValue(int value)
    { m_value = value; }

    ///
    /// \brief minValue getter
    ///
    inline int      minValue()
    { return m_minValue; }

    ///
    /// \brief minValue getter
    ///
    inline int      maxValue()
    { return m_maxValue; }

    ///
    /// \brief minValue getter
    ///
    inline int      value()
    { return m_value; }


private:
    int     m_minValue;
    int     m_maxValue;
    int     m_value;
};

}

#endif /* PARAM_HPP */
