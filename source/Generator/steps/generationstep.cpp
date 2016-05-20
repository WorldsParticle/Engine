#include "Generator/steps/generationstep.hpp"

namespace gen
{

Param  *GenerationStep::paramFromName(const std::string &namee)
{
    for (const auto &p: m_params)
        if (p->name() == namee)
            return p;
    return (nullptr);
}

}
