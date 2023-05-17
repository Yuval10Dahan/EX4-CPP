#include <iostream>
#include "Point.hpp"


using namespace std;

#define ZERO 0

// constructor
Point::Point(double xCoordinate, double yCoordinate) : xCoordinate_(xCoordinate), yCoordinate_(yCoordinate) {}

// default constructor
Point::Point() : xCoordinate_(ZERO), yCoordinate_(ZERO) {}


// ### getters ###

// getter method for the "x" data member
double Point::getX() const
{
    return this->xCoordinate_;
}

// getter method for the "y" data member
double Point::gety() const
{
    return this->yCoordinate_;
}

// ### setters ###

// setter method for the "x" data member
void Point::setX(double xCoordinate)
{
    this->xCoordinate_ = xCoordinate;
}

// setter method for the "y" data member
void Point::setY(double yCoordinate)
{
    this->yCoordinate_ = yCoordinate;
}

double Point::distance(Point &point) const
{
    return 1.0;
}

void Point::print() const
{

}

Point Point::moveTowards(Point &sourceP, Point &destP, double distance)
{
    return Point();
}