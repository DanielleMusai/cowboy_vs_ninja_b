#ifndef YOUNGNINJA_HPP
#define YOUNGNINJA_HPP

#include <string>
#include "Ninja.hpp"
namespace ariel
{ 
 
 class YoungNinja : public Ninja
    {
    public:
        YoungNinja(const std::string &name, const Point &location);
        virtual ~YoungNinja();
        std::string print() const;
    };
}

#endif //YOUNGNINJA_HPP//