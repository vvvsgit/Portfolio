#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include <cassert>
#include <iostream>

class Shape
{
public:
    virtual ~Shape() {}

    virtual double getArea() const = 0;
    virtual void draw() const = 0;
};

#endif

