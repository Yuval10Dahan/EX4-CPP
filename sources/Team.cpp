#include <iostream>
#include "Team.hpp"



using namespace std;

#define TEAM_MAX_SIZE 10


Team::Team(Character *leader) : leader_(leader) {}

Team::~Team()
{

}


// ### getters ###

// getter method for the "warriors" data member
const std::vector<Character*>& Team::getWarriors() const
{
    return this->warriors_;
}

// getter method for the "leader" data member
Character* Team::getLeader() const
{
    return this->leader_;
}

// this method add a warrior to the team        
void Team::add(Character *warrior)
{
    // if the team is fully occupied - throw an exception
    if(this->warriors_.size() > TEAM_MAX_SIZE)
    {
        throw runtime_error("The team is full\n");
    }

    // if the warrior belong to a different team - throw an exception
    if(warrior->getPIsInAGroup() == true)
    {
        throw runtime_error("This warrior is allready in another team\n");
    }

    // add the warrior to the team
    this->warriors_.push_back(warrior);

    // notify that the warrior is belong to the team
    warrior->setPIsInAGroup(true);
}

void Team::attack(Team *rivals)
{

}

// this method returns the number of team warriors that is still alive
int Team::stillAlive() const
{
    return this->warriors_.size();
}

void Team::print() const
{

}

void Team::removeWarrior(size_t index)
{
    
}