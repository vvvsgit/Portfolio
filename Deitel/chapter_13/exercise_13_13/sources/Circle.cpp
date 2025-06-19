#include "headers/Circle.hpp"

Circle::Circle(const double radius)
{
    setRadius(radius);
}

void 
Circle::setRadius(const double radius)
{
    assert(radius > 0.0);
    radius_ = radius;
}

double 
Circle::getRadius() const
{
    return radius_;
}

double 
Circle::getArea() const
{
    return getRadius() * 3.14 * getRadius();
}

