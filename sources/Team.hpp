#pragma once
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"
// #include "Team2.hpp"
// #include "SmartTeam.hpp"


// using namespace std;
 

namespace ariel{}


// typedef struct fighter
// {

// }fighter;

 


class Team
{
    private:

        std::vector<Character*> warriors_;
        Character *leader_;

    protected:

        const std::vector<Character*>& getWarriors() const;
        const std::vector<Point>& getPointsArray() const;
        Character* getLeader() const;

    public:

        // constructor
        Team(Character *leader);

        Team(const Team& other) = delete;  // Deleted copy constructor
        Team& operator=(const Team& other) = delete;  // Deleted copy assignment operator
        Team(Team&& other) = delete;  // Deleted move constructor
        Team& operator=(Team&& other) = delete;  // Deleted move assignment operator
 
        // distructor - virtual
        virtual ~Team();
        
        void add(Character *warrior);
        void attack(Team *rivals);
        int stillAlive() const;
        virtual void print() const;

        void removeWarrior(size_t index);

};