#include <iostream>

int
main()
{
    std::cout << "\nEnter a binary nunber: ";
    int binary;
    std::cin >> binary;
    int decimal = 0;
    int power = 1;
    while (binary / 1 != 0) {
        int digit = binary % 10;
        if (1 == digit) {
        } else if (0 == digit) {
        } else {
            std::cerr << "\nError 1: None binary.\n" << std::endl;
            return 1;
        }
        decimal += binary % 10 * power;
        power *= 2;
        binary /= 10;
    }
    std::cout << "The decimal is " << decimal << std::endl;
    return 0;
}

