#include <iostream>
#include <cmath>

double distance(double, double, double, double);

int
main()
{
    std::cout << "\nEnter two cordinates to determine distance between:" << std::endl;
    double x1, y1, x2, y2;
    std::cout << "x1 = ";
    std::cin >> x1;
    std::cout << "y1 = ";
    std::cin >> y1;
    std::cout << "x2 = ";
    std::cin >> x2;
    std::cout << "y2 = ";
    std::cin >> y2;
    std::cout << "\nDistance is " << distance(x1, y1, x2, y2) << std::endl;
    std::cout << std::endl;
    return 0;
}

double
distance(double x1, double y1, double x2, double y2)
{
    return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}

