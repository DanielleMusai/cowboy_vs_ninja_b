#include "Character.hpp"
#include <iostream>
using namespace std;

namespace ariel
{

Character::Character(const std::string &name, const Point &location)
    : _name(name), _location(location), _fighter(false){};

std::string Character::print() const
{
    std::string typeStr = (this->getType() == "C") ? "Type: C" : "Type: N";
    std::string hpStr = (this->_hitPoint > 0) ? "hitPoint: " + std::to_string(this->_hitPoint) : "dead";

    std::string locationStr = "location: ( " + std::to_string(this->_location.getX()) + " , " + std::to_string(this->_location.getY()) + " )";

    return typeStr + " name: " + this->getName() + " " + locationStr + " " + hpStr;
}

double Character::distance(const Character *other) const
{
    return this->_location.distance(other->getLocation());
}

void Character::hit(int damage)
{
    if (damage < 0)
    {
        throw std::invalid_argument("damage cannot be negative");
    }
    _hitPoint -= damage;
}

bool Character::isAlive() const
{
    return _hitPoint > 0;
}

const std::string &Character::getName() const
{
    return _name;
}

const Point &Character::getLocation() const
{
    return _location;
}
int Character::isInTeam() const
{
    return inTeam_;
}

void Character::setInTeam()
{
    inTeam_ = 1;
}
bool Character::isfighter() const
{
    return this->_fighter;
}

void Character::fighter_change()
{
    _fighter = !_fighter;
}


}