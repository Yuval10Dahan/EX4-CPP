#include <iostream>
#include "Cowboy.hpp"


 
using namespace std;

#define SIX 6
#define C_LIVES 110



// constructor
Cowboy::Cowboy(const string &name, const Point &location) : Character(name, location), bulletAmount_(SIX), livePoints_(C_LIVES) {}

// distructor
Cowboy::~Cowboy()
{

}

// ### getters ###

// getter method for the "bulletAmount" data member
int Cowboy::getBulletAmount() const 
{
    return this->bulletAmount_;
}

// getter method for the "livePoints" data member
int Cowboy::getLivePoints() const 
{
    return this->getLivePoints();
}

string Cowboy::print() const
{
    string cowboyPrint = "";
    string name = this->getName();
    int livePoints = this->getLivePoints();

    // if the cowboy is alive print all
    if(this->isAlive())
    {
        cowboyPrint = "Name: (C) " + name + "\n" + "Live points: " + to_string(livePoints) + "\n" +
        "Location: " + this->getLocation().printStr() + "\n";
    }

    // if the cobowy id dead, remove the "livePoints"
    else
    {
        cowboyPrint = "Name: (C) (" + name + ") " + "\n" + "Location: " + this->getLocation().printStr() + "\n";
    }
    
    return cowboyPrint;
}

void Cowboy::shoot(Character *enemy)
{
    
}

bool Cowboy::hasBullets() const
{
    return false;
}


void Cowboy::reload()
{

}