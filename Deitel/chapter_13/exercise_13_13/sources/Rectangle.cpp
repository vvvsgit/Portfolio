#include "headers/Rectangle.hpp"

Rectangle::Rectangle(const double length, const double width)
{
    setLength(length);
    setWidth(width);
}

void
Rectangle::setLength(const double length)
{
    assert(length > 0.0);
    length_ = length;
}

void
Rectangle::setWidth(const double width)
{
    assert(width > 0.0);
    width_ = width;
}

double
Rectangle::getLength() const
{
    return length_;
}

double
Rectangle::getWidth() const
{
    return width_;
}

double
Rectangle::getArea() const
{
    return getLength() * getWidth();
}

