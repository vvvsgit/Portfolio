#ifndef __TWO_DAY_PACKAGE_HPP__
#define __TWO_DAY_PACKAGE_HPP__

#include "headers/Package.hpp"

class TwoDayPackage : public Package
{
public:
    TwoDayPackage(const Citizen& to, const Citizen& from, const double weight = 1.0, 
                  const double cost = 1.0, const double flatFee = 10.0);

    void setFlatFee(const double fee);
    double getFlatFee() const;

    double calculateCost() const;
private:
    double flatFee_;
};

#endif

