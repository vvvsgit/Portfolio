#include "headers/Employee.hpp"

#include <iostream>
#include <ctime>

Employee::Employee(const std::string& first, const std::string& last, const std::string& ssn, const Date& birthDate)
    : firstName_(first)
    , lastName_(last)
    , socialSecurityNumber_(ssn)
    , birthDate_(birthDate)
{
    std::srand(std::time(0));
}

void
Employee::setFirstName(const std::string& first)
{
    firstName_ = first;
}

void
Employee::setSocialSecurityNumber(const std::string& ssn)
{
    socialSecurityNumber_ = ssn;
}

void
Employee::setLastName(const std::string& last)
{
    lastName_ = last;
}

std::string
Employee::getFirstName() const
{
    return firstName_;
}

std::string
Employee::getLastName() const
{
    return lastName_;
}

std::string
Employee::getSocialSecurityNumber() const
{
    return socialSecurityNumber_;
}

int
Employee::getBirthdayGift() const
{
    const int today = std::rand() % 12 + 1;
    return (today == birthDate_.getMonth() ? 100 : 0);
}

void
Employee::print() const
{
    std::cout << getFirstName() << ' ' << getLastName()
    << "\nsocial security number: " << getSocialSecurityNumber();
}

