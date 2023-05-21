#include <iostream>
#include "Character.hpp"




using namespace std;



// constructor
Character::Character(string name, const Point &location) : name_(name), location_(location),
isInAGroup_(false) {}

// copy constructor
Character::Character(const Character &other)
{
    // copy the data members
    this->name_ = other.getName();
    this->location_ = other.getLocation();
    this->isInAGroup_ = other.getIsInAGroup();
}

// copy assignment operator
Character& Character::operator=(const Character &other)
{
    // in case that other is actually this
    if (this == &other) 
    {
        return *this;
    }

    // copy the data members otherwise
    this->name_ = other.getName();
    this->location_ = other.getLocation();
    this->isInAGroup_ = other.getIsInAGroup();

    // return the object after the changes
    return *this;
}



// --------------------------
// ### getters ###
// --------------------------

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

// getter method for the "IsInAGroup" data member
bool Character::getIsInAGroup() const
{
    return this->isInAGroup_;
}



// --------------------------
// ### setters ###
// --------------------------

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
 



// this method return if the current character is still alive
bool Character::isAlive() const
{
    return (this->livePoints_ > 0);
}

// this method calculate the distnace between the 2 characters
double Character::distance(const Character *other) const
{
    // distance between the points of the characters
    double distance = this->location_.distance(other->getLocation());

    return distance;
}

// this method reduce the livePoints of the Character object
void Character::hit(int number)
{
    if(number < 0)
    {
        throw invalid_argument("The hit number can't be negative number\n");
    }
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
std::string Character::print()
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

// this method advance the character to the given location
void Character::advance(Point &next)
{
    this->location_ = next;
}