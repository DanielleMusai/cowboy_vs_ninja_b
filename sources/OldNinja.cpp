#include "OldNinja.hpp"
using namespace std;

namespace ariel
{

    OldNinja::OldNinja(const std::string &name, const Point &location)
        : Ninja(name, location)
    {
        this->_type = "N";
        this->_hitPoint = 150;
        this->_speed = 8;
        this->_fighter = false;
    }
}