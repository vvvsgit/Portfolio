#include <iostream>

int
main()
{
    std::cout << "\nEnter radius of a circle as an integer: ";
    int radius;
    std::cin >> radius;
    if (radius <=0) {
        std::cerr << "Error 1: invalid value.\n" << std::endl;
        return 1;
    }

    std::cout << "Diameter is " << 2 * radius << std::endl;
    std::cout << "Circumference is " << 2 * 3.14159 * radius << std::endl;
    std::cout << "Area is " << 3.14159 * radius * radius << std::endl;

    return 0;
}

