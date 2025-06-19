#include <iostream>
#include <iomanip>

int
main()
{
    std::cout << "\nEnter hours worked (negative to end): ";
    int hours;
    std::cin >> hours;
    while (hours >= 0) {
        std::cout << "Enter hourly rate of the worker ($00.00): ";
        double rate;
        std::cin >> rate;
        if (rate < 0) {
            std::cerr << "\nError 1: Can't." << std::endl;
            return 1;
        }
        double salary = rate * hours;
        if (hours > 40) {
            salary += (hours - 40) * rate * 0.5;
        }
        std::cout << "Salary is " << std::setprecision(2) << std::fixed << salary << std::endl;
        std::cout << "\nEnter hours worked (negative to end): ";
        std::cin >> hours;
    }
    return 0;
}

