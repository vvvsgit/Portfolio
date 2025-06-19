#include "headers/CommissionEmployee.hpp"

#include <iostream>

CommissionEmployee::CommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, 
                                       const Date& birthDate, const double sales, const double rate)
    : Employee(first, last, ssn, birthDate)
{
    setGrossSales(sales);
    setCommissionRate(rate);
}

void
CommissionEmployee::setGrossSales(const double sales)
{
    grossSales_ = ((sales < 0.0) ? 0.0 : sales);
}

void
CommissionEmployee::setCommissionRate(const double rate)
{
    commissionRate_ = ((rate > 0.0 && rate < 1.0) ? rate : 0.0);
}

double
CommissionEmployee::getGrossSales() const
{
    return grossSales_;
}

double
CommissionEmployee::getCommissionRate() const
{
    return commissionRate_;
}

double
CommissionEmployee::earnings() const
{
    return getCommissionRate() * getGrossSales() + Employee::getBirthdayGift();
}

void
CommissionEmployee::print() const
{
    std::cout << "commission employee: ";
    Employee::print();
    std::cout << "\ngross sales: " << getGrossSales()
    << "; commission rate: " << getCommissionRate();
}

