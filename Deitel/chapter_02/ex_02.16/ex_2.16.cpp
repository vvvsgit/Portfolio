#include <iostream>

int
main()
{
    std::cout << "\nEnter two numbers: ";
    int number1, number2;
    std::cin >> number1 >> number2;
    int sum = number1 + number2;
    int product = number1 * number2;
    int difference = number1 - number2;
    int quotient = number1 / number2;

    std::cout << "\nSum of the numbers is " << sum <<
        "\nProduct of the numbers is " << product <<
        "\nDifference of the numbers is " << difference <<
        "\nQuotient of the numbers is " << quotient << std::endl << std::endl;

    return 0;
}

