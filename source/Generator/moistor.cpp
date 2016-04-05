#include "Generator/moistor.hpp"
#include <ctime>
#include <cstdlib>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>

#include "Generator/map/map.hpp"

namespace MOI
{

Moistor::Moistor()
{
    _step = MOISTING;
}

Moistor::~Moistor()
{
}

void    Moistor::run()
{
    assignCornerMoisture();
    redistributeMoisture();
    assignPolygonMoisture();
}


// assigne l'humidité des polygones en faisant la moyenne de la somme de celle des sommets
void        Moistor::assignPolygonMoisture()
{
    for (auto & z : _map->zones())
    {
        float sumMoisture = 0.0f;
        for (auto corner : z.second->corners)
        {
            if (corner->moisture > 1.0f)
                corner->moisture = 1.0f;
            sumMoisture += corner->moisture;
        }
        z.second->moisture = sumMoisture / static_cast<float>(z.second->corners.size());
    }
}

struct sortByMoisture
{
  bool operator() (map::Corner *L, map::Corner *R) { return L->moisture < R->moisture; }
};

// redistribue l'humidité de 0 à 1.0 uniformément
void        Moistor::redistributeMoisture()
{
    std::vector<map::Corner *> corners;

    for (const auto & corner : _map->corners())
    {
        if (!corner.second->ocean && !corner.second->coast)
            corners.push_back(corner.second);
    }
    std::sort(corners.begin(), corners.end(), sortByMoisture());
    for (unsigned int i = 0; i < corners.size(); ++i)
    {
        corners[i]->moisture = static_cast<float>(i) / (static_cast<float>(corners.size()) - 1.0f);
    }
}

// calcule l'humidité d'un sommet de polygone
void        Moistor::assignCornerMoisture()
{
    std::queue<map::Corner *> q;

    // si le sommet est lié à un point d'eau, ou si il possède une rivière,
    // on lui assigne un humidité et on le push dans la queue
    for (auto & c : _map->corners())
    {
        auto corner = c.second;
        if ((corner->water || corner->river > 0) && !corner->ocean)
        {
            corner->moisture = corner->river > 0 ? std::min(3.0f, (0.2f * corner->river)) : 1.0f;
            q.push(corner);
        }
        else
        {
            corner->moisture = 0.0;
        }
    }

    float   newMoisture = 0.0;

    // on propage l'humidité des rivières et zones d'eau vers les zones sèches,
    // en diminuant l'humidité de 10% à chaque bond.
    while (q.size())
    {
        auto corner = q.front();
        q.pop();

        for (auto adj : corner->adjacent)
        {
            newMoisture = corner->moisture * 0.9f;
            if (newMoisture > adj->moisture)
            {
                adj->moisture = newMoisture;;
                q.push(adj);
            }
        }
    }

    // l'humidité est au maximum pour les océans et beachs.
    for (auto & corner : _map->corners())
    {
        if (corner.second->ocean || corner.second->coast)
            corner.second->moisture = 1.0;
    }
}


}
