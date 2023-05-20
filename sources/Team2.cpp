#include <iostream>
#include <limits>
#include "Team.hpp"
#include "Team2.hpp"


using namespace std;


Team2::Team2(Character *leader) : Team(leader) {}

Team2::~Team2()
{

}


// this method replace the team leader in case he is dead
void Team2::replaceLeader()
{
    // in case the team leader is dead and the team has living warriors
    if( (this->getPLeader()->isAlive() == false) && (this->stillAlive() > 0) )
    {
        // max double
        double minDistanceFromLeader = std::numeric_limits<double>::max();

        // holds the pointer to the dead leader
        Character *deadLeader = this->getPLeader();

        // go through all the Warriors
        for(Character *warrior : this->getPWarriors())
        {
            // find the closest living warrior to the dead leader, and set him as the team leader
            if( (warrior->isAlive()) && (warrior->distance(deadLeader) < minDistanceFromLeader) )
            {
                this->setLeader(warrior);
                minDistanceFromLeader = warrior->distance(deadLeader);
            }    
        }
    }
}

// this method finds a new victim on the rival team
Character* Team::findVictim(Team *rivals)
{
    // in case the rival team has living warriors
    if(rivals->stillAlive() > 0)
    {
        // max double
        double minDistanceFromLeader = std::numeric_limits<double>::max();

        // holds the pointer to chosen victim
        Character *currentVictim;

        // go through all the Warriors
        for(Character *warrior : this->getPWarriors())
        {
            // find the closest living warrior from the rival team to
            // the attacking leader and set him as the current victim
            if( (warrior->isAlive()) && (warrior->distance(this->getPLeader()) < minDistanceFromLeader) )
            {
                currentVictim = warrior;
                minDistanceFromLeader = warrior->distance(this->getPLeader());
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

// this method cause the team to attack a specific victim
void Team::attackVictim(Character *victim, Team *rivals)
{
    // in case there is a victim to attack and the attacking team has living warriors
    if( (victim != nullptr) && (rivals->stillAlive() > 0) && (this->stillAlive() > 0) )
    {
        Character *castingCharacter;

        // holds the current victim to attack
        Character *currentVictim = victim;

        // first go through all the Cowboys
        for(Character *warrior : this->getPWarriors())
        {
            // if character is alive continue
            if(warrior->isAlive())
            {
                // in case the warrior is of type Cowboy
                if(warrior->getPCharacterType() == 'C')
                {
                    // cast the Character into Cowboy
                    Cowboy *castingCowboy = dynamic_cast<Cowboy*>(warrior);

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

                // in case the warrior is of type Ninja
                if(warrior->getPCharacterType() == 'N')
                {
                    // cast the Character into Ninja
                    Ninja *castingNinja = dynamic_cast<Ninja*>(warrior);

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
        return;
    }
}

// this method prints the warriors details
// according to the order of adding the characters
void Team2::print() const
{
    for(Character *warrior : this->getPWarriors())
    {
        cout << warrior->print();
    }
}