#ifndef TRAINEDNINJE_HPP
#define TRAINEDNINJE_HPP

#include <string>
//#include "Character.hpp"
#include "Ninja.hpp"
namespace ariel
{

class TrainedNinja : public Ninja
    {
    public:
        TrainedNinja(const std::string &name, const Point &location);
        virtual ~TrainedNinja();
        std::string print() const;
    };

}
#endif //TRAINEDNINJE_HPP// 