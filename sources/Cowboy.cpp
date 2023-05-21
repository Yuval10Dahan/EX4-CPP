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
    // shoot only if the cowboy has bullets
    if(this->hasboolets())
    {
        // reduce 10 livePoints from the enemy
        enemy->hit(C_HIT);

        // reduce cowboy bullet amount by 1
        this->bulletAmount_ --;  
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
}