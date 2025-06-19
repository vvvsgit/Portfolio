#ifndef __HOURLY_HPP__
#define __HOURLY_HPP__

#include "headers/Employee.hpp"

class HourlyEmployee : public Employee
{
public:
    HourlyEmployee(const std::string& first, const std::string& last, const std::string& ssn, 
                   const Date& birthDate, const double wage = 0.0, const double hours = 0.0);

    void setWage(const double wage);
    double getWage() const;
    void setHours(const double hours);
    double getHours() const;

    virtual double earnings() const;
    virtual void print() const;
private:
    double wage_;
    double hours_;
};

#endif 

