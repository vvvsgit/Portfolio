#ifndef __CHECKING_ACCOUNT_HPP__
#define __CHECKING_ACCOUNT_HPP__

#include "headers/Account.hpp"

class CheckingAccount : public Account
{
public:
    CheckingAccount(const double balance = 0.0, const double fee = 1.0);

    void setFee(const double fee);
    double getFee() const;

    virtual void credit(const double money);
    virtual void debit(const double money);
private:
    double fee_;
};

#endif

