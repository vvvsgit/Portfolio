#include "headers/SalariedEmployee.hpp"

#include <iostream>

SalariedEmployee::SalariedEmployee(const std::string& first, const std::string& last, 
                                   const std::string& ssn, const Date& birthDate, const double salary)
    : Employee(first, last, ssn, birthDate)
{
    setWeeklySalary(salary);
}

void
SalariedEmployee::setWeeklySalary(const double salary)
{
    weeklySalary_ = (salary < 0.0) ? 0.0 : salary;
}

double
SalariedEmployee::getWeeklySalary() const
{
    return weeklySalary_;
}

double
SalariedEmployee::earnings() const
{
    return getWeeklySalary() + Employee::getBirthdayGift();
}

void
SalariedEmployee::print() const
{
    std::cout << "salaried employee: ";
    Employee::print();
    std::cout << "\nweekly salary: " << getWeeklySalary();
}

