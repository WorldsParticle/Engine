#include "Generator/elevator.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>

#include "Generator/map/map.hpp"

namespace ELE
{

Elevator::Elevator()
{
    _step = ELEVATE;
}

Elevator::~Elevator()
{
}

void    Elevator::run()
{
    assignCornerElevation();
    redistributeElevation();
    setPolygonElevation();
    calculateDownSlopes();
}


void        Elevator::assignCornerElevation()
{
    std::queue<std::shared_ptr<MAP_NAMESPACE::Corner>>   q;
int a = 0;
    for (auto & corner : _map->corners())
    {

        if (corner.second->border)
        {
            ++a;
            corner.second->elevation = 0.0;
            q.push(corner.second);
        }
        else
            corner.second->elevation = std::numeric_limits<float>::max();
    }

    while (q.size())
    {
	std::shared_ptr<MAP_NAMESPACE::Corner> corner = q.front();
        q.pop();

        for (std::shared_ptr<MAP_NAMESPACE::Corner> adj : corner->adjacent)
        {
            float newElevation = 0.00001f + corner->elevation;
            if (!corner->water && !adj->water)
            {
                newElevation += 1.0f;
                // add randomness here if map looks too dull
            }
            if (newElevation < adj->elevation)
            {
                adj->elevation = newElevation;
                q.push(adj);
            }
        }
    }
}


struct sortByElevation
{
  bool operator() (std::shared_ptr<MAP_NAMESPACE::Corner> L, std::shared_ptr<MAP_NAMESPACE::Corner> R) { return L->elevation < R->elevation; }
};

void        Elevator::redistributeElevation()
{
    float scaleFactor = 1.1f;
    std::vector<std::shared_ptr<MAP_NAMESPACE::Corner>> corners;

    for (const auto & corner : _map->corners())
    {
        if (!corner.second->ocean)
            corners.push_back(corner.second);
    }
    std::sort(corners.begin(), corners.end(), sortByElevation());

    for (unsigned int i = 0; i < corners.size(); ++i)
    {
       float y, x;

       y = static_cast<float>(i) / static_cast<float>(corners.size() - 1);
       x = sqrt(scaleFactor) - sqrt(scaleFactor * (1.0f - y));
       if (x > 1.0f)
           x = 1.0f;
       corners[i]->elevation = x;
    }

}

void        Elevator::setPolygonElevation()
{
    for (const auto & zone : _map->zones())
    {
        float sumElevation = 0.0;
        for (auto corner : zone.second->corners)
        {
            sumElevation += corner->elevation;
        }
        zone.second->elevation = sumElevation / static_cast<float>(zone.second->corners.size());
    }
}

void        Elevator::calculateDownSlopes()
{
    for (const auto & q : _map->corners())
    {
	std::shared_ptr<MAP_NAMESPACE::Corner> steepest = q.second;
        for (std::shared_ptr<MAP_NAMESPACE::Corner> neighbor : q.second->adjacent)
        {
            if (neighbor->elevation < steepest->elevation)
                steepest = neighbor;
        }
        q.second->downslope = steepest;
    }
}


}
