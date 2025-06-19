#ifndef __TWO_DIMENSIONAL_HPP__
#define __TWO_DIMENSIONAL_HPP__

#include "headers/Shape.hpp"

class TwoDimensional : public Shape
{
public:
    virtual double getArea() const = 0;
    virtual void draw() const = 0;
};

#endif

