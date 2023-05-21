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
        bool isInAGroup_ = false;


    public:
        // protected getters
        std::string getName() const;
        Point getLocation() const;
        int getLivePoints() const;
        char getCharacterType() const;
        bool getIsInAGroup() const;

        // protected setters
        void setLivePoints(int points);
        void setCharacterType(char type);
        void setIsInAGroup(bool is);

    public:

        // constructor
        Character(std::string name, const Point &location);

        // public getters
        bool getPIsInAGroup() const;
        Point getPLocation() const;
        char getPCharacterType() const;

        // public setters
        void setPIsInAGroup(bool is);

        Character(const Character &other) = delete;  // Deleted copy constructor
        Character& operator=(const Character &other) = delete;  // Deleted copy assignment operator
        Character(Character &&other) = delete;  // Deleted move constructor
        Character& operator=(Character &&other) = delete;  // Deleted move assignment operator

        // distructor - virtual
        virtual ~Character() = default;

        // other methods
        bool isAlive() const;
        double distance(Character *other) const;
        void hit(int number);
        std::string print() const;
        void advance(Point &next);
};