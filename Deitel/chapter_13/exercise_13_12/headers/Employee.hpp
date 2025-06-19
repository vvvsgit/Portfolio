#ifndef __EMPLOYEE_HPP__
#define __EMPLOYEE_HPP__

#include "headers/Date.hpp"

#include <string>
#include <cstdlib>

class Employee
{
public:
    Employee(const std::string& first, const std::string& last, const std::string& ssn, const Date& birthDate);

    void setFirstName(const std::string& first);
    void setLastName(const std::string& last);
    void setSocialSecurityNumber(const std::string& ssn);

    std::string getFirstName() const;
    std::string getLastName() const;
    std::string getSocialSecurityNumber() const;

    virtual double earnings() const = 0;
    virtual void print() const;
    virtual int getBirthdayGift() const;
private:
    std::string firstName_;
    std::string lastName_;
    std::string socialSecurityNumber_;
    Date birthDate_;
};

#endif

