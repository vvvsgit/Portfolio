#include <iostream>
#include <cmath>

int
main()
{
    int attemps = 0;
    int triples = 0;
    for (int side1 = 3; side1 <= 340; ++side1) {
        int squareSide1 = side1 * side1;
        for (int side2 = side1 + 1; side2 <= 483; ++side2) {
            int squareHypotenuse = squareSide1 + side2 * side2;
            int hypotenuse = std::sqrt(squareHypotenuse);
            int hypotenuseSquare = hypotenuse * hypotenuse;
            if (hypotenuseSquare == squareHypotenuse) {
                std::cout << side1 << " * " << side1 << " + "
                          << side2 << " * " << side2 << " = "
                          << hypotenuse << " * " << hypotenuse 
                          << std::endl;
                ++triples;
            }
            ++attemps;
        }
    }
    std::cout << "\nAttemps - " << attemps << std::endl;
    std::cout << "\nTriples - " << triples << std::endl;
    std::cout << std::endl;
    return 0;
}

