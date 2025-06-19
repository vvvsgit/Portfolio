#ifndef __ACCOUNT_HPP__
#define __ACCOUNT_HPP__

class Account
{
public:
    Account(const double balance = 0.0);

    void setBalance(const double balance);
    double getBalance() const;

    void credit(const double money);
    void debit(const double money);
private:
    double balance_;
};

#endif

