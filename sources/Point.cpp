#include "Point.hpp"
#include <string>
#include <iostream>
#include <math.h>
using namespace std;

namespace ariel
{

    Point::Point(double dtx, double dty)
        : _dtx(dtx), _dty(dty){};

    double Point::getX() const
    {
        return _dtx;
    }
    double Point::getY() const
    {
        return _dty;
    }

    double Point::distance(const Point &other) const
    {
        double dx = _dtx - other._dtx;
        double dy = _dty - other._dty;
        return std::sqrt(dx * dx + dy * dy);
    };

    Point Point::moveTowards(const Point &source, const Point &target, double distance)
    {
        if (distance < 0)
        {
            throw std::invalid_argument("distance cannot br negative");
        }

        double dis = source.distance(target);
        if (dis <= distance)
        {
            return target;
        }
        else
        {

            double ratio = distance / dis;
            double dx = target.getX() - source.getX();
            double dy = target.getY() - source.getY();
            Point res = Point(source.getX() + ratio * dx, source.getY() + ratio * dy);
            return res;
        }
    }

    void Point::print()
    {
        cout << "(" << getX() << "," << getY() << ")" << endl;
    }
}