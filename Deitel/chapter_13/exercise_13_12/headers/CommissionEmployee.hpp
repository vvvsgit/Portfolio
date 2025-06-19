#ifndef __COMMISSION_HPP__
#define __COMMISSION_HPP__

#include "headers/Employee.hpp"

class CommissionEmployee : public Employee
{
public:
    CommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, 
                       const Date& birthDate, const double sales = 0.0, const double rate = 0.0);

    void setGrossSales(const double sales);
    void setCommissionRate(const double rate);
    double getCommissionRate() const;
    double getGrossSales() const;

    virtual double earnings() const;
    virtual void print() const;
private:
    double grossSales_;
    double commissionRate_;
};

#endif

