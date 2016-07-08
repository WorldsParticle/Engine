#ifndef HEIGHTMAPINGSTEP_HPP
#define HEIGHTMAPINGSTEP_HPP

#include "generationstep.hpp"
#include "Generator/map/zonelookup.hpp"

#include "Engine/Configuration.hpp"

namespace gen
{

///
/// \brief The HeightMapingStep class
/// it will fill the heightmap points height
///
class HeightMapingStep : public GenerationStep
{
public:
    HeightMapingStep();
    virtual ~HeightMapingStep();

    virtual void    run() override;

private:
};

}

#endif  /* HEIGHTMAPINGSTEP_HPP */
