#include <iostream>

int
main()
{
    int sum = 0;
    int counter = -1;
    int integers = 0;
    while (integers != 9999) {
        sum += integers;
        std::cout << "Enter integers to find average (sentinel is 9999): ";
        std::cin >> integers;
        ++counter;
    }
    if (0 == counter) {
        std::cout << "Average is " << sum << std::endl;
        return 0;
    }
    std::cout << "Average is " << sum / counter << std::endl;
    return 0;
}

