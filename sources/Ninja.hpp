#ifndef NINJA_HPP
#define NINJA_HPP
#include <stdexcept>

#include "Character.hpp"

namespace ariel
{

    class Ninja : public Character
    {
    private:
        int speed;
        int damage;

    public:
        Ninja(const std::string &name, const Point &location,int hitPoints, int speed);
       // virtual ~Ninja();

        void move(Character *enemy);
        void slash(Character *enemy);
     //   std::string print() const;
    };

   
}
#endif //NINJA_HPP//