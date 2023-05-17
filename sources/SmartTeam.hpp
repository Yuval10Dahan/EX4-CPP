#pragma once
#include <iostream>
#include "Team.hpp"

// using namespace std; 

namespace ariel{}


class SmartTeam : public Team
{
    public:
    
        // constructor
        SmartTeam(Character *leader);

        SmartTeam(const SmartTeam& other) = delete;  // Deleted copy constructor
        SmartTeam& operator=(const SmartTeam& other) = delete;  // Deleted copy assignment operator
        SmartTeam(SmartTeam&& other) = delete;  // Deleted move constructor
        SmartTeam& operator=(SmartTeam&& other) = delete;  // Deleted move assignment operator

        // distructor
        ~SmartTeam() override;

        void print() const override;
};   