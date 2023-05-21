#include <iostream>
#include "TrainedNinja.hpp"



using namespace std;

#define TRAINED_SPEED 12
#define TRAINED_LIVES 120


// constructor
TrainedNinja::TrainedNinja(string name, const Point &location) : Ninja(name, location) 
{
    setSpeed(TRAINED_SPEED);
    setLivePoints(TRAINED_LIVES);
}

// // distructor
// TrainedNinja::~TrainedNinja ()
// {

// }