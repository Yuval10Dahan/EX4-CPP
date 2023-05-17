#include <iostream>
#include "Character.hpp"




using namespace std;



// constructor
Character::Character(const std::string &name, const Point &location) : name_(name), location_(location) {}


// getters
string Character::getName() const
{
    return this->name_;
}

Point Character::getLocation() const
{
    return this->location_;
}

int Character::getLivePoints() const
{
    return this->livePoints_;
}

// setters
void Character::setLivePoints(int points)
{
    this->livePoints_ = points;
}
 


// // distructor
// Character::~Character()
// {

// }


bool Character::isAlive() const
{
    return false;
}

double Character::distance(Character *other) const
{
    return 0.0;
}

void Character::hit(int number)
{

}