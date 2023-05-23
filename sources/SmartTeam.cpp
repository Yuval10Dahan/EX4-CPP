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
            // find the warrior with the highest number of live points (in order not to
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
    // holds the pointer to chosen victim
    Character *currentVictim = nullptr;

    // in case the rival team has living warriors
    if(rivals->stillAlive() > 0)
    {
        // both teams
        Team *attackTeam = this;
        Team *rivalTeam = rivals;

        // case 1:
        if( (isThereCowboys(attackTeam)) && (isThereCowboys(rivalTeam)) )
        {
            Cowboy *fCowboy = furthestCowboy(rivalTeam);

            currentVictim = fCowboy;
        }

        // case 2:
        else if( (isThereCowboys(attackTeam)) && (isThereCowboys(rivalTeam) == false) )
        {
            Character *enemyLowestPoints = enemyWithLessLivePoints(rivalTeam);

            currentVictim = enemyLowestPoints;
        }

        // case 3:
        else if( (isThereCowboys(attackTeam) == false) && (isThereCowboys(rivalTeam)) )
        {
            Cowboy *nCowboy = nearestCowboy(rivalTeam);

            currentVictim = nCowboy;
        }

        // case 4:
        else
        {
            currentVictim = regularFindVictim(rivalTeam);
        }
    }

    return currentVictim;
}

// this method cause the team to attack a specific victim
void SmartTeam::attackVictim(Character *victim, Team *rivals)
{
    
}


void SmartTeam::print() 
{

}

Character* SmartTeam::enemyWithLessLivePoints(Team *rivals)
{
    // min int
    int maxLivePoints = std::numeric_limits<int>::min();

    // holds the enemy with less live points
    Character *minLivePointsEnemy;


    for(Character *enemy : rivals->getWarriors())
    {
        // find the living enemy with the minimum live points from the rivals
        if( (enemy->isAlive()) && (enemy->getLivePoints() > maxLivePoints) )
        {
            minLivePointsEnemy = enemy;
            maxLivePoints = enemy->getLivePoints();
        }
    }

    return minLivePointsEnemy;
}

Cowboy* SmartTeam::furthestCowboy(Team *rivals)
{
    // min double
    double maxDistance = std::numeric_limits<double>::min();

    // holds the furthest Cowboy in the rival team from
    // the furthest ninja in the attacking team
    Cowboy *chosenCowboy;

    // number of warriors in the rival team
    int rivalTeamSize = rivals->getWarriors().size();

    // number of warriors in the attacking team
    int attackingTeamSize = this->getWarriors().size();

    // rival team's vector
    const std::vector<Character*>& rivalWarriors = rivals->getWarriors();

    // attacking team's vector
    const std::vector<Character*>& attackingWarriors = this->getWarriors();


    // go through only the Cowboys in the rival team 
    // and through the ninjas in the attacking team
    for (size_t i = 0; i < rivalTeamSize; i++)
    {
        for (size_t j = 0; j < attackingTeamSize; j++)
        {
            Character *currentCowboy = rivalWarriors.at(i);
            Character *currentNinja = attackingWarriors.at(j);

            // in case the cowboy in the rival team and the ninja in the attacking team are alive,
            // and their distance from each other is bigger than maxDistance
            if( (currentCowboy->isAlive()) && (currentNinja->isAlive()) && (currentCowboy->getCharacterType() == 'C')
             && (currentNinja->getCharacterType() == 'N') && (currentCowboy->distance(currentNinja) > maxDistance) )
            {
                // find the furthest cowboy
                chosenCowboy = dynamic_cast<Cowboy*>(currentCowboy);
                maxDistance = currentCowboy->distance(currentNinja);
            }
        }
    }
    
    return chosenCowboy;
}

bool SmartTeam::isThereCowboys(Team *team)
{
    int atLeastOne = 0;
    bool thereIs = false;

    // check if there is Cowboys in the team
    for(Character *warrior : team->getWarriors())
    {
        if(warrior->getCharacterType() == 'C')
        {
            atLeastOne++;
        }
    }

    if(atLeastOne > 0)
    {
        thereIs = true;
    }    

    return thereIs;
}

Cowboy* SmartTeam::nearestCowboy(Team *rivals)
{
    // max double
    double minDistance = std::numeric_limits<double>::max();

    // holds the nearest Cowboy in the rival team from
    // the furthest ninja in the attacking team
    Cowboy *chosenCowboy;

    // number of warriors in the rival team
    int rivalTeamSize = rivals->getWarriors().size();

    // number of warriors in the attacking team
    int attackingTeamSize = this->getWarriors().size();

    // rival team's vector
    const std::vector<Character*>& rivalWarriors = rivals->getWarriors();

    // attacking team's vector
    const std::vector<Character*>& attackingWarriors = this->getWarriors();


    // go through only the Cowboys in the rival team 
    // and through the ninjas in the attacking team
    for (size_t i = 0; i < rivalTeamSize; i++)
    {
        for (size_t j = 0; j < attackingTeamSize; j++)
        {
            Character *currentCowboy = rivalWarriors.at(i);
            Character *currentNinja = attackingWarriors.at(j);

            // in case the cowboy in the rival team and the ninja in the attacking team are alive,
            // and their distance from each other is smaller than minDistance
            if( (currentCowboy->isAlive()) && (currentNinja->isAlive()) && (currentCowboy->getCharacterType() == 'C')
             && (currentNinja->getCharacterType() == 'N') && (currentCowboy->distance(currentNinja) < minDistance) )
            {
                // find the furthest cowboy
                chosenCowboy = dynamic_cast<Cowboy*>(currentCowboy);
                minDistance = currentCowboy->distance(currentNinja);
            }
        }
    }
    
    return chosenCowboy;
}

Character* SmartTeam::regularFindVictim(Team *rivals)
{
    // in case the rival team has living warriors
    if(rivals->stillAlive() > 0)
    {
        // max double
        double minDistanceFromLeader = std::numeric_limits<double>::max();

        // holds the pointer to chosen victim
        Character *currentVictim;

        // go through all the Warriors
        for(Character *warrior : rivals->getWarriors())
        {
            // find the closest living warrior from the rival team to
            // the attacking leader and set him as the current victim
            if( (warrior->isAlive()) && (warrior->distance(this->getLeader()) < minDistanceFromLeader) )
            {
                currentVictim = warrior;
                minDistanceFromLeader = warrior->distance(this->getLeader());
            }    
        }

        return currentVictim;
    }

    else
    {
        // indicates that the rival team warriors are all dead
        return nullptr;
    }
}