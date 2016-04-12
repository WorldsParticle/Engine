#ifndef POINT_H
#define POINT_H

#include <iostream>
#include <limits>
#include <cmath>

class   Point
{
public:
    explicit Point(double nx, double ny) : x(nx), y(ny) {}

    inline friend std::ostream &operator<<(std::ostream &os, const Point &p)
    { return os << "(" << p.x << ", " << p.y << ")"; }

    inline bool operator==(const Point &other)
    { return (std::abs(x - other.x) < std::numeric_limits<double>::epsilon())
                && (std::abs(y - other.y) < std::numeric_limits<double>::epsilon()); }

    inline bool operator!=(const Point &other)
    { return !(*this == other); }

    double  x;
    double  y;
};

#endif // POINT_H
