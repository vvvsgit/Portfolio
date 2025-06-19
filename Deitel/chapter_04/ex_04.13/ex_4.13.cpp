#include <iostream>

int
main()
{
    std::cout << "\nEnter the miles used (negative to quit): ";
    int miles;
    std::cin >> miles;
    int tGal = 0, tMile = miles;
    while (miles >= 0)
    {
        std::cout << "Enter gallons: ";
        int gallons;
        std::cin >> gallons;
        tGal += gallons;
        if (gallons <= 0) {
            std::cerr << "Error 1: You are kidding right?\n" << std::endl;
            return 1;
        }
        double mpg = static_cast<double>(miles) / gallons;
        std::cout << "MPG this tankfull: " << mpg;
        std::cout << "\ntGal/tMiles = " << static_cast<double>(tMile) / tGal << std::endl;
        std::cout << "\nEnter the miles used (negative to quit): ";
        std::cin >> miles;
        tMile += miles;
    }
    
    return 0;
}

