#ifndef __SQUARE_HPP__
#define __SQUARE_HPP__

#include "headers/Rectangle.hpp"

class Square : public Rectangle
{
public:
    Square(const double size = 5.0);

    void setSize(const double size);
    double getSize() const;

    virtual double getArea() const;
    virtual void draw() const;
};

#endif

