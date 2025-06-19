#include <iostream>
#include <cassert>

int power(int, int);

int
main()
{
    std::cout << "\nEnter base: ";
    int base;
    std::cin >> base;
    if (base < 0) {
        std::cerr << "\nError 1: Wrong base." << std::endl;
        return 1;
    }
    std::cout << "Enter exponent: ";
    int exponent;
    std::cin >> exponent;
    if (exponent < 0) {
        std::cerr << "\nError 1: Wrong exponent." << std::endl;
        return 1;
    }
    std::cout << "Result is " << power(base, exponent) << std::endl;
    std::cout << std::endl;
    return 0;
}

int
power(int base, int exponent) {
    assert(!(base == 0 && exponent == 0));
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    if (exponent % 2 == 1) {
        return base * power(base, exponent - 1);
    }
    int result = power(base, exponent / 2);
    return result * result;    
}

