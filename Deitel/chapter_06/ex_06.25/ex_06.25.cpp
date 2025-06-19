#include <iostream>
#include <cmath>

int quotient(int, int);
int remainder(int, int);

int
main()
{
    std::cout << "\nEnter integer 1 - 32767: ";
    int number;
    std::cin >> number;
    if (number < 1 || number > 32767) {
        std::cerr << "\nError 1: wrong number." << std::endl;
        return 1;
    }
    int length = 0;
    int numberD = number;
    while (numberD != 0) {
        numberD /= 10;
        ++length;
    }
    int tenths = pow(10, length - 1);
    while (number != 0) {
        std::cout << quotient(number, tenths) << ' ';
        number = remainder(number, tenths);
        tenths /= 10;
    }
    std::cout << std::endl;
    return 0;
}

int
quotient(int number, int divider)
{
    return number / divider;
}

int
remainder(int number, int divider)
{
    return number % divider;
}

