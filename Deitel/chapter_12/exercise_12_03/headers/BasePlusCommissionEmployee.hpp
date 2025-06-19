#ifndef BASEPLUS_H
#define BASEPLUS_H

#include "CommissionEmployee.hpp"

#include <string>

class BasePlusCommissionEmployee
{
public:
    BasePlusCommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, double sales = 0.0, double = 0.0, double salary = 0.0);
    void setBaseSalary(double salary);
    double getBaseSalary() const;
    double earnings() const;
    void print() const;
    const CommissionEmployee& getEmployee() const;
private:
    const CommissionEmployee employee_;
    double baseSalary_;
};

#endif

