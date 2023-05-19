#include <iostream>
#include "YoungNinja.hpp"



using namespace std;

#define YOUNG_SPEED 14
#define YOUNG_LIVES 100

 
// constructor
YoungNinja::YoungNinja(const string &name, const Point &location) : Ninja(name, location) 
{
    setSpeed(YOUNG_SPEED);
    setLivePoints(YOUNG_SPEED);
}

// distructor
YoungNinja::~YoungNinja ()
{

}