//#include "Character.hpp"
#include "YoungNinja.hpp"
namespace ariel
{


YoungNinja::YoungNinja(const std::string &name, const Point &location)
        :Ninja(name,location, 100, 14)  {}

    //YoungNinja::~YoungNinja() {}

    
    std::string YoungNinja::print() const
    {
        std::string output = "Character: N (Young Ninja), Name: " + getName() + ", Hit Points: " + std::to_string(hitPoints) + ", Location: ";
        output = output + "(" + std::to_string(getLocation().getX()) + "," + std::to_string(getLocation().getY()) + ")";

        return output;
    }
}