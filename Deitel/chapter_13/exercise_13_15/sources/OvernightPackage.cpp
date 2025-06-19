#include "headers/OvernightPackage.hpp"

#include <cassert>

OvernightPackage::OvernightPackage(const Citizen& to, const Citizen& from, const double weight, 
                                   const double cost, const double feeForNight)
    : Package(to, from, weight, cost)
{
    setFeeForNight(feeForNight);
}

void
OvernightPackage::setFeeForNight(const double fee)
{
    assert(fee > 0.0);
    feeForNight_ = fee;
}

double
OvernightPackage::getFeeForNight() const
{
    return feeForNight_;
}

double
OvernightPackage::calculateCost() const
{
    return getFeeForNight() * Package::getWeight() + Package::calculateCost();
}

