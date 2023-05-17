#pragma once
#include <iostream>
#include "Point.hpp"


// using namespace std;

namespace ariel{}
 
 
// abstract class
class Character
{
    private:
        std::string name_;
        Point location_;
        int livePoints_;


    protected:
        // getters
        std::string getName() const;
        Point getLocation() const;
        int getLivePoints() const;

        // setters
        void setLivePoints(int points);

    public:

        // constructor
        Character(const std::string &name, const Point &location);

        Character(const Character& other) = delete;  // Deleted copy constructor
        Character& operator=(const Character& other) = delete;  // Deleted copy assignment operator
        Character(Character&& other) = delete;  // Deleted move constructor
        Character& operator=(Character&& other) = delete;  // Deleted move assignment operator

        // distructor - virtual
        virtual ~Character() = default;

        // other methods - pure virtuals
        virtual bool isAlive() const;
        virtual double distance(Character *other) const;
        virtual void hit(int number);
        virtual std::string print() const = 0;
};