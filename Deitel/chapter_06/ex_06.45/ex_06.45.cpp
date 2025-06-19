#include <iostream>

int gcd(int, int);

int
main()
{
    std::cout << "\nEnter two integers: ";
    int integer1, integer2;
    std::cin >> integer1 >> integer2;
    if (integer1 < 0 || integer2 < 0) {
        std::cerr << "\nError 1: Wrong integer." << std::endl;
        return 1;
    }
    std::cout << "The greatest common divisor of integers " << integer1 << " and " << integer2 << " is " << gcd(integer1, integer2) << std::endl;
    std::cout << std::endl;
    return 0;
}

int
gcd(int x, int y)
{
    if (x < y) {
        return gcd(y, x);
    }
    if (y == 0) {
        return x;
    }
    return gcd(y, x % y);
}

