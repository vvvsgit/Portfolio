#ifndef __SAVINGS_ACCOUNT_HPP__
#define __SAVINGS_ACCOUNT_HPP__

#include "headers/Account.hpp"

class SavingsAccount : public Account
{
public:
    SavingsAccount(const double balance = 0.0, const double rate = 1.0);

    void setRate(const double rate);
    double getRate() const;

    double calculateInterest() const;
private:
    double rate_;
};

#endif

