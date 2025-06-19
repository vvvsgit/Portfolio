#include <iostream>
#include <iomanip>
#include <cmath>

int
main()
{
    std::cout << "\nYear" << std::setw(21) << "Amount on deposit" << std::endl << std::fixed << std::setprecision(2);

    double principal = 1000;
    double rate = 0.05;
    int years = 10;
    for (int rates = 5; rates <= 10; ++rates) {
        for (int year = 1; year <= years; ++year) {
            double amount;
            amount = principal * pow(1.0 + rate, year);
            std::cout << std::setw(4) << year << std::setw(24) << amount << std::endl;
        }
        rate += 0.01;
        std::cout << std::endl;
    }

    return 0;
}


