#include <iostream>
#include <limits>
#include "Team.hpp"



using namespace std;

#define TEAM_MAX_SIZE 10
#define METER 1

// constructor
Team::Team(Character *leader) : leader_(leader) 
{
    // in case leader is nullptr
    if(leader == nullptr) throw invalid_argument("Team can't get nullptr as parameter\n");

    // add the leader to the team
    this->add(leader);
}

// distructor
Team::~Team()
{
    // delete each character object from the vector
    for(Character *warrior : warriors_)
    {
        delete warrior;
    }
}


// -----------------
// ### getters ###
// -----------------

// getter method for the "warriors" data member
const std::vector<Character*>& Team::getWarriors() const
{
    return this->warriors_;
}

// getter method for the "leader" data member
Character* Team::getLeader()
{
    return this->leader_;
}


// --------------------------
// ### setters ###
// --------------------------

// setter method for the "leader" data member
void Team::setLeader(Character* leader)
{
    this->leader_ = leader;
}

// this method add a warrior to the team        
void Team::add(Character *warrior)
{
    // if the team is fully occupied - throw an exception
    if(this->warriors_.size() >= TEAM_MAX_SIZE)
    {
        throw runtime_error("The team is full\n");
    }

    // if the warrior belong to a different team - throw an exception
    if(warrior->getIsInAGroup() == true)
    {
        throw runtime_error("This warrior is allready in another team\n");
    }

    // add the warrior to the team
    this->warriors_.push_back(warrior);

    // notify that the warrior is belong to the team
    warrior->setIsInAGroup(true);
}

// this method attack the rivals
void Team::attack(Team *rivals)
{
    // invalid rivals 
    if(rivals == nullptr) throw invalid_argument("The rival team is nullptr\n");
    
    // if the team leader is dead - replace him
    replaceLeader();

    // the current victim to attack
    Character *victim = findVictim(rivals);

    // attack the current victim
    attackVictim(victim, rivals);
}

// this method returns the number of team warriors that is still alive
int Team::stillAlive() 
{
    int livingWarriors = 0;
 
    // if a warrior in the team is alive raise the counter by 1
    for(Character *warrior : warriors_)
    {
        if(warrior->isAlive())
        {
            livingWarriors++;
        }
    }

    return livingWarriors;
}

// this method prints the warriors details
// first the cowboys, after that the ninjas
void Team::print() 
{
    // first go through all the Cowboys
    for(Character *cowboy : warriors_)
    {
        if(cowboy->getCharacterType() == 'C')
        {
            cout << cowboy->print();
        }    
    }

    // now go through all the Ninjas
    for(Character *ninja : warriors_)
    {
        if(ninja->getCharacterType() == 'N')
        {
            cout << ninja->print();
        }    
    }
}

// this method replace the team leader in case he is dead
void Team::replaceLeader() 
{
    // in case the team leader is dead and the team has living warriors
    if( (this->leader_->isAlive() == false) && (this->stillAlive() > 0) )
    {
        // max double
        double minDistanceFromLeader = std::numeric_limits<double>::max();

        // holds the pointer to the dead leader
        Character *deadLeader = this->leader_;

        // first go through all the Cowboys
        for(Character *cowboy : warriors_)
        {
            // cowboy is indeed of type cowboy and he isn't the dead leader
            if(cowboy->getCharacterType() == 'C')
            {
                // find the closest living warrior to the dead leader, and set him as the team leader
                if( (cowboy->isAlive()) && (cowboy->distance(deadLeader) < minDistanceFromLeader) )
                {
                    this->leader_ = cowboy;
                    minDistanceFromLeader = cowboy->distance(deadLeader);
                }
            }    
        }

        // now go through all the Ninjas
        for(Character *ninja : warriors_)
        {
            if(ninja->getCharacterType() == 'N')
            {
                // find the closest living warrior to the dead leader, and set him as the team leader
                if( (ninja->isAlive()) && (ninja->distance(deadLeader) < minDistanceFromLeader) )
                {
                    this->leader_ = ninja;
                    minDistanceFromLeader = ninja->distance(deadLeader);
                }
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

        // first go through all the Cowboys
        for(Character *cowboy : rivals->getWarriors())
        {
            if(cowboy->getCharacterType() == 'C')
            {
                // find the closest living warrior from the rival team to
                // the attacking leader and set him as the current victim
                if( (cowboy->isAlive()) && (cowboy->distance(this->leader_) < minDistanceFromLeader) )
                {
                    currentVictim = cowboy;
                    minDistanceFromLeader = cowboy->distance(this->leader_);
                }
            }    
        }

        // now go through all the Ninjas
        for(Character *ninja : rivals->getWarriors())
        {
            if(ninja->getCharacterType() == 'N')
            {
                // find the closest living warrior from the rival team to
                // the attacking leader and set him as the current victim
                if( (ninja->isAlive()) && (ninja->distance(this->leader_) < minDistanceFromLeader) )
                {
                    currentVictim = ninja;
                    minDistanceFromLeader = ninja->distance(this->leader_);
                }
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
        // holds the current victim to attack
        Character *currentVictim = victim;

        // first go through all the Cowboys
        for(Character *cowboy : warriors_)
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
        for(Character *ninja : warriors_)
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

// this method cause a cowboy to attack
void Team::cowboyAttack(Cowboy *cowboy, Character *victim)
{
    // if the cowboy has bullets left - he is shooting the victim
    if(cowboy->hasboolets())
    {
        cowboy->shoot(victim);
    }

    // if the cowboy has no bullets left - he is reloading his weapon
    else
    {
        cowboy->reload();
    }
}

// this method cause a ninja to attack 
void Team::ninjaAttack(Ninja *ninja, Character *victim)
{
    // if the ninja is less than a meter away
    // from victim - the ninja slash the victim
    if(ninja->distance(victim) < METER)
    {
        ninja->slash(victim);
    }

    // otherwise - the ninja move towards the victim
    else
    {
        ninja->move(victim);
    }
}