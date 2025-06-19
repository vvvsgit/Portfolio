#include <iostream>

int
main()
{
    std::cout << "\nEnter non negative integer: ";
    int integer;
    std::cin >> integer;
    if (integer < 0) {
        std::cerr << "\nError 1: Negative.\n" << std::endl;
        return 1;
    }
    if (0 == integer) {
        std::cout << "0! = 1" << std::endl;
        return 0;
    }

    int factorial = 1;
    int counter = 1;
    while (counter <= integer) {
        factorial *= counter;
        ++counter;
    }
    std::cout << integer << "! = " << factorial << std::endl;
    return 0;
}

