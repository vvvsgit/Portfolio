#ifndef __SHAPE_HPP__
#define __SHAPE_HPP__

#include <cassert>

class Shape
{
public:
    virtual ~Shape(){}

    virtual double getArea() const = 0;
};

#endif

