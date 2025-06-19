#include <iostream>
#include <iomanip>
#include <cmath>

int
main()
{
    std::cout << "\nYear" << std::setw(21) << "Amount on deposit" << std::endl << std::fixed << std::setprecision(2);

    int principal = 100000;
    double rate = 0.05;
    for (int rates = 5; rates <= 10; ++rates) {
        for (int year = 1; year <= 10; ++year) {
            int amount;
            amount = principal * pow(1.0 + rate, year);
            std::cout << std::setw(4) << year << std::setw(18) << amount / 100 << '.' << amount / 10 % 10 << amount % 10 << std::endl;
        }
        rate += 0.01;
        std::cout << std::endl;
    }
    return 0;
}


