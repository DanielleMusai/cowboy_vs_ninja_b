#include "Team2.hpp"
#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
using namespace std;
namespace ariel
{
    Team2::Team2(Character* leader)
    {
        leader_ = leader;
         fighters_.push_back(leader_);
    }

   void Team2::add(Character *fighter)
    {
        if (fighter != nullptr)
        {
            throw std::runtime_error("The character is already in a team.");
        }

        if (fighters_.size() >= 10)
        {
            throw std::runtime_error("Team is already at maximum capacity.");
        }

        fighter->setTeam(); 
        fighters_.push_back(fighter);
    }
    
 Character* Team2::findCharacter(const Character* leader, const std::vector<Character*>& characters) const
{
    Character* closestVictim = nullptr;
    double minDistance = std::numeric_limits<double>::max();

    for (Character* fighter : characters)
    {
        if (fighter->isAlive())
        {
            double distance = leader->distance(fighter);
            if (distance < minDistance)
            {
                minDistance = distance;
                closestVictim = fighter;
            }
        }
    }

    return closestVictim;
}


    void Team2::chooseNewLeader()
   {
        leader_ = nullptr;
        double minDistance = std::numeric_limits<double>::max();
        for (Character *fighter : fighters_)
        {
            if (fighter->isAlive())
            {
                double distance = leader_->getLocation().distance(fighter->getLocation());
                if (distance < minDistance)
                {
                    minDistance = distance;
                    leader_ = fighter;
                }
            }
        }
    }

//     void Team2::attack(Team2 *enemyTeam)
// {
//     if (enemyTeam == nullptr)
//     {
//         throw std::invalid_argument("null enemyTeam pointer!");
//     }
//     if (stillAlive() == 0 || enemyTeam->stillAlive() == 0)
//     {
//         return; // End the attack if there are no living members in either group
//     }

//     if (!leader_->isAlive())
//     {
//         chooseNewLeader(); // if the leader dies, choose another leader
//     }

//     for (Character* fighter : fighters_)
//     {
//         if (fighter->isAlive())
//         {
//             Cowboy* cowboy = dynamic_cast<Cowboy*>(fighter);
//             if (cowboy && cowboy->hasboolets())
//             {
//                 Character* victim = enemyTeam->findCharacter(leader_, enemyTeam->fighters_);
//                 if (victim)
//                 {
//                     cowboy->shoot(victim);
//                     int prevHitPoints = victim->getHitPoints();
//                     fighter->hit(10); // Adjust the amount as needed

//                     if (prevHitPoints > 0 && victim->getHitPoints() <= 0)
//                     {
//                         victim->hit(0); // Set hitPoints_ to 0 if the victim died
//                     }
//                 }
//             }
//             else if (cowboy)
//             {
//                 cowboy->reload();
//             }

//             Ninja* ninja = dynamic_cast<Ninja*>(fighter);
//             if (ninja && ninja->isAlive())
//             {
//                 Character* victim = enemyTeam->findCharacter(leader_, enemyTeam->fighters_);
//                 if (victim && ninja->getLocation().distance(victim->getLocation()) <= 1.0)
//                 {
//                     ninja->slash(victim);
//                     int prevHitPoints = victim->getHitPoints();
//                     fighter->hit(10); // Adjust the amount as needed

//                     if (prevHitPoints > 0 && victim->getHitPoints() <= 0)
//                     {
//                         victim->hit(0); // Set hitPoints_ to 0 if the victim died
//                     }
//                 }
//                 else if (victim)
//                 {
//                     ninja->move(victim);
//                 }
//             }
//         }
//     }
// }

   void Team2::attack(Team *enemyTeam)
    {
        if (enemyTeam == nullptr)
        {
            throw std::invalid_argument("Invalid target character.");
        
        }
        if (stillAlive() == 0 || enemyTeam->stillAlive() == 0)
        {
            return; 
        }

        if (!leader_->isAlive())
        {
            chooseNewLeader();
        }

        Character *victim = findCharacter(leader_, enemyTeam->fighters_);
        while (victim)
        {
            for (Character *fighter : fighters_)
            {
                if (fighter->isAlive())
                {
                    Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
                    if (cowboy && cowboy->hasboolets())
                    {
                        cowboy->shoot(victim);
                    }
                    else if (cowboy)
                    {
                        cowboy->reload();
                    }

                    Ninja *ninja = dynamic_cast<Ninja *>(fighter);
                    if (ninja && ninja->getLocation().distance(victim->getLocation()) <= 1.0)
                    {
                        ninja->slash(victim);
                    }
                    else if (ninja)
                    {
                        ninja->move(victim);
                    }

                    int prevHitPoints = victim->getHitPoints();
                    fighter->hit(10);

                    if (prevHitPoints > 0 && victim->getHitPoints() <= 0)
                    {
                        victim->hit(0); 
                    }
                }
            }

            if (!victim->isAlive())
            {
                victim = findCharacter(leader_, enemyTeam->fighters_);
            }
            else
            {
                break;
            }
        }
    }

    // void Team2::print() const
    // {
    //     if (leader_ == nullptr)
    //     {
    //         std::cout << "Team2 has no leader." << std::endl;
    //     }
    //     else
    //     {
    //         std::cout << "Team2 leader: " << leader_->getName() << std::endl;
    //         std::cout << "Team2 fighters: " << std::endl;
    //         for (Character* fighter : fighters_)
    //         {
    //             std::cout << "- " << fighter->getName() << std::endl;
    //         }
    //     }
    // }

    int Team2::stillAlive() const
    {
        int aliveCount = 0;
        for (const auto  &fighter : fighters_)
        {
            if (fighter->isAlive())
            {
                aliveCount++;
            }
        }
        return aliveCount;
    }

void Team2::print() const
    {
        for (const auto &fighter : fighters_)
        {
            fighter->print();
        }
    }
       Team2::~Team2()
    {
        for (Character *fighter : fighters_)
        {
            delete fighter;
        }
    }
} // namespace ariel
