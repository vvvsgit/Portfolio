#include <iostream>

int integerPower(int, int);

int
main()
{
    std::cout << "\nEnter integer and power: ";
    int integer, power;
    std::cin >> integer >> power;
    std::cout << integerPower(integer, power) << " = " << integer << '^' << power << std::endl;
    std::cout << std::endl;
    return 0;
}

int
integerPower(int base, int exponent)
{
    if (base < 0 || exponent < 0 || (base == 0 && exponent == 0)) {
        std::cerr << "\nError 1: Wrong." << std::endl;
        ::exit(1);
    }
    int power = base;
    int result = 1;
    while (exponent != 0) {
        if (1 == exponent % 2) {
            result *= power;
        }
        exponent /= 2;
        power *= power;
    }
    return result;
}

