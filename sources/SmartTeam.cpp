#include <iostream>
#include <limits>
#include "Team.hpp"
#include "Team2.hpp"
#include "SmartTeam.hpp"


using namespace std;

// constructor
SmartTeam::SmartTeam(Character *leader) : Team(leader) {}

// this method replace the team leader in case he is dead
// ### strategy: set as leader whoever has the most live points ###
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
// ### strategy:
// (1) We would prefer to eliminate cowboys first, because they shoot from anywhere without location restrictions.
// (2) If not, we will prefer to eliminate an enemy with the least number of points.
// (3) If not, we would prefer to find the closest cowboy to the attacking team in order to advance the ninjas as quickly as possible.
// (4) If not, find the closest living warrior from the rival team to the attacking leader and set him as the current victim.
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

        // ### case 1: if there are cowboys in both the rival team and the
        // attacking team, find the furthest cowboy in the rival team from
        // the furthest ninja in the attacking team.
        if( (isThereCowboys(attackTeam)) && (isThereCowboys(rivalTeam)) )
        {
            Cowboy *fCowboy = furthestCowboy(rivalTeam);

            currentVictim = fCowboy;
        }

        // case 2: if there are cowboys in the attacking team but not in the rival team,
        // we'll find the enemy with the least livePoints.
        else if( (isThereCowboys(attackTeam)) && (isThereCowboys(rivalTeam) == false) )
        {
            Character *enemyLowestPoints = enemyWithLessLivePoints(rivalTeam);

            currentVictim = enemyLowestPoints;
        }

        // case 3: if there are cowboys in the rival team but not in the attacking team,
        // we'll find the nearest cowboy in the rival team from the nearest ninja in the attacking team.
        else if( (isThereCowboys(attackTeam) == false) && (isThereCowboys(rivalTeam)) )
        {
            Cowboy *nCowboy = nearestCowboy(rivalTeam);

            currentVictim = nCowboy;
        }

        // case 4: we'll find the victim the same way as team2 implementation
        else
        {
            currentVictim = regularFindVictim(rivalTeam);
        }
    }

    return currentVictim;
}

// this method cause the team to attack a specific victim
// *** just like in Team *** 
void SmartTeam::attackVictim(Character *victim, Team *rivals)
{
    // in case there is a victim to attack and the attacking team has living warriors
    if( (victim != nullptr) && (rivals->stillAlive() > 0) && (this->stillAlive() > 0) )
    {
        // holds the current victim to attack
        Character *currentVictim = victim;

        // first go through all the Cowboys
        for(Character *cowboy : this->getWarriors())
        {
            if(cowboy->getCharacterType() == 'C')
            {
                // if character is alive continue
                if(cowboy->isAlive())
                {
                    // cast the Character into Cowboy
                    Cowboy *castingCowboy = dynamic_cast<Cowboy*>(cowboy);

                    // if victim is alive
                    if(currentVictim->isAlive())
                    {
                        cowboyAttack(castingCowboy, currentVictim);
                    }
                    
                    // victim is allready dead
                    else
                    {
                        currentVictim = findVictim(rivals);

                        if(currentVictim != nullptr)
                        {
                            cowboyAttack(castingCowboy, currentVictim);
                        }

                        else
                        {
                            return;
                        }
                    }
                }
                
            }
        }

        // now go through all the Ninjas
        for(Character *ninja : this->getWarriors())
        {
            if(ninja->getCharacterType() == 'N')
            {
                // if character is alive continue
                if(ninja->isAlive())
                {
                    // cast the Character into Ninja
                    Ninja *castingNinja = dynamic_cast<Ninja*>(ninja);

                    // if victim is alive
                    if(currentVictim->isAlive())
                    {
                        ninjaAttack(castingNinja, currentVictim);
                    }
                    
                    // victim is allready dead
                    else
                    {
                        currentVictim = findVictim(rivals);

                        if(currentVictim != nullptr)
                        {
                            ninjaAttack(castingNinja, currentVictim);
                        }

                        else
                        {
                            return;
                        }
                    }
                }
                
            }    
        }
    }

    // attacking is not possible
    else
    {
        throw runtime_error("Can't attack a dead team\n");
    }
}

// this method prints the warriors details
// print the leader first, then all the rest
void SmartTeam::print() 
{
    // first - print the leader
    for(Character *warrior : this->getWarriors())
    {
        if(warrior == this->getLeader())
        {
            cout << warrior->print();
        }
    }   
    
    // then - print all the rest
    for(Character *warrior : this->getWarriors())
    {
        if(warrior != this->getLeader())
        {
            cout << warrior->print();
        }
    }
}

// this method find the enemy from the rival team with the least livePoints
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

// this method find the furthest cowboy in the rival team
// from the furthest ninja from the attacking team
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

// this method check if there is cowboys in the team
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

// this method find the nearest cowboy in the rival team
// from the nearest ninja from the attacking team
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
                // find the nearest cowboy
                chosenCowboy = dynamic_cast<Cowboy*>(currentCowboy);
                minDistance = currentCowboy->distance(currentNinja);
            }
        }
    }
    
    return chosenCowboy;
}

// this method find a victim the same way Team2 does
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