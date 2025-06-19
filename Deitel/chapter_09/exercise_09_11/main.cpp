#include "headers/Rectangle.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    Rectangle one(0.0, 21.0);
    std::cout << "Perimeter is " << one.perimeter() << std::endl;
    std::cout << "Area is " << one.area() << std::endl;
    std::cout << std::endl;

    Rectangle two(2.0, 11.0);
    std::cout << "Perimeter is " << two.perimeter() << std::endl;
    std::cout << "Area is " << two.area() << std::endl;

    std::cout << std::endl;
    
    return 0;
}

