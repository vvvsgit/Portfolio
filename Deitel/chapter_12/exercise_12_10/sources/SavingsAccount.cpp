#include "headers/SavingsAccount.hpp"

#include <cassert>

SavingsAccount::SavingsAccount(const double balance, const double rate)
    : Account(balance)
{
    setRate(rate);
}

void
SavingsAccount::setRate(const double rate)
{
    assert(rate >= 1.0 && rate < 2.0);
    rate_ = rate;
}

double
SavingsAccount::getRate() const
{
    return rate_;
}

double
SavingsAccount::calculateInterest() const
{
    return Account::getBalance() * getRate();
}

