#include "headers/Cuboid.hpp"

Cuboid::Cuboid(const double length, const double width, const double height)
{
    setLength(length);
    setWidth(width);
    setHeight(height);
}

void
Cuboid::setLength(const double length)
{
    assert(length > 0.0);
    length_ = length;
}

void
Cuboid::setWidth(const double width)
{
    assert(width > 0.0);
    width_ = width;
}

void
Cuboid::setHeight(const double height)
{
    assert(height > 0.0);
    height_ = height;
}

double
Cuboid::getLength() const
{
    return length_;
}

double
Cuboid::getWidth() const
{
    return width_;
}

double
Cuboid::getHeight() const
{
    return height_;
}

double
Cuboid::getArea() const
{
    return getLength() * getWidth();
}

double
Cuboid::getVolume() const
{
    return getArea() * getHeight();
}

