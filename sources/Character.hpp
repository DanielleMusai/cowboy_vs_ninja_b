#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <string>
using namespace std;
namespace ariel
{
    class Character
    {

    protected:
        string _name;
        Point _location;
        int _hitPoint;
        bool _fighter;
        string _type;
        int inTeam_;

    public:
        Character(const std::string &name, const Point &location);
        virtual ~Character(){};
          virtual const std::string &getName() const;
        virtual const Point &getLocation() const;
        virtual double distance(const Character *other) const;
        virtual void hit(int damage);
        virtual bool isAlive() const;
        virtual int isInTeam() const;
        virtual void setInTeam();
        virtual bool isfighter() const;
        virtual void updateFighterState();
        virtual void setType(string type) { this->_type = type; }
        virtual std::string getType() const { return this->_type; }
        virtual void setlocation(double dtx, double dty)
        {
            this->_location.setX(dtx);
            this->_location.setY(dty);
        }
        virtual std::string print() const;
        // virtual  void setLocation(const Point& newLocation) {
        //     this->_location = newLocation;
        // }
    };

}

#endif