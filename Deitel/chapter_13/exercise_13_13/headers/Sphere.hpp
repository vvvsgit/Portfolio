#ifndef __SPHERE_HPP__
#define __SPHERE_HPP__

#include "headers/ThreeDimensional.hpp"

class Sphere : public ThreeDimensional
{
public:
    Sphere(const double radiusi = 1.0);
    
    void setRadius(const double radius);
    double getRadius() const;

    virtual double getArea() const;
    virtual double getVolume() const;
private:
    double radius_;
};

#endif

