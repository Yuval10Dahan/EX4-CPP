#include <iostream>
#include "Character.hpp"




using namespace std;



// constructor
Character::Character(const std::string &name, const Point &location) : name_(name), location_(location) {}


// ### getters ###

// getter method for the "name" data member
string Character::getName() const
{
    return this->name_;
}

// getter method for the "location" data member
Point Character::getLocation() const
{
    return this->location_;
}

// getter method for the "livePoints" data member
int Character::getLivePoints() const
{
    return this->livePoints_;
}

// ### setters ###

// setter method for the "livePoints" data member
void Character::setLivePoints(int points)
{
    this->livePoints_ = points;
}
 


// // distructor
// Character::~Character()
// {
// }

// this method return if the current character is still alive
bool Character::isAlive() const
{
    return (this->livePoints_ > 0);
}

// this method calculate the distnace between the 2 characters
double Character::distance(Character *other) const
{
    // distance between the points of the characters
    double distance = this->location_.distance(other->getLocation());

    return distance;
}

// this method reduce the livePoints of the Character object
void Character::hit(int number)
{
    // reduce of the livePoints is valid
    if(this->livePoints_ >= number)
    {
        this->livePoints_ -= number;
    }

    // reduce is invalid --> reset the livePoints
    else
    {
        this->livePoints_ = 0;
    }
}