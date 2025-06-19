#include "headers/BasePlusCommissionEmployee.hpp"

#include <iostream>
BasePlusCommissionEmployee::BasePlusCommissionEmployee(const std::string& first, const std::string& last, 
                                                       const std::string& ssn, const Date& birthDate, 
                                                       const double sales, const double rate, const double salary)
    : CommissionEmployee(first, last, ssn, birthDate, sales, rate)
{
    setBaseSalary(salary);
}

void
BasePlusCommissionEmployee::setBaseSalary(const double salary)
{
    baseSalary_ = ((salary < 0.0) ? 0.0 : salary);
}

double
BasePlusCommissionEmployee::getBaseSalary() const
{
    return baseSalary_;
} 

double
BasePlusCommissionEmployee::earnings() const
{
    return getBaseSalary() + CommissionEmployee::earnings() + Employee::getBirthdayGift();
} 

void
BasePlusCommissionEmployee::print() const
{
    std::cout << "base-salaried ";
    CommissionEmployee::print();
    std::cout << "; base salary: " << getBaseSalary();
}

