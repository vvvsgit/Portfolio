#include "headers/Sphere.hpp"

Sphere::Sphere(const double radius)
{
    setRadius(radius);
}

void
Sphere::setRadius(const double radius)
{
    assert(radius > 0.0);
    radius_ = radius;
}

double
Sphere::getRadius() const
{
    return radius_;
}

double
Sphere::getArea() const
{
    return 4.0 * 3.14 * getRadius() * getRadius();
}

double
Sphere::getVolume() const
{
    return 4.0/3.0 * 3.14 * getRadius() * getRadius() * getRadius();
}

