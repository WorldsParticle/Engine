#ifndef HEIGHTPOINT_H
#define HEIGHTPOINT_H

#include <iostream>
#include <memory>
#include <cmath>
#include <limits>
#include "zone.hpp"

class   HeightPoint
{
public:
    HeightPoint() : x(0.0), y(0.0), z(0.0), zone(nullptr) {}
    HeightPoint(double nx, double ny) : x(nx), y(ny), z(0.0), zone(nullptr) {}

    inline friend std::ostream &operator<<(std::ostream &os, const HeightPoint &p)
    { return os << "(" << p.x << ", " << p.y << ", " << p.z << ")"; }

    inline bool operator==(const HeightPoint &other)
    { return (std::abs(x - other.x) < std::numeric_limits<double>::epsilon())
                && (std::abs(y - other.y) < std::numeric_limits<double>::epsilon()); }

    inline bool operator!=(const HeightPoint &other)
    { return !(*this == other); }

    double  x;
    double  y;
    double  z;

    map::Zone     *zone;
};

#endif // HEIGHTPOINT_H
