// #include "Character.hpp"
#include "Cowboy.hpp"
using namespace std;
namespace ariel
{

    Cowboy::Cowboy(const std::string &name, const Point &location)
        : Character(name, location, 110), bullets(6) {}

    Cowboy::~Cowboy() {}

    void Cowboy::shoot(Character *enemy)
    {
        if (enemy == this)
        {
            throw std::runtime_error("Cannot shoot oneself.");
        }
        if (!isAlive())
        {
            throw std::runtime_error("Cannot attack when dead.");
        }
        if (!enemy->isAlive())
        {
            throw std::runtime_error("Cannot attack a dead enemy.");
        }

        if (hasboolets())
        {
            enemy->hit(10);
            bullets--;
        }
    }

    bool Cowboy::hasboolets() const
    {
        return bullets > 0;
    }

    void Cowboy::reload()
    {

        if (!this->isAlive())
        {
            throw std::runtime_error("Cannot attack when dead.");
        }

        // const int maxBullets = 6; // Maximum number of bullets in the magazine

        // if (bullets == 0) {
        bullets = 6;
        //}
    }

    std::string Cowboy::print() const
    {
        std::string output = "Character: C (Cowboy), Name: " + getName() + ", Hit Points: " + std::to_string(hitPoints) + ", Location: ";
        output = output + "(" + std::to_string(getLocation().getX()) + "," + std::to_string(getLocation().getY()) + ")";
        return output;
    }

}