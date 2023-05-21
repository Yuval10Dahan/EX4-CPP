#pragma once
#include <iostream>
#include <vector>

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
        double getY() const;

        // setters
        void setX(double xCoordinate);
        void setY(double yCoordinate);

        // other methods                           
        double distance(const Point &point) const;
        void print();
        static Point moveTowards(const Point &sourceP, const Point &destP, double distance);
        std::string printStr();

        // operator "=="
        bool operator==(const Point &other) const;
};