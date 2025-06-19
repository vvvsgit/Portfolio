#ifndef __COMMISSION_EMPLOYEE_HPP__
#define __COMMISSION_EMPLOYEE_HPP__

#include <string>

class CommissionEmployee
{
public:
    CommissionEmployee(const std::string& first, const std::string& last, const std::string& ssn, double sales = 0.0, double rate = 0.0);
    void setFirstName(const std::string& first);
    std::string getFirstName() const;
    void setLastName(const std::string& last);
    std::string getLastName() const;
    void setSocialSecurityNumber(const std::string& ssn);
    std::string getSocialSecurityNumber() const;
    void setGrossSales(double sales);
    double getGrossSales() const;
    void setCommissionRate(double rate);
    double getCommissionRate() const;
    double earnings() const;
    void print() const; 
private:
    std::string firstName_;
    std::string lastName_;
    std::string socialSecurityNumber_;
    double grossSales_; 
    double commissionRate_;
};

#endif

