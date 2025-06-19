#include <iostream>

inline double circleArea(double);

int
main()
{
    std::cout << "\nEnter radius: ";
    double radius;
    std::cin >> radius;
    if (radius < 0) {
        std::cerr << "\nError 1: Wrong radius." << std::endl;
        return 1;
    }
    std::cout << "The area of the circle is " << circleArea(radius) << std::endl;
    std::cout << std::endl;
    return 0;
}

inline double
circleArea(double radius)
{
    return 2 * 3.14159 * radius;
}

