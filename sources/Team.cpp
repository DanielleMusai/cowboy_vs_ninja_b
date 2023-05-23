#include "Team.hpp"
#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdexcept>
using namespace std;
namespace ariel
{
    Team::Team(Character *leader)
    {
        if (leader->teamFighter())
        {
            throw std::runtime_error("member in other team");
        }
        else
        {
            fighters_.push_back(leader);
            leader_ = leader;
            leader->fighterchange(true);
        }
    }

    void Team::add(Character *fighter)
    {
        if (fighter->teamFighter())
        {
            throw std::runtime_error("Character is already in a team.");
        }

        if (fighters_.size() >= 10)
        {
            throw std::runtime_error("Team is already at maximum capacity.");
        }

        fighters_.push_back(fighter);
        fighter->fighterchange(true);
    }

    void Team::attack(Team *other)
    {

        if (other == nullptr)
        {
            throw std::invalid_argument("Invalid target team.");
        }

        if (stillAlive() == 0 || other->stillAlive() == 0)
        {
            throw std::runtime_error("Cannot attack a dead team.");
        }

        if (!leader_->isAlive())
        {
            leader_ = closeToleader(other);
            if (leader_ == nullptr)
            {
                throw std::runtime_error("Cannot find a valid leader to attack with.");
            }
        }

        Character *enemy = closeToleader(other);
        if (enemy == nullptr)
        {
            return; // No enemy characters available to attack
        }

        for (Character *fighter : fighters_)
        {
            Cowboy *cowboy = dynamic_cast<Cowboy *>(fighter);
            if (cowboy && cowboy->hasboolets() && cowboy->isAlive() && enemy->isAlive())
            {
                cowboy->shoot(enemy);
            }
            else if (cowboy && cowboy->isAlive())
            {
                cowboy->reload();
            }

            Ninja *ninja = dynamic_cast<Ninja *>(fighter);
            if (ninja && ninja->getLocation().distance(enemy->getLocation()) <= 1 && ninja->isAlive() && enemy->isAlive())
            {
                ninja->slash(enemy);
            }
            else if (ninja && ninja->isAlive())
            {
                ninja->move(enemy);
            }
        }
    }

    Character *Team::closeToleader(Team *other)
    {

        double temp_dis = std::numeric_limits<double>::max();
        Character *temp = nullptr;

        for (Character *fighter : other->fighters_)
        {
            double dis = this->leader_->getLocation().distance(fighter->getLocation());
            if (dis < temp_dis && fighter->isAlive())
            {
                temp_dis = dis;
                temp = fighter;
            }
        }
        return temp;
    };
    int Team::stillAlive() const
    {
        int aliveCount = 0;
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