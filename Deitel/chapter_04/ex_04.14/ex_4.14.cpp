#include <iostream>

int
main()
{
    std::cout << "\nEnter account number (negative to end): ";
    int account;
    std::cin >> account;
    while (account >= 0) {
        std::cout << "Enter beginning balance: ";
        double balance;
        std::cin >> balance;
        if (balance < 0) {
            std::cerr << "\nError 1: Not possible." << std::endl;
            return 1;
        }
        std::cout << "Enter total charges: ";
        double charges;
        std::cin >> charges;
        if (charges < 0) {
            std::cerr << "\nError 1: Not possible." << std::endl;
            return 1;
        }
        balance += charges;
        std::cout << "Enter total credits: ";
        double credits;
        std::cin >> credits;
        if (credits < 0) {
            std::cerr << "\nError 1: Not possible." << std::endl;
            return 1;
        }
        if (balance < credits) {
            std::cerr << "\nError 2: Money lack." << std::endl;
            return 2;
        }
        balance -= credits;
        std::cout << "Enter credit limit: ";
        double limit;
        std::cin >> limit;
        if (limit < 0) {
            std::cerr << "\nError 1: Not possible." << std::endl;
            return 1;
        }
        std::cout << "\nNew balance is " << balance << std::endl;
        if (limit < balance) {
            std::cout << "\nAccount " << account << "\nCredit limit: " << limit << "\nBalance: " << balance << "\nCredit Limit Exceeded.\n" << std::endl;
        }
        std::cout << "\nEnter account number (negative to end): ";
        std::cin >> account;
    }
    return 0;
}

