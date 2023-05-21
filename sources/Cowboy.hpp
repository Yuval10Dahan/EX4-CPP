#pragma once
#include <iostream>
#include "Character.hpp"


// class Ninja; // forward declaration

namespace ariel{}


class Cowboy : public Character
{
    private:
        int bulletAmount_;
        int livePoints_;
 


    public:

        // constructor
        Cowboy(std::string name, const Point &location);

        Cowboy(const Cowboy &other) = delete;  // Deleted copy constructor
        Cowboy& operator=(const Cowboy &other) = delete;  // Deleted copy assignment operator
        Cowboy(Cowboy &&other) = delete;  // Deleted move constructor
        Cowboy& operator=(Cowboy &&other) = delete;  // Deleted move assignment operator

        // distructor
        ~Cowboy() override;

        // getters
        int getBulletAmount() const;
        int getLivePoints() const;
        
        // other methods
        void shoot(Character *enemy);
        bool hasboolets() const;
        void reload();
};