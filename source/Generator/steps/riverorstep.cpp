#include "Generator/steps/riverorstep.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <algorithm>

namespace gen
{

RiverorStep::RiverorStep() :
    GenerationStep("Assignement des rivières")
{
}

RiverorStep::~RiverorStep()
{
}

void    RiverorStep::run()
{
    createRivers();
    calculateWatersheds();
}

void        RiverorStep::calculateWatersheds()
{
    for (auto & corner : m_map->corners())
    {
        corner.second->watershed = corner.second;
        if (!corner.second->ocean && !corner.second->coast)
        {
            corner.second->watershed = corner.second->downslope;
        }
    }

    bool changed;
    for (int i = 0; i < 100; ++i)
    {
        changed = false;
        for (auto & c : m_map->corners())
        {
            auto corner = c.second;
            if (!corner->ocean && !corner->coast && !corner->watershed->coast)
            {
        map::Corner *adj = corner->downslope->watershed;
                if (!adj->ocean)
                {
                    corner->watershed = adj;
                    changed = true;
                }
            }
        }
        if (!changed) break;
    }

    for (auto & corner : m_map->corners())
    {
    map::Corner *adj = corner.second->watershed;
        adj->watershedSize += 1;
    }
}

void        RiverorStep::createRivers()
{
    for (unsigned int i; i < (m_map->zones().size() / 2); ++i)
    {
    map::Corner *corner = m_map->corners().at(rand() % static_cast<int>(m_map->corners().size()));
        if (corner->ocean || corner->elevation < 0.3f || corner->elevation > 0.9f)
            continue;
        while (!corner->coast)
        {
            if (corner->downslope == corner)
                break;
        map::CrossedEdge *edge = lookupEdgeFromCorner(corner, corner->downslope);
            edge->river += 1;
            corner->river += 1;
            corner->downslope->river += 1;
            corner = corner->downslope;
        }
    }
}

map::CrossedEdge *RiverorStep::lookupEdgeFromCorner(map::Corner *from, map::Corner *to)
{
    for (map::CrossedEdge *edge : from->edges)
    {
        if (edge->c0 == to || edge->c1 == to)
            return (edge);
    }
    return (nullptr);
}


}
