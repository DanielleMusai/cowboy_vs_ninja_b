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
namespace ariel
{
    using namespace std;
    class Team
    {
    protected:
        static const int MAX_FIGHTERS = 10;
        std::vector<Character *> _fighters;
        Character *_leader;

    public:
        Team(Character *leader);
        virtual void add(Character *member);
        virtual void attack(Team *other);
        void updateLeader();
        void attackCowboys(Team *other);
        void attackNinjas(Team *other);
        virtual Character *closeToleader(Team *other);
        virtual Character *getLeader() { return this->_leader; }
        virtual int stillAlive() const;
        virtual void print() const;
        virtual ~Team();
    };

}

#endif // TEAM_HPP