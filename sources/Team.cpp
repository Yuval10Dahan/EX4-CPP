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

    if(leader->isAlive() == false)
    {
        throw runtime_error("The given leader is dead\n");
    }

    if(leader->getIsInAGroup() == true)
    {
        throw runtime_error("The given leader is allready in a team\n");
    }

    // add the leader to the team
    this->add(leader);
}

// distructor
Team::~Team()
{
    // delete each warrior object in the vector
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
    // if the given parameter in nullptr - throw an exception
    if(warrior == nullptr)
    {
        throw runtime_error("The given warrior is null\n");
    }

    // in case warrior is dead
    if(warrior->isAlive() == false)
    {
        throw runtime_error("The warrior is allready dead and can't join a team\n");
    }

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
    if (rivals == NULL){
        throw invalid_argument("enemy team are null\n");
    }

    if (this == rivals){
        throw invalid_argument("team can not attack himself\n");
    }
    if (rivals->stillAlive()<=0){
        throw runtime_error("can not attack a dead team \n");
    }
    if (!this->leader_->isAlive()){
        replaceLeader();
    }

    Character* enemytoattack = findVictim(rivals);
    for (unsigned int i = 0; i < warriors_.size(); ++i) { // go over all the cowboy
        auto &character = *warriors_.at(i);
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (!enemytoattack->isAlive()){
            enemytoattack= findVictim(rivals);
        }
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (character.getCharacterType() == 'C'){
            Cowboy* cowboyattacker = dynamic_cast <Cowboy*> (&character); // convert character to cowboy
            if (cowboyattacker->isAlive()) {
                if (cowboyattacker->hasboolets()) {
                    cowboyattacker->shoot(enemytoattack);
                } else {
                    cowboyattacker->reload();
                }
            }
        }
    }

    for (unsigned int i = 0; i < warriors_.size(); ++i) { // go over all the ninja
        auto &character = *warriors_.at(i);
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (!enemytoattack->isAlive()){
            enemytoattack= findVictim(rivals);
        }
        if (enemytoattack==NULL){ // this team win
            break;
        }
        if (character.getCharacterType() == 'N'){ // convert character to ninja
            Ninja* ninjaattacker = dynamic_cast <Ninja*> (&character);
            if (ninjaattacker->isAlive()) {
                if (ninjaattacker->getLocation().distance(enemytoattack->getLocation()) <= 1) {
                    ninjaattacker->slash(enemytoattack);
                } else {
                    ninjaattacker->move(enemytoattack);
                }
            }
        }
    }
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
    Character *newcaptain = this->leader_;
    double mindistance=99999;

    for (size_t i = 0; i < warriors_.size(); ++i) { // go over all this team warriors
        Character *Character = warriors_.at(i);
        double distance = this->leader_->getLocation().distance(Character->getLocation());
        if (distance<mindistance && Character->isAlive()){ //check the distance
            mindistance=distance;
            newcaptain=Character;
        }
    }
    this->leader_=newcaptain;
}

// this method finds a new victim on the rival team
Character* Team::findVictim(Team *rivals)
{
    Character *enemy = NULL;
    double mindistance=99999;
    for (unsigned int i = 0; i < rivals->getWarriors().size(); ++i) { // go over all enemy team warriors
        Character *Character = rivals->getWarriors().at(i);
        double distance = this->leader_->getLocation().distance(Character->getLocation());
        if (distance<mindistance && Character->isAlive()){  //check the distance
            mindistance=distance;
            enemy=Character;
        }
    }
    return enemy;
}

// // this method cause the team to attack a specific victim
// void Team::attackVictim(Character *victim, Team *rivals)
// {
    
// }

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
}                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                              // victim is allready dead
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