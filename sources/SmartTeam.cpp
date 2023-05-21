#include <iostream>
#include "Team.hpp"
#include "Team2.hpp"
#include "SmartTeam.hpp"


using namespace std;


SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

SmartTeam::~SmartTeam()
{

}

void SmartTeam::replaceLeader() 
{

}

Character* SmartTeam::findVictim(Team *rivals)
{
    return this->getPLeader();
}

void SmartTeam::attackVictim(Character *victim, Team *rivals)
{

}

void SmartTeam::print() const
{

}