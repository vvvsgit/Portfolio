#include <iostream>
#include <iomanip>

int
main()
{
    std::cout << "\nEnter sales in dollars (negative to end): ";
    double sales;
    std::cin >> sales;
    while (sales >= 0) {
        std::cout << "\nSalary is: $" << std::setprecision(2) << std::fixed << sales * 0.09 + 200 << std::endl;
        std::cout << "\nEnter sales in dollars (negative to end): ";
        std::cin >> sales;
    }
    return 0;
}

