#include <iostream>
#include "Ninja.hpp"




using namespace std;

#define METER 1
#define N_HIT 40


// constructor
Ninja::Ninja(std::string name, const Point &location) : Character(name, location) 
{
    setCharacterType('N');
}


// ### public getters ###

// public getter for the "name" data member
string Ninja::getPName() const
{
    return this->getName();
}

// public getter for the "location" data member
Point Ninja::getPLocation() const
{
    return this->getLocation();
}

// public getter for the "livePoints" data member
int Ninja::getPLivePoints() const
{
    return this->getLivePoints();
}

// public getter for the "speed" data member
int Ninja::getPSpeed() const 
{
    return this->getSpeed();
}

// ### protected getters ###

// protected getter method for the "speed" data member
int Ninja::getSpeed() const 
{
    return this->speed_;
}

// ### setters ###

// setter method for the "speed" data member
void Ninja::setSpeed(int speed)
{
    this->speed_ = speed;
}

void Ninja::move(Character *enemy)
{
    // use moveTowards(point)
}

// this method slash the enemy
void Ninja::slash(Character *enemy)
{
    // if the Ninja is alive and the distance to the enemy is less than 1 meter - slash the enemy
    if( this->isAlive() && (this->distance(enemy) < METER) )
    {
        // reduce 40 livePoints from the enemy
        enemy->hit(N_HIT);
    }
}