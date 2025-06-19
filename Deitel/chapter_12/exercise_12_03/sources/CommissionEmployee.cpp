#include "headers/CommissionEmployee.hpp"

#include <iostream>

CommissionEmployee::CommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn,
                                       double sales, double rate)
    : firstName_(first), lastName_(last), socialSecurityNumber_(ssn)
{
    setGrossSales(sales);
    setCommissionRate(rate);
}

void
CommissionEmployee::setFirstName(const std::string& first)
{
    firstName_ = first;
}

std::string
CommissionEmployee::getFirstName() const
{
    return firstName_;
}

void
CommissionEmployee::setLastName(const std::string& last)
{
    lastName_ = last;
}

std::string
CommissionEmployee::getLastName() const
{
    return lastName_;
}

void
CommissionEmployee::setSocialSecurityNumber(const std::string& ssn)
{
    socialSecurityNumber_ = ssn;
}

std::string
CommissionEmployee::getSocialSecurityNumber() const
{
    return socialSecurityNumber_;
}

void
CommissionEmployee::setGrossSales(double sales)
{
    grossSales_ = (sales < 0.0) ? 0.0 : sales;
}

double
CommissionEmployee::getGrossSales() const
{
    return grossSales_;
}

void
CommissionEmployee::setCommissionRate(double rate)
{
    commissionRate_ = (rate > 0.0 && rate < 1.0) ? rate : 0.0;
}

double
CommissionEmployee::getCommissionRate() const
{
    return commissionRate_;
}

double
CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales();
}

void
CommissionEmployee::print() const
{
    std::cout << "commission employee: "
    << getFirstName() << ' ' << getLastName()
    << "\nsocial security number: " << getSocialSecurityNumber()
    << "\ngross sales: " << getGrossSales()
    << "\ncommission rate: " << getCommissionRate();
}
