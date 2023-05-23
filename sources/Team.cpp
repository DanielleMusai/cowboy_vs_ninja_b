#include "Team.hpp"
#include <iostream>
#include <algorithm>
using namespace std;
namespace ariel
{
    Team::Team(Character *leader)
    {
        if (leader != nullptr && !leader->getTeam())
        {
            throw std::runtime_error("The character is already in a team.");
        }
        leader_ = leader;

        if (leader != nullptr)
        {
            leader->setTeam();
            //fighters_.push_back(leader_);
        }
    }

    void Team::add(Character *fighter)
    {
        if (fighter != nullptr)
        {
            throw std::runtime_error("Character is already in a team.");
        }

        if (fighters_.size() >= 10)
        {
            throw std::runtime_error("Team is already at maximum capacity.");
        }

        fighter->setTeam();
        fighters_.push_back(fighter);
    }

    void Team::chooseNewLeader()
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

    Character *Team::findCharacter(const Character *character, const std::vector<Character *> &characters) const
    {
        Character *closestVictim = nullptr;
        double minDistance = std::numeric_limits<double>::max();

        for (Character *fighter : characters)
        {
            if (fighter->isAlive())
            {
                double distance = character->distance(fighter);
                if (distance < minDistance)
                {
                    minDistance = distance;
                    closestVictim = fighter;
                }
            }
        }

        return closestVictim;
    }

    void Team::attack(Team *enemyTeam)
    {
        if (enemyTeam == nullptr)
        {
            throw std::invalid_argument("Invalid target character.");
          
        }
        if (stillAlive() == 0 || enemyTeam->stillAlive() == 0)
        {
            return; 

        if (!leader_->isAlive())
        {
            chooseNewLeader(); // if the leader is die we will choose other leader
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

    int Team::stillAlive() const
    {
        int aliveCount = 1;
        for (const auto &fighter : fighters_)
        {
            if (fighter->isAlive())
            {
                aliveCount++;
            }
        }
        return aliveCount;
    }

    void Team::print() const
    {
        for (const auto &fighter : fighters_)
        {
            fighter->print();
        }
    }

    Team::~Team()
    {
        for (Character *fighter : fighters_)
        {
            delete fighter;
        }
    }
} // namespace ariel
