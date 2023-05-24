#include "YoungNinja.hpp"
using namespace std;

namespace ariel
{

    YoungNinja::YoungNinja(const std::string &name, const Point &location)
        : Ninja(name, location)
    {
        this->_type = "N";
        this->_hitPoint = 100;
        this->_speed = 14;
        this->_fighter = false;
    }
}