#ifndef __THREE_DIMENSIONAL_HPP__
#define __THREE_DIMENSIONAL_HPP__

#include "headers/Shape.hpp"

class ThreeDimensional : public Shape
{
public:
//    virtual ~ThreeDimensional();

    virtual double getArea() const = 0;
    virtual double getVolume() const = 0;
};

#endif

