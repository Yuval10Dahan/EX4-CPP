#pragma once
#include <iostream>
#include "Character.hpp"



// using namespace std;

class Cowboy; // forward declaration

namespace ariel{}


class Ninja : public Character
{
    private:
        int speed_;
        


    protected:
    
        // getters
        
        int getSpeed() const;

        // setters
        
        void setSpeed(int speed);

    public:

        // constructor
        Ninja(std::string name, const Point &location);

        Ninja(const Ninja& other) = delete;  // Deleted copy constructor
        Ninja& operator=(const Ninja& other) = delete;  // Deleted copy assignment operator
        Ninja(Ninja&& other) = delete;  // Deleted move constructor
        Ninja& operator=(Ninja&& other) = delete;  // Deleted move assignment operator

        // distructor - virtual
        ~Ninja() override {}

        // for the ninjas classes
        std::string getPName() const;
        Point getPLocation() const;
        int getPLivePoints() const;
        int getPSpeed() const;
        
        // override methods
        std::string print() const override;
        
        // other methods
        void move(Character *enemy);
        void slash(Character *enemy);
};