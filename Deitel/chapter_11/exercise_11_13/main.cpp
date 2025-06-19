#include "headers/Complex.hpp"

#include <iostream>

int
main()
{
    Complex x;
    Complex y(4.3, 8.2);
    Complex z(3.3, 1.1);

    std::cout << "x: " << x << "\ny: " << y << "\nz: " << z;

    x = y + z;
    std::cout << "\n\nx = y + z:" << std::endl;
    std::cout << x << " = " << y << " + " << z;

    x = y - z;
    std::cout << "\n\nx = y - z:" << std::endl;
    std::cout << x << " = " << y << " - " << z << std::endl;

    return 0;
}

