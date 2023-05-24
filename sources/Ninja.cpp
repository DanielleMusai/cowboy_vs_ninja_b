#include "Ninja.hpp"
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
using namespace std;

namespace ariel
{

Ninja::Ninja(const std::string& name, const Point& location)
:Character(name,location){};
        

 void Ninja::slash(Character *other)
    {
        if(!other->isAlive())
            throw std::runtime_error("Cannot attack a dead enemy. (Ninja::slash)");

        if (other == this)
            throw std::runtime_error("Cannot attack himself. (Ninja::slash)");

        if (!isAlive())
            throw std::runtime_error("Cannot attack with a dead character. (Ninja::slash)");

        if (other->isAlive())
        {
            double distance = this->getLocation().distance(other->getLocation());
            if (distance <= 1.0)
                other->hit(40);
        }
    }
   
    
   void Ninja::move(Character* other){
        Point temp=this->getLocation().moveTowards(this->getLocation(),other->getLocation(),this->_speed);
        this->setlocation(temp.getX(),temp.getY());
        
   };
   }