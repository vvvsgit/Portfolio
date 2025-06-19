#include <iostream>

int
main()
{
    std::cout << "\nEnter five integers: ";
    int integer1, integer2, integer3, integer4, integer5;
    std::cin >> integer1 >> integer2 >> integer3 >> integer4 >> integer5;

    int smallest = integer1;
    if (smallest > integer2) { smallest = integer2; }
    if (smallest > integer3) { smallest = integer3; }
    if (smallest > integer4) { smallest = integer4; }
    if (smallest > integer5) { smallest = integer5; }
    std::cout << "Smallest is " << smallest << std::endl;

    int largest = integer1;
    if (largest < integer2) { largest = integer2; }
    if (largest < integer3) { largest = integer3; }
    if (largest < integer4) { largest = integer4; }
    if (largest < integer5) { largest = integer5; }
    std::cout << "Largest is " << largest << std::endl;

    return 0;
}

