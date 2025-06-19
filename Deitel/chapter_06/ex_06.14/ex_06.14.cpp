#include <iostream>
#include <cmath>

double roundToInteger(double);
double roundToTenths(double);
double roundToHundredths(double);
double roundToThousandths(double);
double roundToTenThousandths(double);

int
main()
{
    std::cout << "\nEnter number: ";
    double number;
    std::cin >> number;
    std::cout << std::endl;
    std::cout << number << std::endl;
    std::cout << roundToInteger(number) << std::endl;
    std::cout << roundToTenths(number) << std::endl;
    std::cout << roundToHundredths(number) << std::endl;
    std::cout << roundToThousandths(number) << std::endl;
    std::cout << roundToTenThousandths(number) << std::endl;
    std::cout << std::endl;

    return 0;
}

double
roundToInteger(double number) {
    return floor(number * 1 + 0.5) / 1;
}

double
roundToTenths(double number) {
    return floor(number * 10 + 0.5) / 10;
}

double
roundToHundredths(double number) {
    return floor(number * 100 + 0.5) / 100;
}

double
roundToThousandths(double number) {
    return floor(number * 1000 + 0.5) / 1000;
}

double
roundToTenThousandths(double number) {
    return floor(number * 10000 + 0.5) / 10000;
}

