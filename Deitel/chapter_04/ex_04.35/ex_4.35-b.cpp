#include <iostream>

int
main()
{
    std::cout << "\nEnter accuracy: ";
    int integer;
    std::cin >> integer;
    if (integer <= 0) {
        std::cerr << "\nError 1: wrong accuracy.\n" << std::endl;
        return 1;
    }
    if (1 == integer) {
        std::cout << "e = 1" << std::endl;
        return 0;
    }

    int factorial = 1;
    int counter = 1;
    double e = 1;
    while (counter < integer) {
        factorial *= counter;
        e += 1.0 / factorial;
        ++counter;
    }
    std::cout << "e = " << e << std::endl;
    return 0;
}

