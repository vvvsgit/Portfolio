#include "Account.hpp"

#include <iostream>

Account::Account(int initialBalance)
{
    setAccountBalance(initialBalance);
}

void
Account::setAccountBalance(int initialBalance)
{
    if (initialBalance < 0) {
        accountBalance_ = 0;
        return;
    }
    accountBalance_ = initialBalance;
}

int
Account::getAccountBalance()
{
    return accountBalance_;
}

void
Account::credit(int creditBalance)
{
    if (creditBalance < 0) {
        return;
    }
    accountBalance_ = accountBalance_ + creditBalance;
}

void
Account::debit(int debitBalance)
{
    if (debitBalance < 0) {
        return;
    }
    if (debitBalance > accountBalance_) {
        std::cout << "Debit amount exceeded account balance." << std::endl;
        return;
    }
    accountBalance_ = accountBalance_ - debitBalance;
}

