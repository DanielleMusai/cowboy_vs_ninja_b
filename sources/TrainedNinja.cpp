#include "TrainedNinja.hpp"
using namespace std;

namespace ariel
{

    TrainedNinja::TrainedNinja(const std::string &name, const Point &location)
        : Ninja(name, location)
    {
        this->_type = "N";
        this->_hitPoint = 120;
        this->_speed = 12;
        this->_fighter = false;
    }
}