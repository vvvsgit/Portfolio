#include <iostream>

int gcd(int, int);

int
main()
{
    std::cout << "\nEnter numbers to find GCD: ";
    int number1, number2;
    std::cin >> number1 >> number2;
    if (number1 <= 0 || number2 <= 0) {
        std::cerr << "\nError 1: Wrong number." << std::endl;
        return 1;
    }

    std::cout << "The GCD is " << gcd(number1, number2) << std::endl;
    std::cout << std::endl;
    return 0;
}

int
gcd(int number1, int number2)
{
    while (number1 != number2) {
        if (number1 > number2) {
            number1 -= number2;
        } else { 
            number2 -= number1;
        }
    }
    return number1;
}

