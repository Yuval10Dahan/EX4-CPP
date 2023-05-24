#pragma once
#include <iostream>
#include "Point.hpp"

namespace ariel{}
 
 
// abstract class
class Character
{
    private:
        std::string name_;
        Point location_;
        int livePoints_;
        char characterType_;
        bool isInAGroup_;


    public:

        // getters
        std::string getName() const;
        Point getLocation() const;
        int getLivePoints() const;
        char getCharacterType() const;
        bool getIsInAGroup() const;

        // setters
        void setLivePoints(int points);
        void setCharacterType(char type);
        void setIsInAGroup(bool isIn);

        // constructor
        Character(std::string name, const Point &location);

        Character(const Character &other);  // copy constructor
        Character& operator=(const Character &other);  // copy assignment operator
        Character(Character &&other) = delete;  // Deleted move constructor
        Character& operator=(Character &&other) = delete;  // Deleted move assignment operator

        // distructor - virtual
        virtual ~Character() = default;

        // other methods
        bool isAlive() const;
        double distance(const Character *other) const;
        void hit(int number);
        std::string print();
        void advance(Point &next);
};