#include <iostream>
#include "Team.hpp"
#include "Team2.hpp"
#include "SmartTeam.hpp"


using namespace std;

// constructor
SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

// this method replace the team leader in case he is dead
void SmartTeam::replaceLeader() 
{

}

// this method finds a new victim on the rival team
Character* SmartTeam::findVictim(Team *rivals)
{
    return this->getLeader();
}

// this method cause the team to attack a specific victim
void SmartTeam::attackVictim(Character *victim, Team *rivals)
{

}


void SmartTeam::print() 
{

}