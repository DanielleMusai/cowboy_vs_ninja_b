#include "Character.hpp"
#include <iostream>

namespace ariel
{
    Character::Character(const std::string &name, const Point &location, int hitPoints)
        : name(name), location(location), hitPoints(hitPoints) {}

    Character::~Character() {}

    int Character::getHitPoints() const
    {
        return hitPoints;
    }

    void Character::setHitPoints(int hitPoints)
    {
        hitPoints = hitPoints;
    }
    bool Character::isAlive() const
    {
        return hitPoints > 0;
    }

    double Character::distance(const Character *other) const
    {
        return location.distance(other->getLocation());
    }

    void Character::hit(int amount)
    {
        if (amount < 0)
        {
            throw std::invalid_argument("negative value");
        }
        hitPoints -= amount;
    }

    std::string Character::getName() const
    {
        return name;
    }

    Point Character::getLocation() const
    {
        return location;
    }

    void Character::print() const
    {
        if (isAlive())
        {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Hit Points: " << hitPoints << std::endl;
            std::cout << "Location: (" << location.getX() << ", " << location.getY() << ")" << std::endl;
        }
        else
        {
            std::cout << "Name: " << name << std::endl;
            std::cout << "Character is dead." << std::endl;
            std::cout << "Location: (" << location.getX() << ", " << location.getY() << ")" << std::endl;
        }
    }

    void Character::fighterchange(bool x)
    {
        // teamfighter_ = !teamfighter_;
        teamfighter_ = x;
    }

    // int Character::getTeam() const {
    //     return team_;
    // }

    bool Character::teamFighter() const
    {
        return teamfighter_;
    }

    //     void Character::setAlive(bool alive) {
    //     alive_ = alive;
    // }

} // namespace ariel