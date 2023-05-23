#ifndef OLDNINJA_HPP
#define OLDNINJA_HPP

#include <string>
//#include "Character.hpp"
#include "Ninja.hpp"
namespace ariel
{


class OldNinja : public Ninja
    {
    public:
        OldNinja(const std::string &name, const Point &location);
       // virtual ~OldNinja();
        std::string print() const;
    };

}
 #endif //OLDNINJA_HPP//