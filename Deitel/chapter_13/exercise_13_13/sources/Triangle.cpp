#include "headers/Triangle.hpp"

#include <cmath>

Triangle::Triangle(const double side1, const double side2, const double side3)
{
    setSides(side1, side2, side3);
}

void
Triangle::setSides(const double side1, const double side2, const double side3)
{
    assert(side1 > 0.0 && side2 > 0.0 && side3 > 0.0);
    assert(side1 + side2 > side3);
    assert(side1 + side3 > side2);
    assert(side2 + side3 > side1);
    side1_ = side1;
    side2_ = side2;
    side3_ = side3;
}

double
Triangle::getSide1() const
{
    return side1_;
}

double
Triangle::getSide2() const
{
    return side2_;
}

double
Triangle::getSide3() const
{
    return side3_;
}

double
Triangle::getArea() const
{
    const double semiPerimeter = (getSide1() + getSide2() + getSide3()) / 2;
    return std::sqrt(semiPerimeter 
                     * (semiPerimeter - getSide1()) 
                     * (semiPerimeter - getSide2()) 
                     * (semiPerimeter - getSide3()));
}

