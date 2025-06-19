#include <iostream>
#include <cmath>

int reverse(int);

int
main()
{
    std::cout << "\nEneter an integer: ";
    int number;
    std::cin >> number;
    std::cout << "The reversed number is " << reverse(number) << std::endl;
    std::cout << std::endl;
    return 0;
}

int
reverse(int number)
{
    int digits = 0;
    int reverseNumber = number;
    while (reverseNumber != 0) {
        reverseNumber /= 10;
        ++digits;
    }
    int tents = pow(10, digits - 1);
    int power = 1;
    for (int i = 0; i < digits; ++i) {
        reverseNumber += number / tents * power;
        number %= tents;
        tents /= 10;
        power *= 10;
    }
    return reverseNumber;
}

