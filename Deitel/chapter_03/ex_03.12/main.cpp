#include "Account.hpp"

#include <iostream>

int
main()
{
    Account account1(1000);
    Account account2(5000);

    std::cout << "account1's starting balance is: " << account1.getAccountBalance() << std::endl;
    std::cout << "account2's starting balance is: " << account2.getAccountBalance() << std::endl;

    account1.credit(150);
    account2.credit(2300);

    std::cout << "account1's balance after credit 150 is: " << account1.getAccountBalance() << std::endl;
    std::cout << "account2's balance after credit 2300 is: " << account2.getAccountBalance() << std::endl;

    account1.debit(2450);
    account2.debit(450);

    std::cout << "account1's balance after debit 2450 is: " << account1.getAccountBalance() << std::endl;
    std::cout << "account2's balance after debit 450 is: " << account2.getAccountBalance() << std::endl;

    return 0;
}

