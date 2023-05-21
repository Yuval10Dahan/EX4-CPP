#pragma once
#include <iostream>
#include "Team.hpp"
#include "Character.hpp"



namespace ariel{}


class Team2 : public Team
{
    public:
    
        // constructor
        Team2(Character *leader);

        // override methods
        void replaceLeader() override;
        Character* findVictim(Team *rivals) override;
        void attackVictim(Character *victim, Team *rivals) override;
        void print() override;
};   