#ifndef __SALARIED_HPP__
#define __SALARIED_HPP__

#include "headers/Employee.hpp"

class SalariedEmployee : public Employee
{
public:
    SalariedEmployee(const std::string& first, const std::string& last, const std::string& ssn, 
                     const Date& birthDate, const double salary = 0.0);

    void setWeeklySalary(const double salary);
    double getWeeklySalary() const;
    
    virtual double earnings() const;
    virtual void print() const;
private:
    double weeklySalary_;
};

#endif

