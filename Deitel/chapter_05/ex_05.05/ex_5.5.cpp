#include <iostream>

int
main()
{
    std::cout << "\nEnter quantity of summation: ";
    int quantity;
    std::cin >> quantity;
    if (quantity < 0) {
        std::cerr << "\nErroe 1: Wrong quantity." << std::endl;
        return 1;
    }

    int sum = 0;
    for (int i = 0; i < quantity; ++i) {
        std::cout << "Enter next number: ";
        int number;
        std::cin >> number;
        sum += number;
    }

    std::cout << "The sum of all numbers is " << sum << std::endl;
    return 0;
}

