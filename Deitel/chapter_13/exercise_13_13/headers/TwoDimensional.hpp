#ifndef __TWO_DIMENSIONAL_HPP__
#define __TWO_DIMENSIONAL_HPP__

#include "headers/Shape.hpp"

class TwoDimensional : public Shape
{
public:
//    virtual ~TwoDimensional();

    virtual double getArea() const = 0;
};

#endif

