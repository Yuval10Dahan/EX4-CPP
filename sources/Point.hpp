#pragma once
#include <iostream>


namespace ariel{}



class Point
{
    private:
        double xCoordinate_;
        double yCoordinate_;


    public:

        // constructor
        Point(double xCoordinate, double yCoordinate);
        Point();

        // getters
        double getX() const;
        double gety() const;

        // setters
        void setX(double xCoordinate);
        void setY(double yCoordinate);

        // other methods                           
        double distance(const Point &point) const;
        void print() const;
        Point moveTowards(Point &sourceP, Point &destP, double distance);
        std::string printStr();

        // operator "=="
        bool operator==(const Point &other) const;
};