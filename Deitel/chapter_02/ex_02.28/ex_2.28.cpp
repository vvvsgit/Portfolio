#include <iostream>

int
main()
{
    std::cout << "\nEnter a five digit integer: ";
    int integer;
    std::cin >> integer;
    if (integer > 99999) {
        std::cerr << "Error 1: Five digit i said!\n" << std::endl;
        return 1;
    }
    if (integer < 10000) {
        std::cerr << "Error 1: Five digit i said!\n" << std::endl;
        return 1 ;
    }
    
    std::cout << integer / 10000 << ' ' 
              << integer / 1000 % 10 << ' '
              << integer / 100 % 10 << ' '
              << integer / 10 % 10 << ' '
              << integer % 10 << std::endl;
    return 0;
}

