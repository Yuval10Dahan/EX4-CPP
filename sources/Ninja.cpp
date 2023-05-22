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
    if( (enemy == nullptr) || (this->isAlive() == false) )
    {
        throw runtime_error("This ninja can't move\n");
    }

    else 
    {
        // the most advanced point to the enemy
        Point moveTo = Point::moveTowards(this->getLocation(), enemy->getLocation(), this->getSpeed());

        // the ninja advance to the enemy
        this->advance(moveTo);
    }
}

// this method slash the enemy
void Ninja::slash(Character *enemy)
{
    // enemy is null
    if(enemy == nullptr)
    {
        throw invalid_argument("The given enemy is nullptr\n");
    }

    // in case the enemy is the attacking ninja itself
    if(this == enemy)
    {
        throw runtime_error("The Ninja can't slash himself\n");
    }

    // if the attacking ninja is dead - throw exception
    if(this->isAlive() == false)
    {
        throw runtime_error("The Ninja can't slash when it is dead\n");
    }

    // the ninja is less than meter away from enemy
    if(this->distance(enemy) < METER)
    {
        // if the enemy is alive - the ninja attacking the enemy
        if(enemy->isAlive() == true)
        {
            // reduce 40 livePoints from the enemy
            enemy->hit(N_HIT);
        }
        
        // otherwise throw exception
        else
        {
            throw runtime_error("The enemy is allready dead\n");
        }
    }
}