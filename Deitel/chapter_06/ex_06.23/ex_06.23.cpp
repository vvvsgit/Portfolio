#include <iostream>
#include <cassert>

void square(int, char);

int
main()
{
    std::cout << "\nEnter number: ";
    int number;
    std::cin >> number;
    if (number < 0) {
        std::cerr << "\nError 1: Wrong side." << std::endl;
        return 1;
    }
    std::cout << "Enter character: ";
    char fill;
    std::cin >> fill;
    std::cout << std::endl;
    square(number, fill);
    std::cout << std::endl;
    return 0;
}

void
square(int side, char fillCharacter)
{
    assert(side >= 0);
    for (int i = 0; i < side; ++i) {
        for (int j = 0; j < side; ++j) {
            std::cout << fillCharacter;
        }
        std::cout << std::endl;
    }
}

