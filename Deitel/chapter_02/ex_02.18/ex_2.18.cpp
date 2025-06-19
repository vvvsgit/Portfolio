#include <iostream>

int
main()
{
    std::cout << "\nEnter two integers: ";
    int integer1, integer2;
    std::cin >> integer1 >> integer2;
    
    if (integer1 == integer2) {
        std::cout << "These number are equal.\n" << std::endl;
        return 0;
    }
    if (integer1 > integer2) {
        std::cout << integer1 << " is larger.\n" << std::endl;
        return 0;
    }
    std::cout << integer2 << " is larger.\n" << std::endl;
    return 0;
}

