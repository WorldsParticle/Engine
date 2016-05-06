#include "Generator/map/map.hpp"
#include "Generator/zonelookup.hpp"

namespace MAP
{


ZoneLookUp::ZoneLookUp() : _pc2kd(NULL), _tree(NULL)
{

}

ZoneLookUp::~ZoneLookUp()
{
if (_pc2kd)
   delete(_pc2kd);
if (_tree)
   delete(_tree);
}

void    ZoneLookUp::createCloud(MAP::Map & m)
{
    for (const auto & zone : m.zones())
    {
        MAP::ZoneLookUp::PointCloud<double>::LPoint p = {zone.second->point.x, zone.second->point.y, zone.second};
        _cloud.pts.push_back(p);
    }
    _pc2kd = new PC2KD(_cloud);
    _tree = new my_kd_tree_t(2 /*dim*/, *_pc2kd, nanoflann::KDTreeSingleIndexAdaptorParams(10 /* max leaf */) );
    _tree->buildIndex();
}

Zone *  ZoneLookUp::getNearestZone(double x, double y)
{
    double          queryPoint[2] = {x, y};
    const size_t    num_results = 1;
    size_t          ret_index;
    double          out_dist_sqr;

    nanoflann::KNNResultSet<double> resultSet(num_results);
    resultSet.init(&ret_index, &out_dist_sqr );

    _tree->findNeighbors(resultSet, &queryPoint[0], nanoflann::SearchParams(10));
    return (_cloud.pts[ret_index].zone);
}

}