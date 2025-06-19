#include <iostream>

int
main()
{
    std::cout << "\nEnter two integers: ";
    int integer1, integer2;
    std::cin >> integer1 >> integer2;
    if (0 == integer2) {
        std::cerr << "Error 1: Can't be 0.\n" << std::endl;
        return 1;
    }
    if (0 == integer1 % integer2) {
        std::cout << integer1 << " is a multiple of the " << integer2 << std::endl;
        return 0;
    }
    std::cout << integer1 << " isn't a multiple of the " << integer2 << std::endl;
    return 0;
}

