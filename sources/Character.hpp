#ifndef CHARACTER_HPP
#define CHARACTER_HPP
#include "Point.hpp"
#include <string>
using namespace std;

namespace ariel
{
  class Team;
  class Character
  {

  public:
    bool appointed = false;
    Character(const std::string &name, const Point &location, int hitPoints);
    virtual ~Character();
    int getHitPoints() const;
    void setHitPoints(int hitPoints);
    bool isAlive() const;                          //
    double distance(const Character *other) const; //
    void hit(int amount);                          //
    std::string getName() const;
    Point getLocation() const; //
    void print() const;        //
    void fighterchange(bool x);
    bool teamFighter() const;

  protected:
    std::string name;
    int hitPoints;
    Point location;
    // int team_;
    bool teamfighter_;
    string type_;
    //  Team* team_; // Pointer to the team the character belongs to
  };
}
#endif // CHARACTER_HPP