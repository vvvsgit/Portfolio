#include <iostream>
#include <cmath>

double calculateCharges(double);

int
main()
{
    std::cout << "\nEnter hours to determine charges." << std::endl;
    std::cout << "\nCar\tHours\tCharge\n";
    int cars = 3;
    double totalCharges = 0;
    double totalHours = 0;
    for (int i = 1; i <= cars; ++i) {
        std::cout << i << '\t';
        double hours;
        std::cin >> hours;
        totalHours += hours;
        double charges = calculateCharges(hours);
        std::cout << '\t' << charges << std::endl;
        totalCharges += charges;
    }
    std::cout << "TOTAL\t" << totalHours << '\t' << totalCharges << std::endl;
    return 0;
}

double
calculateCharges(double hours) {
    if (hours < 0 || hours > 24) {
        std::cerr << "\nError 1: Wrong hours." << std::endl;
        ::exit(1);
    }
    if (24 == ceil(hours)) {
        return 10.0;
    }
    if (3 >= ceil(hours)) {
        return 2.0;
    }
    return 2.0 + ((ceil(hours) - 3) * 0.5);
}

