#include <iostream>
#include <iomanip>

double celsius(double);
double fahrenheit(double);

int
main()
{
    std::cout << "\nCelsius into fahrenheit:" << std::endl;
    for (int i = 0; i <= 100; ++i) {
        std::cout << i << " = " << fahrenheit(i);
        std::cout << (i % 5 == 0 ? '\n' : '\t');
    }
    std::cout << std::endl;
    std::cout << "\nFahrenheit into celsius:" << std::endl;
    for (int i = 32; i <= 212; ++i) {
        std::cout << i << " = " << std::setprecision(3) << std::fixed << celsius(i);
        std::cout << (i % 5 == 0 ? '\n' : '\t');
    }
    std::cout << std::endl;
    return 0;
}

double
celsius(double fahrenheit)
{
    return (fahrenheit - 32) * 5 / 9;
}

double
fahrenheit(double celsius)
{
    return celsius * 9 / 5 + 32;
}

