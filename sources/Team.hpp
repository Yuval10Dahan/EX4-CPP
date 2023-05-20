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
 


class Team
{
    private:

        std::vector<Character*> warriors_;
        Character *leader_;

    protected:

        // protected getters
        const std::vector<Character*>& getWarriors() const;
        Character* getLeader() const;

    public:

        // constructor
        Team(Character *leader);

        // public getters
        const std::vector<Character*>& getPWarriors() const;
        Character* getPLeader() const;

        // public setters
        void setLeader(Character* leader);

        Team(const Team& other) = delete;  // Deleted copy constructor
        Team& operator=(const Team& other) = delete;  // Deleted copy assignment operator
        Team(Team&& other) = delete;  // Deleted move constructor
        Team& operator=(Team&& other) = delete;  // Deleted move assignment operator
 
        // distructor - virtual
        virtual ~Team();
        
        // virtual methods
        virtual void replaceLeader();
        virtual Character* findVictim(Team *rivals);
        virtual void attackVictim(Character *victim, Team *rivals);
        void cowboyAttack(Cowboy *cowboy, Character *victim);
        void ninjaAttack(Ninja *ninja, Character *victim);

        // other methods
        void add(Character *warrior);
        void attack(Team *rivals); 
        int stillAlive() const;
        virtual void print() const;
        
};