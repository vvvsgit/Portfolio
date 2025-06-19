#ifndef __PYRAMID_HPP__
#define __PYRAMID_HPP__

#include "headers/ThreeDimensional.hpp"

class Pyramid : public ThreeDimensional
{
public:
    Pyramid(/*const double base = 9.0, const double height = 5.0*/);
/*
    void setBase(const double base);
    void setHeight(const double height);
    double getBase() const;
    double getHeight() const;
*/
    virtual double getArea() const = 0;
    virtual double getVolume() const = 0;
private:
/*
    double base_;
    double height_;
*/
};

#endif

