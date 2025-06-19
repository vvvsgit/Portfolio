#include <iostream>

int
main()
{
    std::cout << "\nEnter five digit  positive number: ";
    int number;
    std::cin >> number;
    if (number < 10000) {
        std::cerr << "\nError 1: Try again." << std::endl;
        return 1;
    }
    if (number > 99999) {
        std::cerr << "\nError 1: Try again." << std::endl;
        return 1;
    }

    if (number / 10000 == number % 10) {
        if (number / 1000 % 10 == number / 10 % 10) {
            std::cout << "It is a palindrome." << std::endl;
            return 0;
        }
    }
    std::cout << "It is not a palindrome." << std::endl;
    return 0;
}

