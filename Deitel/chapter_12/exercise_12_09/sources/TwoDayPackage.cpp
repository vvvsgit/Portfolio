#include "headers/TwoDayPackage.hpp"

#include <cassert>

TwoDayPackage::TwoDayPackage(const Citizen& to, const Citizen& from, 
                             const double weight, const double cost, const double flatFee)
    : Package(to, from, weight, cost)
{
    setFlatFee(flatFee);
}

void
TwoDayPackage::setFlatFee(const double fee)
{
    assert(fee > 0.0);
    flatFee_ = fee;
}

double
TwoDayPackage::getFlatFee() const
{
    return flatFee_;
}

double
TwoDayPackage::calculateCost() const
{
    return getFlatFee() + Package::calculateCost();
}

