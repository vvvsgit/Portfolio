#ifndef __TRIANGLE_HPP__
#define __TRIANGLE_HPP__

#include "headers/TwoDimensional.hpp"

class Triangle : public TwoDimensional
{
public:
    Triangle(const double side1 = 2.0, const double side2 = 3.0, const double side3 = 4.0);

    void setSides(const double side1, const double side2, const double side3);
    double getSide1() const;
    double getSide2() const;
    double getSide3() const;

    virtual double getArea() const;
private:
    double side1_;
    double side2_;
    double side3_;
};

#endif

