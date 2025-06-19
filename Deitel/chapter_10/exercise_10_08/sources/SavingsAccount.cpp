#include "headers/SavingsAccount.hpp"

#include <cassert>
#include <iostream>

double SavingsAccount::annualInterestRate_ = 0.0;

void
SavingsAccount::modifyInterestRate(const double rate)
{
    assert(rate > 1.0);
    annualInterestRate_ = rate;
}

double
SavingsAccount::getRate() 
{
    return annualInterestRate_;
}

SavingsAccount::SavingsAccount(const double balance)
{
    setBalance(balance);
}

void 
SavingsAccount::setBalance(const double balance)
{
    assert(balance > 0.0);
    balance_ = balance;
}

double 
SavingsAccount::getBalance() const
{
    return balance_;
}

void 
SavingsAccount::calculateMonthlyInterest()
{
    const double balance = getBalance();
    setBalance(balance + balance * getRate() / 12);
}

void
SavingsAccount::printBalance() const
{
    std::cout << "The balance is " << getBalance() << std::endl << std::endl;
}
