#include <iostream>
#include <cassert>

bool multiple(int, int);

int
main()
{
    std::cout << "\nEnter pair of integers: ";
    int number1, number2;
    std::cin >> number1 >> number2;
    if (number1 == 0) {
        std::cerr << "Error 1: Can't be zero." << std::endl;
        return 1;
    }
    std::cout << "The second is a multiple of the first? " << (multiple(number1, number2) ? "true" : "false") << std::endl;
    return 0;
}

bool
multiple(int number1, int number2)
{
    assert(number1 != 0);
    return (number2 % number1) == 0;
}

