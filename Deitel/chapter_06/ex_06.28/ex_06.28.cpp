#include <iostream>

double smallest(double, double, double);

int
main()
{
    std::cout << "\nEnter three floating numbers: ";
    double number1, number2, number3;
    std::cin >> number1 >> number2 >> number3;
    std::cout << "The smallest of them is " << smallest(number1, number2, number3) << std::endl << std::endl;
    return 0;
}

double
smallest(double number1, double number2, double number3)
{
    double smallest = number1;
    if (smallest > number2) {
        smallest = number2;
    }
    if (smallest > number3) {
        smallest = number3;
    }
    return smallest;
}

