#include "Team.hpp"
#include <math.h>
#include <string>
#include <iostream>
#include <stdexcept>
using namespace std;

namespace ariel
{

Team::Team(Character* leader) {
    
    if(leader->isfighter())
    {
        throw std::runtime_error("fighter is in other team");
        }
        else{
        _fighters.push_back(leader);
        leader->updateFighterState();
       _leader=leader;
    
        }
    }

void Team::add(Character* fighter) {
    if (this->_fighters.size() >= 10 || fighter->isfighter())
    {
        throw std::runtime_error("over 10 fighters");
    }
    fighter->updateFighterState();
    this->_fighters.push_back(fighter);
}

   
   
// If the leader is not alive and there is a closer character, it updates the team leader to the closest character 
void Team::updateLeader() {
    if (!this->_leader->isAlive() && this->closeToleader(this) != nullptr) {
        this->_leader = this->closeToleader(this);
    }
}
//responsible for the attack actions performed by the cowboys in the team
void Team::attackCowboys(Team* other) {
    for (Character* fighter : _fighters) {
        if (fighter->getType() != "C")
            continue;

        Cowboy* temp_c = dynamic_cast<Cowboy*>(fighter);
        if (temp_c == nullptr)
            continue;

        Character* enemy = this->closeToleader(other);
        if (enemy == nullptr)
            continue;

        if (temp_c->hasboolets() && temp_c->isAlive() && enemy->isAlive()) {
            temp_c->shoot(enemy);
        } else if (temp_c->isAlive()) {
            temp_c->reload();
        }
    }
}

//this function handles the attack actions performed by the ninjas in the team
void Team::attackNinjas(Team* other) {
    for (Character* fighter : _fighters) {
        if (fighter->getType() != "N")
            continue;

        Ninja* temp_n = dynamic_cast<Ninja*>(fighter);
        if (temp_n == nullptr)
            continue;

        Character* enemy = this->closeToleader(other);
        if (enemy == nullptr)
            continue;

        if (temp_n->getLocation().distance(enemy->getLocation()) <= 1 && enemy->isAlive() && temp_n->isAlive()) {
            temp_n->slash(enemy);
        } else if (temp_n->isAlive()) {
            temp_n->move(enemy);
        }
    }
}

 void Team::attack(Team* other) {
    if (other == nullptr)
        throw std::invalid_argument("cannot attack null");

    if (other->stillAlive() == 0)
        throw std::runtime_error("cannot attack a dead team");

    updateLeader();
    attackCowboys(other);
    attackNinjas(other);
}


Character* Team::closeToleader(Team* other) {
    double temp_dis = std::numeric_limits<double>::max();
    Character* temp = nullptr;

    for (Character* fighter : other->_fighters) {
        double dis = this->_leader->getLocation().distance(fighter->getLocation());
        if (dis < temp_dis && fighter->isAlive())
            temp_dis = dis, temp = fighter;
    }

    return temp;
}



int Team::stillAlive() const {
   int count = 0;
   for (Character* fighter : _fighters)
    {
        if(fighter->isAlive()){
            count++;
        }
    }
    return count;
}


void Team::print() const {
    for (Character* fighter : _fighters)
     {
         fighter->print();
    }
    
}

Team::~Team() {
    for (Character* fighter : _fighters) {
        delete fighter;
    }
}
}