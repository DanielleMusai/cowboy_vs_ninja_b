//#include "Character.hpp"
#include "OldNinja.hpp"
namespace ariel
{

    OldNinja::OldNinja(const std::string &name, const Point &location)
        : Ninja(name,location, 150, 8) {}

  // OldNinja::~OldNinja() {}

    std::string OldNinja::print() const
    {
        std::string output = "Character: N (Old Ninja), Name: " + getName() + ", Hit Points: " + std::to_string(hitPoints) + ", Location: ";
        output = output + "(" + std::to_string(getLocation().getX()) + "," + std::to_string(getLocation().getY()) + ")";

        return output;
    }
}