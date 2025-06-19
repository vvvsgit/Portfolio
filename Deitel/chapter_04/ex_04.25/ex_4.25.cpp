#include <iostream>

int
main()
{
    std::cout << "\nEnter number between 1-20: ";
    int number;
    std::cin >> number;
    std::cout << std::endl;
    if (number < 1) {
        std::cerr << "\nError 1: Wrong number." << std::endl;
        return 1;
    }
    if (number > 20) {
        std::cerr << "\nError 1: Wrong number." << std::endl;
        return 1;
    }

    int row = 0;
    while (row < number) { 
        int column = 0;
        while (column < number) {
            if (0 == row) {
                std::cout << '*';
            } else if (number - 1 == row) {
                std::cout << '*';
            } else if (0 == column) {
                std::cout << '*';
            } else if (number - 1 == column) {
                std::cout << '*';
            } else {
                std::cout << ' ';
            }
            ++column;
        }
        std::cout << std::endl;
        ++row;
    }
    std::cout << std::endl;
    return 0;
}

