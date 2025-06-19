#ifndef __RECTANGLE_HPP__
#define __RECTANGLE_HPP__

#include "headers/TwoDimensional.hpp"

class Rectangle : public TwoDimensional 
{
public:
    Rectangle(const double length = 4.0, const double width = 7.0);

    void setLength(const double length);
    void setWidth(const double width);
    double getLength() const;
    double getWidth() const;

    virtual double getArea() const;
    virtual void draw() const;
private:
    double length_;
    double width_;
};

#endif

