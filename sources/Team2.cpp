#include "Team2.hpp"

using namespace ariel;

Team2::Team2(Character *leader) : Team(leader)
{
}

//   Team2::~Team2()
//     {
//         for (Character *fighter : fighters_)
//         {
//             delete fighter;
//         }
//     }

void Team2::attack(Team *other)
{

    if (other == nullptr)
    {
        throw std::invalid_argument("Invalid target team.");
    }

    if (stillAlive() == 0 || other->stillAlive() == 0)
    {
        throw std::runtime_error("Cannot attack a dead team.");
    }

    Character *enemyLeader = other->getLeader();
    if (!enemyLeader->isAlive())
    {
        enemyLeader = other->closeToleader(other);
        if (enemyLeader == nullptr)
        {
            throw std::runtime_error("Cannot find a valid leader to attack with.");
        }
    }

    for (Character *fighter : fighters_)
    {
        Character *enemy = closeToleader(other);

        if (enemy != nullptr)
        {
            Cowboy *temp_c = dynamic_cast<ariel::Cowboy *>(fighter);
            if (temp_c != nullptr && temp_c->hasboolets() && temp_c->isAlive() && enemy->isAlive())
            {
                temp_c->shoot(enemy);
            }
            else if (temp_c != nullptr && temp_c->isAlive())
            {
                temp_c->reload();
            }

            Ninja *temp_n = dynamic_cast<ariel::Ninja *>(fighter);
            if (temp_n != nullptr && temp_n->getLocation().distance(enemy->getLocation()) <= 1 && enemy->isAlive() && temp_n->isAlive())
            {
                temp_n->slash(enemy);
            }
            else if (temp_n != nullptr && temp_n->isAlive())
            {
                temp_n->move(enemy);
            }
        }
    }
}
