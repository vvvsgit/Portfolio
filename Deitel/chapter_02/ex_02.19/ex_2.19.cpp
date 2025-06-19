#include <iostream>

int
main()
{
    std::cout << "\nInput three different integers: ";
    int integer1, integer2, integer3;
    std::cin >> integer1 >> integer2 >> integer3;
    if (integer1 == integer2) {
        std::cout << "Error 1: Different integers i said!\n" << std::endl;
        return 1;
    }
    if (integer1 == integer3) {
        std::cout << "Error 1: Different integers i said!\n" << std::endl;
        return 1;
    }
    if (integer2 == integer3) {
        std::cout << "Error 1: Different integers i said!\n" << std::endl;
        return 1;
    }

    int sum = integer1 + integer2 + integer3;
    std::cout << "Sum is " << sum << std::endl;
    
    int average = sum / 3;
    std::cout << "Average is " << average << std::endl;

    int product = integer1 * integer2 * integer3;
    std::cout << "Product is " << product << std::endl;

    int smallest = integer1;
    if (smallest > integer2) {
        smallest = integer2;
    }
    if (smallest > integer3) {
        smallest = integer3;
    }
    std::cout << "Smallest is " << smallest << std::endl;

    int largest = integer1;
    if (largest < integer2) {
        largest = integer2;
    }
    if (largest < integer3) {
        largest = integer3;
    }
    std::cout << "Largest is " << largest << std::endl;

    std::cout << std::endl;
    return 0;
}

