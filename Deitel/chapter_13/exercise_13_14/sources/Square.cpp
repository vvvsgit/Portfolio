#include "headers/Square.hpp"

Square::Square(const double size)
{
    setSize(size);
}

void
Square::setSize(const double size)
{
    assert(size >= 0.0);
    Rectangle::setWidth(size);
    Rectangle::setLength(size);
}

double
Square::getSize() const
{
    return Rectangle::getWidth();
}

double
Square::getArea() const
{
    return Rectangle::getArea();
}

void
Square::draw() const
{
    const int size = getSize();
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            if (0 == i || 0 == j || size - 1 == i || size - 1 == j) {
                std::cout << " *";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

