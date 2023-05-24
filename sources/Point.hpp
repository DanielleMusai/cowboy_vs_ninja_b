#ifndef POINT_HPP
#define POINT_HPP

namespace ariel{

class Point {
    private:
        double _dtx;
        double _dty;
        
    public:
        Point(double dtx, double dty);
        virtual ~Point(){};
        double getX() const;
        double getY() const;
        double setX(double dtx) {return this->_dtx=dtx;}
        double setY(double dty){return this->_dty=dty;}
        double distance(const Point& other)const;
        static Point moveTowards(const Point& source, const Point& target, double distance);
        void print();

    
    };

}
#endif