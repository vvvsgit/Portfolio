#include <iostream>
#include <cassert>

int qualityPoints(int);

int
main()
{
    std::cout << "\nEnter student's average: ";
    int average;
    std::cin >> average;
    if (average < 0 || average > 100) {
        std::cerr << "\nError 1: Wrong average." << std::endl;
        return 1;
    }
    std::cout << "Your point is " << qualityPoints(average) << std::endl;
    std::cout << std::endl;
    return 0;
}

int
qualityPoints(int average)
{
    assert(average >= 0 && average <= 100);
    if (average >= 90 && average <= 100) {
        return 4;
    } else if (average >= 80) {
        return 3;
    } else if (average >= 70) {
        return 2;
    } else if (average >= 60) {
        return 1;
    }
    return 0;
}

