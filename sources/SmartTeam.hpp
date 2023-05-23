#pragma once
#include <iostream>
#include "Team.hpp"
#include "Character.hpp"



namespace ariel{}


class SmartTeam : public Team
{
    public:
    
        // constructor
        SmartTeam(Character *leader);

        // override methods
        void replaceLeader() override;
        Character* findVictim(Team *rivals) override;
        void attackVictim(Character *victim, Team *rivals) override;
        void print() override;

        // other methods
        Character* enemyWithLessLivePoints(Team *rivals);
        Cowboy* furthestCowboy(Team *rivals);
        bool isThereCowboys(Team *team);
        Cowboy* nearestCowboy(Team *rivals);
        Character* regularFindVictim(Team *rivals);
};    