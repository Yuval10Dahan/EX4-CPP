#include <iostream>
#include "Ninja.hpp"




using namespace std;

#define N_HIT 40


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
void Ninja::move(Character *enemy)
{
    // if the distance to the enemy is bigger than the ninja speed - advance
    if( (enemy != nullptr) && (this->distance(enemy) >= this->getSpeed()) )
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
    // reduce 40 livePoints from the enemy
    enemy->hit(N_HIT);
}