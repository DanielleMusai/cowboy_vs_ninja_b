#ifndef TEAM_HPP
#define TEAM_HPP
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "SmartTeam.hpp"
#include "TrainedNinja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
namespace ariel
{
    class Team
    {
    private:
        Character *leader_;
        Character *findCharacter(const Character *character, const std::vector<Character *> &characters) const;
        void chooseNewLeader();


    public:
   std::vector<Character *> fighters_;
        Team() : leader_(nullptr) {};
        Team(Character *leader);
        void add(Character *fighter);
        void attack(Team *enemyTeam);
        int stillAlive() const;
        void print() const;
        ~Team();
        
    };
}

#endif // TEAM_HPP