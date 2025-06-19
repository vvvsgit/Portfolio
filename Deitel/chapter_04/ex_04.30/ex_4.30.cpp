#include <iostream>

int
main()
{
    std::cout << "\nEnter radius: ";
    double pi = 3.14159;
    double radius;
    std::cin >> radius;
    if (radius < 0) {
        std::cerr << "\nError 1: cant be negative." << std::endl;
        return 1;
    }
    std::cout << "\nDiameter = " << 2 * radius
              << "\ncircumference = " << 2 * pi * radius
              << "\nArea = " << pi * radius * radius << std::endl;
    return 0;
}

