#include <iostream>
#include <cmath>
#include <vector>
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
double Point::getY() const
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
    double y2 = point.getY();

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

// This method returns the closest point to the destination point, which is
// at most the given distance from the source point
Point Point::moveTowards(const Point &sourceP, const Point &destP, double distance)
{
    if(distance < 0) throw invalid_argument("Distance can't be negative\n");

    // differences between the points coordinates
    double diff1 = destP.getX() - sourceP.getX();
    double diff2 = destP.getY() - sourceP.getY();

    // distance between the points
    double currDistance = sourceP.distance(destP);

    // the given distance is bigger than the distance between the points - return the destination
    if (currDistance <= distance) 
    {
        return destP;
    }

    // the ratio between the steps to move to the actual distance between the points
    double ratio = distance / currDistance;
    
    // calculate the coordinates of the nearest possible point to advance
    double newX = sourceP.getX() + ratio * diff1;
    double newY = sourceP.getY() + ratio * diff2;

    // return the desired point
    return Point(newX, newY);
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
    double y2 = other.getY();

    // if the x and the y of both the points is equal return true
    return ( ( x1 == x2 ) && ( y1 == y2 ) );
}