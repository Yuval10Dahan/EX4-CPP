#include <iostream>
#include "Ninja.hpp"




using namespace std;



// constructor
Ninja::Ninja(std::string name, const Point &location) : Character(name, location) {}


// public getters
string Ninja::getPName() const
{
    return this->getName();
}

Point Ninja::getPLocation() const
{
    return this->getLocation();
}

int Ninja::getPLivePoints() const
{
    return this->getLivePoints();
}

int Ninja::getPSpeed() const 
{
    return this->getSpeed();
}

// protected getters
int Ninja::getSpeed() const 
{
    return this->speed_;
}

void Ninja::setSpeed(int speed)
{
    this->speed_ = speed;
}

string Ninja::print() const
{
    return "";
}

void Ninja::move(Character *enemy)
{

}

void Ninja::slash(Character *enemy)
{

}