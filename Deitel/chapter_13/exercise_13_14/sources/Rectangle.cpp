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

void
Rectangle::draw() const
{
    const int width = getWidth();
    const int length = getLength();
    for (int i = 0; i < length; ++i) {
        for (int j = 0; j < width; ++j) {
            if (0 == i || 0 == j || width - 1 == j || length - 1 == i) {
                std::cout << " *";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

