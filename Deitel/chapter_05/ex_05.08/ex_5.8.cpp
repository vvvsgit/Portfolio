#include <iostream>

int
main()
{
    std::cout << "\nEnter quantity: ";
    int quantity;
    std::cin >> quantity;
    if (quantity < 0) {
        std::cerr << "\nError 1: Not a quantity." << std::endl;
        return 1;
    }
    int smallest = 2147483647;
    for (int i = 0; i < quantity; ++i) {
        std::cout << "Enter " << quantity << " integers to find the smallest: ";
        int integers;
        std::cin >> integers;
        if (integers < smallest) {
            smallest = integers;
        }
    }
    std::cout << "The smallest is " << smallest << std::endl;
    return 0;
}

