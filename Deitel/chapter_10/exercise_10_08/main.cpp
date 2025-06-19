#include "headers/SavingsAccount.hpp"

#include <iostream>

int
main()
{
    SavingsAccount account1(2000.0);
    SavingsAccount account2(3000.0);
    
    SavingsAccount::modifyInterestRate(4.0);
    
    account1.calculateMonthlyInterest();
    account2.calculateMonthlyInterest();
    account1.printBalance();
    account2.printBalance();
    
    SavingsAccount::modifyInterestRate(5.0);

    account1.calculateMonthlyInterest();
    account2.calculateMonthlyInterest();
    account1.printBalance();
    account2.printBalance();

    return 0;
}

