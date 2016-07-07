#ifndef GENERATIONSTEP_H
#define GENERATIONSTEP_H

#include "../map/map.hpp"
#include "../param/param.hpp"
#include <list>

#include "Engine/Configuration.hpp"

namespace gen
{

///
/// \brief This abstract class describes the backbone of a map's generation step.
///
class ENGINE_EXPORTS GenerationStep
{
public:
    GenerationStep(const std::string &namee)
        : m_name(namee), m_params(), m_map(nullptr) {}

    GenerationStep(const GenerationStep &other)
        : m_name(other.name()), m_params(), m_map(nullptr) {}

    GenerationStep(GenerationStep &&other) noexcept
        : m_name(other.name()), m_params(), m_map(nullptr) {}

    virtual ~GenerationStep() {}

    GenerationStep& operator=(const GenerationStep &other)
    {if (other.name() != ""){} /* TODO */ return *this;}

    GenerationStep& operator=(GenerationStep &&other) noexcept
    { if (other.name() != ""){} /* TODO */ return *this;}

public:
    inline void launch(map::MapGraph *map)
    { m_map = map; run(); }

    inline const std::string    &name() const
    { return m_name; }

    inline std::list<Param *>   &params()
    { return m_params; }

    Param   *paramFromName(const std::string &namee);

protected:
    virtual void    run() = 0;

    const std::string   m_name;

    std::list<Param *>  m_params;

    map::MapGraph       *m_map;
};

}

#endif // GENERATIONSTEP_H
