#include <iostream>
#include <cmath>

double hypotenuse(double, double);

int
main()
{
    for (int i = 1; i <= 3; ++i) {
        double side1, side2;
        std::cout << "Side 1 is : ";
        std::cin >> side1;
        std::cout << "Side 2 is : ";
        std::cin >> side2;
        std::cout << "Hypotenuse of " << side1 << " and " << side2 << " is " << hypotenuse(side1, side2);
        std::cout << std::endl;
        std::cout << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

double
hypotenuse(double side1, double side2)
{
    return sqrt(side1 * side1 + side2 * side2);
}

