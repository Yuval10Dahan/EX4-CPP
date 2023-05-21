#include <iostream>
#include "OldNinja.hpp"



using namespace std;

#define OLD_SPEED 8
#define OLD_LIVES 150


// constructor
OldNinja::OldNinja(string name, const Point &location) : Ninja(name, location) 
{
    setSpeed(OLD_SPEED);
    setLivePoints(OLD_LIVES);
}

// distructor
OldNinja::~OldNinja ()
{

}