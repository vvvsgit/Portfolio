#include "headers/Account.hpp"

#include <cassert>

Account::Account(const double balance)
{
    setBalance(balance);
}

void
Account::setBalance(const double balance)
{
    assert(balance >= 0.0);
    balance_ = balance;
}

double 
Account::getBalance() const
{
    return balance_;
}

void 
Account::credit(const double money)
{
    assert(money > 0.0);
    setBalance(getBalance() + money);
}

void
Account::debit(const double money)
{
    assert(money > 0.0 && money <= getBalance());
    setBalance(getBalance() - money);
}

