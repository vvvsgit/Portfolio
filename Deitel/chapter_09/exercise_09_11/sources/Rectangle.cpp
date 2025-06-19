#include "headers/Rectangle.hpp"

#include <iostream>

Rectangle::Rectangle(const double length, const double width)
{
    setLength(length);
    setWidth(width);
}

void
Rectangle::setLength(const double length)
{
    if (length <= 0.0 || length > 20.0) {
        std::cout << "Error 1: invalid length, set to 1.0." << std::endl;
        length_ = 1.0;
        return;
    }
    length_ = length;
}

void
Rectangle::setWidth(const double width)
{
    if (width <= 0.0 || width > 20.0) {
        std::cout << "Error 1: invalid width, set to 1.0." << std::endl;
        width_ = 1.0;
        return;
    }
    width_ = width;
}

double
Rectangle::getLength()
{
    return length_;
}

double
Rectangle::getWidth()
{
    return width_;
}

double
Rectangle::perimeter()
{
    return 2 * getLength() + 2 * getWidth();
}

double
Rectangle::area()
{
    return getLength() * getWidth();
}

