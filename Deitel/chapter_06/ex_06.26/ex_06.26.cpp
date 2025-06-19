#include <iostream>
#include <cmath>

int timeInSeconds(int, int, int);

int
main()
{
    int hour, minute, second;
    std::cout << "\nEnter time (hh mm ss): ";
    std::cin >> hour >> minute >> second;
    int time1 = timeInSeconds(hour, minute, second);
    std::cout << "\nEnter time (hh mm ss): ";
    std::cin >> hour >> minute >> second;
    int time2 = timeInSeconds(hour, minute, second);
    int time3 = abs(time1 - time2);
    std::cout << "Between them is " << time3 / 3600 << ':' << time3 % 3600 / 60 << ':' << 3600 % 60 << std::endl;
    std::cout << std::endl;
    return 0;
}

int
timeInSeconds(int hour, int minute, int second)
{
    if (hour < 0 || hour > 23) {
        std::cerr << "\nError 1: Wrong hours." << std::endl;
        ::exit(1);
    }
    if (minute < 0 || minute > 59) {
        std::cerr << "\nError 2: Wrong minute." << std::endl;
        ::exit(2);
    }
    if (second < 0 || second > 59) {
        std::cerr << "\nError 3: Wrong second." << std::endl;
        ::exit(3);
    }
    if (hour > 11) {
        hour -= 12;
    }
    return (hour * 60 + minute) * 60 + second;
}

