#include <iostream>

int
main()
{
    int counter = 0;
    int firstLargest = -2147483648;
    int secondLargest = firstLargest;
    std::cout << "\nEnter 10 numbers to find two largest of them." << std::endl;
    while (counter < 10) {
        std::cout << "Enter number: ";
        int number;
        std::cin >> number;
        if (firstLargest <= number) {
            secondLargest = firstLargest;
            firstLargest = number;
        }
        ++counter;
    }
    std::cout << "The first largest is " << firstLargest << std::endl;
    std::cout << "The second largest is " << secondLargest << std::endl;
    return 0;
}

