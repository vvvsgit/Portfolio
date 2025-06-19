#include "headers/Package.hpp"

#include <cassert>
#include <iostream>

Package::Package(const Citizen& to, const Citizen& from, const double weight, const double cost)
    : to_(to)
    , from_(from)
{
    setWeight(weight);
    setCostPerOunce(cost);
}

void
Package::setWeight(const double weight)
{
    assert(weight > 0.0);
    weight_ = weight;
}

void
Package::setCostPerOunce(const double cost)
{
    assert(cost > 0.0);
    costPerOunce_ = cost;
}

double
Package::getWeight() const
{
    return weight_;
}

double
Package::getCostPerOunce() const
{
    return costPerOunce_;
}

double
Package::calculateCost() const
{
    return getWeight() * getCostPerOunce();
}

void
Package::printLabel() const
{
    std::cout << "Package to: " << to_.getName() << ", " 
              << to_.getAddress() << ", " 
              << to_.getCity() << ", " 
              << to_.getState() << ", " 
              << to_.getZip() << std::endl;

    std::cout << "Package from: " << from_.getName() << ", " 
              << from_.getAddress() << ", " 
              << from_.getCity() << ", " 
              << from_.getState() << ", " 
              << from_.getZip() << std::endl;
}

