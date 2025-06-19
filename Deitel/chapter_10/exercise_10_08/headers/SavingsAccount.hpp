#ifndef __SAVINGS_ACCOUNT_HPP__
#define __SAVINGS_ACCOUNT_HPP__

class SavingsAccount
{
public:
    static void modifyInterestRate(const double rate);
    static double getRate();
private:
    static double annualInterestRate_;
public:
    SavingsAccount(const double balance);
    void setBalance(const double balance);
    double getBalance() const;
    void calculateMonthlyInterest();
    void printBalance() const;
private:
    double balance_;
};

#endif

