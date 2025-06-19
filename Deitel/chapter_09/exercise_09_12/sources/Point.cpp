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
    assert(x >= 0 && x <= 20);
    x_ = x;
}

void
Point::setY(const double y)
{
    assert(y >= 0 && y <= 20);
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

