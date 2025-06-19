#include <iostream>

int
main()
{
    int counter = 0;
    int largest = -2147483648;
    std::cout << "\nEnter 10 numbers to find the largest of them." << std::endl;
    while (counter < 10) {
        std::cout << "Enter number: ";
        int number;
        std::cin >> number;
        if (largest < number) {
            largest = number;
        }
        ++counter;
    }
    std::cout << "The largest is " << largest << std::endl;
    return 0;
}

