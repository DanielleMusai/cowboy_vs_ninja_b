#ifndef COWBOY_HPP
#define COWBOY_HPP

#include "Character.hpp"
using namespace std;
namespace ariel
{

    class Cowboy : public Character
    {
    private:
        int _stack;
        //static constexpr int DEFAULT_BULLETS = 6;
       // static constexpr int DEFAULT_LIVE = 110;

    public:
        Cowboy(const std::string &name, const Point &location);
        void shoot(Character *other);
        bool hasboolets() const;
        void reload();
    };
}
#endif