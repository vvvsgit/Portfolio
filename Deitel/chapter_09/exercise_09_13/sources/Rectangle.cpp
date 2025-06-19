#include "headers/Rectangle.hpp"

#include <iostream>
#include <cmath>
#include <cassert>

Rectangle::Rectangle(const Point& a, const Point& b, const Point& c, const Point& d, const char fillCharacter, const char perimeterCharacter)
{
    setCoordinates(a, b, c, d);
    setFillCharacter(fillCharacter);
    setPerimeterCharacter(perimeterCharacter);
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

    assert(ab == cd && ac == bd && ad == bc);
    
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

char
Rectangle::getFillCharacter() const
{
    return fillCharacter_;
}

void
Rectangle::setFillCharacter(const char fillCharacter)
{
    fillCharacter_ = fillCharacter;
}

char
Rectangle::getPerimeterCharacter() const
{
    return perimeterCharacter_;
}

void
Rectangle::setPerimeterCharacter(const char perimeterCharacter)
{
    assert(perimeterCharacter != ' ');
    perimeterCharacter_ = perimeterCharacter;
}

bool 
Rectangle::isInside(const Point& point) const
{
    if (product(pointsDifference(c_, b_), pointsDifference(point, b_)) < 0 && 
        product(pointsDifference(d_, c_), pointsDifference(point, c_)) < 0 && 
        product(pointsDifference(a_, d_), pointsDifference(point, d_)) < 0 && 
        product(pointsDifference(b_, a_), pointsDifference(point, a_)) < 0)
    {
        return true;
    }
    return false;
}

bool
Rectangle::isOnPerimeter(const Point& point) const
{
    if (product(pointsDifference(c_, b_), pointsDifference(point, b_)) == 0 || 
        product(pointsDifference(d_, c_), pointsDifference(point, c_)) == 0 || 
        product(pointsDifference(a_, d_), pointsDifference(point, d_)) == 0 || 
        product(pointsDifference(b_, a_), pointsDifference(point, a_)) == 0)
    {
        return true;
    }

    return false;
}

double 
Rectangle::product(const Point& one, const Point& two) const
{
    return one.getX() * two.getY() - one.getY() * two.getX();
}

Point 
Rectangle::pointsDifference(const Point& one, const Point& two) const
{
    return Point(one.getX() - two.getX(), one.getY() - two.getY());
}

void 
Rectangle::draw() const
{
    const double minX = std::min(std::min(a_.getX(), b_.getX()), std::min(c_.getX(), d_.getX()));
    const double maxX = std::max(std::max(a_.getX(), b_.getX()), std::max(c_.getX(), d_.getX()));
    const double minY = std::min(std::min(a_.getY(), b_.getY()), std::min(c_.getY(), d_.getY()));
    const double maxY = std::max(std::max(a_.getY(), b_.getY()), std::max(c_.getY(), d_.getY()));

    const int size = 25;
    std::cout << "┏━";
    for (int i = 0; i < size; ++i) {
        std::cout << "━━";
    }
    std::cout << "━┓" << std::endl;

    for (int column = size; column >= 0; --column) {
        std::cout << "┃";
        for (int row = 0; row <= size; ++row) {
            if (row >= minX && row <= maxX && column >= minY && column <= maxY) {
                const Point nextPoint(row, column);
                if (isInside(nextPoint)) {
                    std::cout << ' ' << getFillCharacter();
                    continue;
                }
                if (isOnPerimeter(nextPoint)) {
                    std::cout << ' ' << getPerimeterCharacter();
                    continue;
                }
            }
            std::cout << "  ";
        }
        std::cout << "┃" << std::endl;
    }

    std::cout << "┗━";
    for (int i = 0; i < size; ++i) {
        std::cout << "━━";
    }
    std::cout << "━┛" << std::endl;
}

