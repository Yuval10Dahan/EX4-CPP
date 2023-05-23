#include <iostream>
#include <limits>
#include "Team.hpp"
#include "Team2.hpp"
#include "SmartTeam.hpp"


using namespace std;

// constructor
SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

// this method replace the team leader in case he is dead
void SmartTeam::replaceLeader() 
{
    // in case the team leader is dead and the team has living warriors
    if( (this->getLeader()->isAlive() == false) && (this->stillAlive() > 0) )
    {
        // min int
        int maxLivePoints = std::numeric_limits<int>::min();

        // go through all the Warriors
        for(Character *warrior : this->getWarriors())
        {
            // find the fighter with the highest number of live points (in order not to
            // undermine the team with a high frequency of leader changes), and set him as the team leader
            if( (warrior->isAlive()) && (warrior->getLivePoints() > maxLivePoints) )
            {
                this->setLeader(warrior);
                maxLivePoints = warrior->getLivePoints();
            }
        }
    }
}

// this method finds a new victim on the rival team
Character* SmartTeam::findVictim(Team *rivals)
{
    // // in case the rival team has living warriors
    // if(rivals->stillAlive() > 0)
    // {
    //     // holds the pointer to chosen victim
    //     Character *currentVictim;

    //     // min double
    //     double maxDistance = std::numeric_limits<double>::min();





    //     for()
    // }


    return this->getLeader();
}

// this method cause the team to attack a specific victim
void SmartTeam::attackVictim(Character *victim, Team *rivals)
{

}


void SmartTeam::print() 
{

}