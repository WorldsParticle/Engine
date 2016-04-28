#ifndef GENERATIONSTEP_H
#define GENERATIONSTEP_H

#include "../map/map.hpp"
#include "../param/param.hpp"
#include <list>

namespace gen
{

///
/// \brief This abstract class describes the backbone of a map's generation step.
///
class GenerationStep
{
public:
    ///
    /// \brief Default constructor.
    ///
    GenerationStep(const std::string &name) : m_name(name), m_params(), m_map(nullptr) {}

    inline void launch(map::MapGraph *map)
    { m_map = map; run(); }

    ///
    /// \brief Destructor
    ///
    virtual ~GenerationStep() {}

    ///
    /// \brief name getter
    /// \return name
    ///
    inline const std::string    &name() const
    { return m_name; }

    ///
    /// \brief params getter
    /// \return params
    ///
    inline std::list<Param *>   &params()
    { return m_params; }

    ///
    /// \brief paramFromName
    /// \param name
    /// \return param
    ///
    Param   *paramFromName(const std::string &name);

protected:
    ///
    /// \brief Run the step
    ///
    virtual void    run() = 0;

    ///
    /// \brief Name of the step
    ///
    const std::string   m_name;

    ///
    /// \brief user disposable parameters
    ///
    std::list<Param *>  m_params;

    map::MapGraph       *m_map;
};

}

#endif // GENERATIONSTEP_H
