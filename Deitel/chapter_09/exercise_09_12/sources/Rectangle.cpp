#include "headers/Rectangle.hpp"

#include <iostream>
#include <cmath>
#include <cassert>

Rectangle::Rectangle(const Point& a, const Point& b, const Point& c, const Point& d)
{
    setCoordinates(a, b, c, d);
}

void
Rectangle::setCoordinates(const Point& a, const Point& b, const Point& c, const Point& d)
{
    assert(!(0 == a.getX() && 0 == a.getY() && 0 == b.getX() && 0 == b.getY() &&
             0 == c.getX() && 0 == c.getY() && 0 == d.getX() && 0 == d.getY()));  
    const double ab = calculateDistance(a, b);
    const double cd = calculateDistance(c, d);

    const double ac = calculateDistance(a, c);
    const double bd = calculateDistance(b, d);

    const double ad = calculateDistance(a, d);
    const double bc = calculateDistance(b, c);

    if (!(ab == cd && ac == bd && ad == bc)) {
        std::cout << "Error 1: not a rectangle." << std::endl;
        ::exit(1);
    }
    
    if (ab > ac && ab > ad) {
        a_ = a;
        c_ = b;
        b_ = ac <= ad ? c : d;
        d_ = ad < ac ? c : d;
        return;
    }
    if (ac > ab && ac > ad) {
        a_ = a;
        c_ = c;
        b_ = ab <= ad ? b : d;
        d_ = ad < ab ? b : d;
        return;
    }
    a_ = a;
    c_ = d;
    b_ = ab <= ac ? b : c;
    d_ = ac < ab ? b : c;
}

double
Rectangle::length()
{
    return calculateDistance(a_, d_);
}

double
Rectangle::width()
{
    return calculateDistance(a_, b_);
}

double
Rectangle::perimeter()
{
    return 2 * length() + 2 * width();
}

double
Rectangle::area()
{
    return length() * width();
}

bool
Rectangle::isSquare()
{
    return length() == width();
}

double
Rectangle::calculateDistance(const Point& one, const Point& two)
{
    return sqrt((one.getX() - two.getX()) * (one.getX() - two.getX()) + (one.getY() - two.getY()) * (one.getY() - two.getY()));
}

