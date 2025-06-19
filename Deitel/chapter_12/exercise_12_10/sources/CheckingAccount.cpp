#include "headers/CheckingAccount.hpp"

#include <cassert>

CheckingAccount::CheckingAccount(const double balance, const double fee)
    : Account(balance)
{
    setFee(fee);
}

void
CheckingAccount::setFee(const double fee)
{
    assert(fee >= 0.0);
    fee_ = fee;
}

double
CheckingAccount::getFee() const
{
    return fee_;
}

void 
CheckingAccount::credit(const double money)
{
    const double checkMoney = money + Account::getBalance();
    assert(money > 0.0 && checkMoney >= getFee());
    Account::setBalance(checkMoney - getFee());
}

void
CheckingAccount::debit(const double money)
{
    const double checkMoney = money + getFee();
    assert(money > 0.0 && checkMoney <= Account::getBalance());
    Account::setBalance(Account::getBalance() - checkMoney);
}

