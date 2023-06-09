#pragma once
#include <iostream>
#include <vector>
#include "Character.hpp"
#include "Cowboy.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"
#include "YoungNinja.hpp"
#include "TrainedNinja.hpp"


namespace ariel{}
 


class Team
{
    private:

        std::vector<Character*> warriors_;
        Character *leader_;

    public:

        // constructor
        Team(Character *leader);

        // getters
        const std::vector<Character*>& getWarriors() const;
        Character* getLeader();

        // setters
        void setLeader(Character* leader);

        Team(const Team &other);  // copy constructor
        Team& operator=(const Team &other);  // copy assignment operator
        Team(Team &&other) = delete;  // Deleted move constructor
        Team& operator=(Team &&other) = delete;  // Deleted move assignment operator
 
        // distructor - virtual
        virtual ~Team();
        
        // virtual methods
        virtual void replaceLeader();
        virtual Character* findVictim(Team *rivals);
        virtual void attackVictim(Character *victim, Team *rivals);
        virtual void print();
        
        // other methods
        void cowboyAttack(Cowboy *cowboy, Character *victim);
        void ninjaAttack(Ninja *ninja, Character *victim);
        void add(Character *warrior);
        void attack(Team *rivals); 
        int stillAlive();
};