#pragma once
#include <iostream>
#include "Character.hpp"



namespace ariel{}


class Cowboy : public Character
{
    private:
        int bulletAmount_;


    public:

        // constructor
        Cowboy(std::string name, const Point &location);

        // getters
        int getBulletAmount() const;
        
        // other methods
        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
};