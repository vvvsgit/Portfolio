#include <iostream>

int
main()
{
    std::cout << "\nEnter nunber 1-30: ";
    int number;
    std::cin >> number;
    if (number < 1 || number > 30) {
        std::cerr << "\nError 1: not in range." << std::endl;
        return 1;
    }
    for (int i = 0; i < number; ++i) {
        std::cout << '*';
    }
    std::cout << std::endl;
    return 0;
}

