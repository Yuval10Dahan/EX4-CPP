#include <iostream>
#include "Team.hpp"



using namespace std;


Team::Team(Character *leader) : leader_(leader) {}

Team::~Team()
{

}

const std::vector<fighter>& Team::getNinjas() const
{
    return this->ninjas_;
}

const std::vector<fighter>& Team::getCowboys() const
{
    return this->cowboys_;
}

Character* Team::getLeader() const
{
    return this->leader_;
}
        
void Team::add(Character *warrior)
{

}

void Team::attack(Team *rivals)
{

}

int Team::stillAlive() const
{
    return 0;
}

void Team::print() const
{

}