#include "Ninja.hpp"
using namespace std;
namespace ariel {



    Ninja::Ninja(const std::string &name, const Point &location, int hitPoints, int speed)
        : Character(name,location,hitPoints), speed(speed) {}
  


    //Ninja::~Ninja() {}

    void Ninja::move(Character* enemy) {
        if (enemy != nullptr && isAlive()) {
            double distance = location.distance(enemy->getLocation());
        if (distance >= 1) {
            double dx = enemy->getLocation().getX() - location.getX();
            double dy = enemy->getLocation().getY() - location.getY();
            double angle = std::atan2(dy, dx);
            double newX = location.getX() + speed * std::cos(angle);
            double newY = location.getY() + speed * std::sin(angle);
            location = Point(newX, newY);
        }
        }
       
    }
void Ninja::slash(Character* enemy) {
         if (enemy == this) {
        throw std::runtime_error("Cannot slash oneself.");
    }

    if (!isAlive()) {
        throw std::runtime_error("Cannot attack when dead.");
    }
    if (!enemy->isAlive()) {
        throw std::runtime_error("Cannot attack a dead enemy.");
    }

        if (enemy->isAlive() && isAlive()) {
            double distance = location.distance(enemy->getLocation());
            if (distance < 1) {
                enemy->hit(40);
           }
        }
    }
} // namespace ariel
