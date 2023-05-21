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

        SmartTeam(const SmartTeam &other) = delete;  // Deleted copy constructor
        SmartTeam& operator=(const SmartTeam &other) = delete;  // Deleted copy assignment operator
        SmartTeam(SmartTeam &&other) = delete;  // Deleted move constructor
        SmartTeam& operator=(SmartTeam &&other) = delete;  // Deleted move assignment operator

        // distructor
        ~SmartTeam() override;

        // override methods
        void replaceLeader() override;
        Character* findVictim(Team *rivals) override;
        void attackVictim(Character *victim, Team *rivals) override;
        void print() const override;
};    