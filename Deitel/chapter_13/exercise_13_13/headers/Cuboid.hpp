#ifndef __CUBOID_HPP__
#define __CUBOID_HPP__

#include "headers/ThreeDimensional.hpp"

class Cuboid : public ThreeDimensional
{
public:
    Cuboid(const double length = 2.0, const double width = 3.0, const double height = 4.0);

    void setLength(const double length);
    void setWidth(const double width);
    void setHeight(const double height);
    double getLength() const;
    double getWidth() const;
    double getHeight() const;

    virtual double getArea() const;
    virtual double getVolume() const;
private:
    double length_;
    double width_;
    double height_;
};

#endif

