#ifndef TEAM2_HPP
#define TEAM2_HPP
// #include <algorithm>
// #include <vector>
// #include <iostream>
// #include <limits>

// #include <vector>
// #include "Character.hpp"
#include "Team.hpp"

namespace ariel
{
     // class Team; 
    class Team2 : public Team
    {
    private:
        std::vector<Character*> fighters_;
        Character* leader_;

        Character* findCharacter(const Character* character, const std::vector<Character*>& characters) const;
        void chooseNewLeader();

    public:
        Team2(Character* leader);
        void add(Character* fighter);
      
        void attack(Team* enemyTeam);
        int stillAlive() const;
        void print() const;
         ~Team2();

         
    };
} // namespace ariel

#endif // TEAM2_HPP