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

        Team2(const Team2 &other) = delete;  // Deleted copy constructor
        Team2& operator=(const Team2 &other) = delete;  // Deleted copy assignment operator
        Team2(Team2 &&other) = delete;  // Deleted move constructor
        Team2& operator=(Team2 &&other) = delete;  // Deleted move assignment operator

        // distructor
        ~Team2() override;

        // override methods
        void replaceLeader() override;
        Character* findVictim(Team *rivals) override;
        void attackVictim(Character *victim, Team *rivals) override;
        void print() const override;
};   