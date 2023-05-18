#include <iostream>
#include <cmath>
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

// this method calculates the distance between two points
double Point::distance(const Point &point) const
{
    double x1 = this->xCoordinate_;
    double x2 = point.getX();
    double y1 = this->yCoordinate_;
    double y2 = point.gety();

    // pow
    double diff1 = pow( (x1 - x2), 2 );
    double diff2 = pow( (y1 - y2), 2 );

    // sqrt
    double distance = sqrt(diff1 + diff2);

    return distance;
}

// this method prints the point object as (x,y)
void Point::print() const
{
    cout << "(" << this->xCoordinate_ << "," << this->yCoordinate_ << ")" << endl;
}

Point Point::moveTowards(Point &sourceP, Point &destP, double distance)
{
    return Point();
}

// this method print the point as a string
string Point::printStr()
{
    string print = "(" + to_string(this->xCoordinate_) + "," + to_string(this->yCoordinate_) + ")";

    return print;
}

// operator "=="
bool Point::operator==(const Point &other) const
{   
    double x1 = this->xCoordinate_;
    double x2 = other.getX();
    double y1 = this->yCoordinate_;
    double y2 = other.gety();

    // if the x and the y of both the points is equal return true
    return ( ( x1 == x2 ) && ( y1 == y2 ) );
}