#include <iostream>

int factorialVisualization(int);

int
main()
{
    std::cout << "\nEnter number: ";
    int number;
    std::cin >> number;
    if (number < 0) {
        std::cerr << "\nError 1: Wrong number." << std::endl;
        return 1;
    }
    factorialVisualization(number);
    std::cout << std::endl;
    return 0;
}

int
factorialVisualization(int number)
{
    static int intend = 0;
    if (number == 0) {
        std::cout << number << "! = " << number << std::endl;
        return 1;
    }
    if (number == 1) {
        for (int i = 0; i < intend; ++i) {
            std::cout << "  ";
        }
        std::cout << number << "! = " << number << std::endl;
        return 1;
    }
    for (int i = 0; i < intend; ++i) {
        std::cout << "  ";
    }
    std::cout << number << "! = " << number << " * " << number - 1 << '!' << std::endl;
    ++intend;
    int x = number * factorialVisualization(number - 1);
    --intend;
    for (int i = 0; i < intend; ++i) {
        std::cout << "  ";
    }
    std::cout << number << "! = " << x << std::endl;
    return x;
}

