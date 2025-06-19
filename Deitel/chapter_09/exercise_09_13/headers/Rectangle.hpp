#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "headers/Point.hpp"

class Rectangle
{
public:
    Rectangle(const Point& a, const Point& b, const Point& c, const Point& d, const char fillCharacter = ' ', const char perimeterCharacter = '*');
   
    void setCoordinates(const Point& a, const Point& b, const Point& c, const Point& d);

    double length();
    double width();
    double perimeter();
    double area();
    bool isSquare();

    void draw() const;

    char getFillCharacter() const;
    void setFillCharacter(const char fillCharacter);
    char getPerimeterCharacter() const;
    void setPerimeterCharacter(const char perimeterCharacter);

private:
    double calculateDistance(const Point& one, const Point& two);
    bool isOnPerimeter(const Point& point) const;
    bool isInside(const Point& point) const;
    Point pointsDifference(const Point& one, const Point& two) const;
    double product(const Point& one, const Point& two) const;

private:
    Point a_;
    Point b_;
    Point c_;
    Point d_;
    char fillCharacter_;
    char perimeterCharacter_;
};

#endif

