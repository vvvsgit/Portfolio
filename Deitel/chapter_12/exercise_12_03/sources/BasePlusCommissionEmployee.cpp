#include "headers/BasePlusCommissionEmployee.hpp"

#include <iostream>

BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, 
                                                       double sales, double rate, double salary)
    : employee_(first, last, ssn, sales, rate)
{
    setBaseSalary(salary);
}

void
BasePlusCommissionEmployee::setBaseSalary(double salary)
{
    baseSalary_ = (salary < 0.0) ? 0.0 : salary;
}

double
BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary_;
}

const CommissionEmployee&
BasePlusCommissionEmployee::getEmployee() const
{
    return employee_;
}

double
BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + getEmployee().earnings();
}

void
BasePlusCommissionEmployee::print() const
{
    std::cout << "base-salaried ";

    getEmployee().print();
    std::cout << "\nbase salary: " << getBaseSalary();
}

