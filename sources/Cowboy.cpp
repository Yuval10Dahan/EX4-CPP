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

int Cowboy::getBulletAmount() const 
{
    return 0;
}


int Cowboy::getLivePoints() const 
{
    return 0;
}

string Cowboy::print() const
{
    return "";
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