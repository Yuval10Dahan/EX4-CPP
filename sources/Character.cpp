#include <iostream>
#include "Character.hpp"




using namespace std;



// constructor
Character::Character(const std::string &name, const Point &location) : name_(name), location_(location) {}


// ### protected getters ###

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

// getter method for the "characterType" data member
char Character::getCharacterType() const
{
    return this->characterType_;
}


// ### public getters ###

// public getter method for the "IsInAGroup" data member
bool Character::getIsInAGroup() const
{
    return this->isInAGroup_;
}

// public getter method for the "location" data member
Point Character::getPLocation() const
{
    return this->getLocation();
}


// ### setters ###

// setter method for the "livePoints" data member
void Character::setLivePoints(int points)
{
    this->livePoints_ = points;
}

// setter method for the "characterType" data member
void Character::setCharacterType(char type)
{
    this->characterType_ = type;
}

// setter method for the "IsInAGroup" data member
void Character::setIsInAGroup(bool is)
{
    this->isInAGroup_ = is;
}

// public getter for the "IsInAGroup" data member
bool Character::getPIsInAGroup() const
{
    return this->getIsInAGroup();
}

// public setter for the "IsInAGroup" data member
void Character::setPIsInAGroup(bool is) 
{
    this->isInAGroup_ = is;
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

// this method print the Character attributes as a string
std::string Character::print() const
{
    string characterPrint = "";
    string name = this->getName();
    int livePoints = this->getLivePoints();
    char type = this->characterType_;

    // if the character is alive print all
    if(this->isAlive())
    {
        characterPrint = "Name: (" + to_string(type) + ") " + name + "\n" + "Live points: " + to_string(livePoints) + "\n" +
        "Location: " + this->getLocation().printStr() + "\n";
    }

    // if the character id dead, remove the "livePoints"
    else
    {
        characterPrint = "Name: (" + to_string(type) + ") " + "\n" + "Location: " + this->getLocation().printStr() + "\n";
    }
    
    return characterPrint;
}