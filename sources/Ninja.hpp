#pragma once
#include <iostream>
#include "Character.hpp"



namespace ariel{}


class Ninja : public Character
{
    private:
        int speed_;
        

    public:
    
        // getters
        int getSpeed() const;

        // setters
        void setSpeed(int speed);

        // constructor
        Ninja(std::string name, const Point &location);
        
        // other methods
        void move(const Character *enemy);
        void slash(Character *enemy);
};