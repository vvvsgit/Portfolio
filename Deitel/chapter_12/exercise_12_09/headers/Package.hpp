#ifndef __PACKAGE_HPP__
#define __PACKAGE_HPP__

#include "headers/Citizen.hpp"

#include <string>

class Package
{
public:
    Package(const Citizen& to, const Citizen& from, const double weight = 1.0, const double cost = 1.0);

    void setWeight(const double weight);
    void setCostPerOunce(const double cost);
    double getWeight() const;
    double getCostPerOunce() const;
    
    double calculateCost() const;
    void printLabel();
private:
    const Citizen to_;
    const Citizen from_;
    double weight_;
    double costPerOunce_;
};

#endif

