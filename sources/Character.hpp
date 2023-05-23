#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <string>
namespace ariel
{

    class Character
    {

    protected:
        std::string name;
        int hitPoints;
        Point location;
        int team_;
      //  bool alive_;

    public:
        Character(const std::string &name, const Point &location, int hitPoints);
        virtual ~Character();
        int getHitPoints() const;
        void setHitPoints(int hitPoints);
        bool isAlive() const;
        double distance(const Character *other) const;
        void hit(int amount);
        std::string getName() const;
        Point getLocation() const;
        void print() const;
        void setTeam();
        int getTeam() const;
       // void setAlive(bool alive);
    };

}

#endif // CHARACTER_HPP
