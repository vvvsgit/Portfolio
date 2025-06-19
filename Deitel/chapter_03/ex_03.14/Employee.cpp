#include "Employee.hpp"

#include <iostream>

Employee::Employee(std::string firstName, std::string lastName, int monthlySalary)
{
    setFirstName(firstName);
    setLastName(lastName);
    setMonthlySalary(monthlySalary);
}

void
Employee::setFirstName(std::string name)
{
    if (name.length() > 10) {
        std::cout << "\nFirst name \"" << name << "\" is to long." << std::endl;
        firstName_ = name.substr(0, 10);
        return;
    }
    firstName_ = name;
}

void
Employee::setLastName(std::string name)
{
    if (name.length() > 10) {
        std::cout << "\nLast name \"" << name << "\" is to long." << std::endl;
        lastName_ = name.substr(0, 10);
        return;
    }
    lastName_ = name;
}

void
Employee::setMonthlySalary(int salary)
{
    if (salary < 0) {
        monthlySalary_ = 0;
        return;
    }
    monthlySalary_ = salary;
}

std::string
Employee::getFirstName()
{
    return firstName_;
}

std::string
Employee::getLastName()
{
    return lastName_;
}

int
Employee::getMonthlySalary()
{
    return monthlySalary_;
}

int
Employee::getYearlySalary()
{
    return getMonthlySalary() * 12;
}

void
Employee::salaryRaiseByTenPercent()
{
    setMonthlySalary(getMonthlySalary() + getMonthlySalary() / 10);
}

