//#include "Character.hpp"
#include "TrainedNinja.hpp"
namespace ariel
{

 
 TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
        : Ninja(name,location, 120,12)  {}

    TrainedNinja::~TrainedNinja() {}

    
    std::string TrainedNinja::print() const
    {
        std::string output = "Character: N (Trained Ninja), Name: " + getName() + ", Hit Points: " + std::to_string(hitPoints) + ", Location: ";
       output = output + "(" + std::to_string(getLocation().getX()) + "," + std::to_string(getLocation().getY()) + ")";

        return output;
    }
}