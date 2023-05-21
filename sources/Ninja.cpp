#include <iostream>
#include "Ninja.hpp"




using namespace std;

#define N_HIT 40
#define METER 1

// constructor
Ninja::Ninja(string name, const Point &location) : Character(name, location) 
{
    setCharacterType('N');
}

 

// --------------------------
// ### getters ###
// --------------------------

// getter method for the "speed" data member
int Ninja::getSpeed() const 
{
    return this->speed_;
}

// --------------------------
// ### setters ###
// --------------------------

// setter method for the "speed" data member
void Ninja::setSpeed(int speed)
{
    this->speed_ = speed;
}



// this method advances the ninja a distance equal to its speed
void Ninja::move(const Character *enemy)
{
    // if the distance to the enemy is bigger than the ninja speed - advance
    if( (enemy != nullptr) && (this->distance(enemy) >= this->getSpeed()) && (this->isAlive()) )
    {
        // the most advanced point to the enemy
        Point moveTo = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->getSpeed());

        // the ninja advance to the enemy
        this->advance(moveTo);
    }

    else 
    {
        throw runtime_error("This ninja can't move\n");
    }
}

// this method slash the enemy
void Ninja::slash(Character *enemy)
{
    // in case the enemy is the attacking ninja itself
    if(this == enemy)
    {
        throw runtime_error("The Ninja can't slash himself\n");
    }

    // if the ninja is less than meter away from enemy - the
    // ninja attacking the enemy, otherwise the ninja doe's nothing
    if(this->distance(enemy) < METER)
    {
        // reduce 40 livePoints from the enemy
        enemy->hit(N_HIT);
    }
}