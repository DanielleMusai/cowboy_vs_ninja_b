#ifndef POINT_HPP
#define POINT_HPP

#include <cmath>

namespace ariel {

    class Point {
    private:
        double x;
        double y;

    public:
        Point(double xCoord, double yCoord);
        double getX() const;
        double getY() const;
        double distance(const Point& point) const;
        void print() const;
        static Point moveTowards(const Point& source, const Point& destination, double distance);
        // double setX(double dotx) {return this->x= dotx;}
        // double setY(double doty){return this->y= doty;}
    };

} // namespace ariel

#endif  // POINT_HPP
