#include "headers/Circle.hpp"

#include <cmath>

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

void
Circle::draw() const
{
    const int size = getRadius();
    for (int i = -size; i <= size; ++i) {
        for (int j = -size; j <= size; ++j) {
            if (0 == i && 0 == j) {
                std::cout << " .";
                continue;
            }
             
            if ((0 == std::abs(i) && size == std::abs(j)) || (0 == std::abs(j) && size == std::abs(i))) {
                std::cout << " *";
            } else if ((size - (size/3) == std::abs(i) && size - (size/3) == std::abs(j)) || 
                       (size - (size/3) == std::abs(j) && size - (size/3) == std::abs(i))) {
                std::cout << " *";
            } else if (((size/3) == std::abs(j) && size - (size/6) == std::abs(i)) || 
                       (size - (size/6) == std::abs(i) && (size/3) == std::abs(j)) ||
                       ((size/3) == std::abs(i) && size - (size/6) == std::abs(j)) || 
                       (size - (size/6) == std::abs(j) && (size/3) == std::abs(i))) {
                std::cout << " *";
            } else {
                std::cout << "  ";
            }
        }
        std::cout << std::endl;
    }
}

