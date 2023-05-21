#include <iostream>
#include "Cowboy.hpp"


 
using namespace std;

#define BULLET_AMOUNT 6
#define C_LIVES 110
#define C_HIT 10



// constructor
Cowboy::Cowboy(string name, const Point &location) : Character(name, location),
 bulletAmount_(BULLET_AMOUNT)
{
    setLivePoints(C_LIVES);
    setCharacterType('C');
}

// // distructor
// Cowboy::~Cowboy() 
// { 

// }
  
// ### getters ###

// getter method for the "bulletAmount" data member
int Cowboy::getBulletAmount() const 
{
    return this->bulletAmount_;
}

// this method shoot the enemy
void Cowboy::shoot(Character *enemy)
{   
    // in case the enemy is the attacking cowboy itself
    if(this == enemy)
    {
        throw runtime_error("The Cowboy can't shoot himself\n");
    }

    // if the attacking cowboy is dead - throw exception
    if(this->isAlive() == false)
    {
        throw runtime_error("The cowboy can't shoot when it is dead\n");
    }

    // cowboy has bullets
    if(this->hasboolets())
    {
        // enemy is alive - the cowboy shoot it
        if(enemy->isAlive() == true)
        {
            // reduce 10 livePoints from the enemy
            enemy->hit(C_HIT);

            // reduce cowboy bullet amount by 1
            this->bulletAmount_ --;  
        }

        // otherwise throw exception
        else
        {
           throw runtime_error("The enemy is allready dead\n"); 
        }
    }
}

// this method check if the cowboy has bullets left
bool Cowboy::hasboolets() const
{
    return (this->bulletAmount_ > 0);
}

// this function loads the cowboy's gun with six new bullets
void Cowboy::reload()
{
    // only if the cowboy is alive, load the gun
    if(this->isAlive())
    {
        this->bulletAmount_ = BULLET_AMOUNT;
    }

    // otherwise - throw exception
    else
    {
        throw runtime_error("Dead cowboy can't reload\n");
    }
}