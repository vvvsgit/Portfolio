#include "headers/HourlyEmployee.hpp"

#include <iostream>

HourlyEmployee::HourlyEmployee(const std::string& first, const std::string& last, const std::string& ssn, 
                               const Date& birthDate, const double hourlyWage, const double hoursWorked)
    : Employee(first, last, ssn, birthDate)
{
    setWage(hourlyWage);
    setHours(hoursWorked);
}

void
HourlyEmployee::setWage(const double hourlyWage)
{
    wage_ = (hourlyWage < 0.0 ? 0.0 : hourlyWage);
}

double
HourlyEmployee::getWage() const
{
    return wage_;
}

void
HourlyEmployee::setHours(const double hoursWorked )
{
    hours_ = (((hoursWorked >= 0.0) && (hoursWorked <= 168.0)) ?  hoursWorked : 0.0);
}

double
HourlyEmployee::getHours() const
{
    return hours_;
}

double 
HourlyEmployee::earnings() const
{
    if (getHours() <= 40) {
        return getWage() * getHours() + Employee::getBirthdayGift();
    } else {
        return 40 * getWage() + ((getHours() - 40) * getWage() * 1.5) + Employee::getBirthdayGift();
    }
}

void
HourlyEmployee::print() const
{
    std::cout << "hourly employee: ";
    Employee::print();
    std::cout << "\nhourly wage: " << getWage() <<
    "; hours worked: " << getHours();
}

