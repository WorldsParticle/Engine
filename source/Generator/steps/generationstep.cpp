#include "Generator/steps/generationstep.hpp"

namespace gen
{

Param  *GenerationStep::paramFromName(const std::string &name)
{
    for (const auto &p: m_params)
        if (p->name() == name)
            return p;
}

}
