#include <iostream>
#include <cmath>

int myPower(int, int);
int power(int, int);

int
main()
{
    std::cout << "\nEnter base and exponent to get result: ";
    int base, exponent;
    std::cin >> base >> exponent;
    if (exponent < 0) {
        std::cout << "\nError 1: Wrong exponent." << std::endl;
        return 1;
    }
    std::cout << "pow(" << base << ", " << exponent << ") = " << pow(base, exponent) << std::endl;

    std::cout << "myPower(" << base << ", " << exponent << ") = " << myPower(base, exponent) << std::endl;
    std::cout << "power(" << base << ", " << exponent << ") = " << power(base, exponent) << std::endl;
    std::cout << std::endl;
    return 0;
}

int
myPower(int base, int exponent) {
    if (exponent == 0) {
        return 1;
    }
    if (exponent == 1) {
        return base;
    }
    if (exponent % 2 == 1) {
        return base * myPower(base, exponent - 1);
    }
    int result = myPower(base, exponent / 2);
    return result * result;
}

int
power(int base, int exponent)
{
    if (exponent == 0) {
        return 1;
    }
    int result = 1;
    while (exponent != 0) {
        if (exponent % 2 == 1) {
            result *= base;
            if (exponent == 0) { break; }
        }
        base *= base;
        exponent /= 2;
    }
    return result;
}

