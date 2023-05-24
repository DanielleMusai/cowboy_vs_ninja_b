#include "Cowboy.hpp"
#include <string>
#include <stdexcept>

namespace ariel
{
Cowboy::Cowboy(const std::string& name, const Point& location)
:Character(name,location), _stack(6){
    this->_type="C";
    this->_hitPoint=110;

}

 void Cowboy::shoot(Character *other)
    {
        if (other == this)
            throw std::runtime_error("Cannot shoot oneself. (Cowboy::shoot)");

        if (!isAlive())
            throw std::runtime_error("Cannot attack with a dead character. (Cowboy::shoot)");

        if (other->isAlive())
        {
            if (_stack > 0)
            {
                other->hit(10);
                _stack--;
            }
        }
        else
        {
           throw std::runtime_error("Cannot attack a dead enemy. (Cowboy::shoot)");
        }
    }

    bool Cowboy::hasboolets() const
    {
        return _stack > 0;
    }

    void Cowboy::reload()
    {
        if (!isAlive())
        {
            throw std::runtime_error("Cannot reload with a dead character");
        }
        _stack = 6;
    }

}