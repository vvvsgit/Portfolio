#include <iostream>

int
main()
{
    std::cout << "\nEnter an integer: ";
    int integer;
    std::cin >> integer;
    if (0 == integer % 2) {
        std::cout << "It is even.\n" << std::endl;
        return 0;
    }
    std::cout << "It is odd.\n" << std::endl;
    return 0;
}

