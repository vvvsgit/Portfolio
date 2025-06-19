#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "headers/Point.hpp"

class Rectangle
{
public:
    Rectangle(const Point& a, const Point& b, const Point& c, const Point& d);
   
    void setCoordinates(const Point& a, const Point& b, const Point& c, const Point& d);

    double length();
    double width();
    double perimeter();
    double area();
    bool isSquare();

    double calculateDistance(const Point& one, const Point& two);

private:
    Point a_;
    Point b_;
    Point c_;
    Point d_;
};

#endif

