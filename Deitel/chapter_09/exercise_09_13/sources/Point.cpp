#include "headers/Point.hpp"

#include <cassert>

Point::Point(const double x, const double y)
{
    setX(x);
    setY(y);
}

void
Point::setX(const double x)
{
    x_ = x;
}

void
Point::setY(const double y)
{
    y_ = y;
}

double
Point::getX() const
{
    return x_;
}

double
Point::getY() const
{
    return y_;
}

