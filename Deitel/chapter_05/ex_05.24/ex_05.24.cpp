#include <iostream>

int
main()
{
    std::cout << "\nEnter odd number 1 - 19: ";
    int number;
    std::cin >> number;
    if (number < 1 || number > 19 || number % 2 == 0) {
        std::cerr << "\nError 1: Wrong number." << std::endl;
        return 1;
    }
    std::cout << std::endl;
    for (int i = -number / 2; i <= number / 2; ++i) {
        std::cout << '\t';
        for (int j = -number / 2; j <= number/ 2; ++j) {
            std::cout << (abs(i) + abs(j) <= number / 2 ? '*' : ' ');
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

