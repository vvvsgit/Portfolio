#ifndef __CIRCLE_HPP__
#define __CIRCLE_HPP__

#include "headers/TwoDimensional.hpp"

class Circle : public TwoDimensional
{
public:
    Circle(const double radius = 4.0);

    void setRadius(const double radius);
    double getRadius() const;

    virtual double getArea() const;
    virtual void draw() const;
private:
    double radius_;
};

#endif

