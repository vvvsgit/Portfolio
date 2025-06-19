#ifndef __OVERNIGHT_PACKAGE_HPP__
#define __OVERNIGHT_PACKAGE_HPP__

#include "headers/Package.hpp"

class OvernightPackage : public Package
{
public:
    OvernightPackage(const Citizen& to, const Citizen& from, const double weight = 1.0, 
                     const double cost = 1.0, const double feeForNight = 1.0);

    void setFeeForNight(const double fee);
    double getFeeForNight() const;

    double calculateCost() const;
private:
    double feeForNight_;
};

#endif

