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
 
// #define TEN 10

namespace ariel{}


typedef struct fighter
{

}fighter;




class Team
{
    private:

        std::vector<fighter> ninjas_;
        std::vector<fighter> cowboys_;
        Character *leader_;

    protected:

        const std::vector<fighter>& getNinjas() const;
        const std::vector<fighter>& getCowboys() const;
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

        void addCowboy(Cowboy *cowboy);
        void addNinja(Ninja *ninja);
};