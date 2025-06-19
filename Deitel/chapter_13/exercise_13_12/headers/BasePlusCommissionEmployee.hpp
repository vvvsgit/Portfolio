#ifndef __BASEPLUS_HPP__
#define __BASEPLUS_HPP__

#include "headers/CommissionEmployee.hpp"

class BasePlusCommissionEmployee : public CommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, const Date& birthDate,
                               const double sales = 0.0, const double rate = 0.0, const double salary = 0.0);
    void setBaseSalary(const double salary);
    double getBaseSalary() const;

    virtual double earnings() const;
    virtual void print() const;
private:
    double baseSalary_;
};

#endif

