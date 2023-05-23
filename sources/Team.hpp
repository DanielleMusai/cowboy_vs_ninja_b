#ifndef TEAM_HPP
#define TEAM_HPP

#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "Character.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Point.hpp"
#include "Cowboy.hpp"
using namespace std;
namespace ariel
{

    class Team
    {
    public:
        Team(Character *leader);
        virtual ~Team();
        virtual void add(Character *fighter);
        virtual void attack(Team *other);
        virtual int stillAlive() const;
        virtual void print() const;
        virtual Character *closeToleader(Team *other);
        virtual Character *getLeader() { return this->leader_; }

    protected:
        std::vector<Character *> fighters_;
        Character *leader_;
    };

}

#endif // TEAM_HPP