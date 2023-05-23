#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <string>
#include "Character.hpp"
#include <stdexcept>
using namespace std;
namespace ariel
{
  
  
  class Cowboy : public Character
    {
    private:
        int bullets;

    public:
        Cowboy(const std::string &name, const Point &location);
        virtual ~Cowboy();

        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
        std::string print() const;
    };
}
#endif //COWBOY_HPP//