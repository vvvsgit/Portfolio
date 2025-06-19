#include "headers/Time.hpp"

#include <iostream>

int
main()
{
    Time t;

    t.setHour(18).setMinute(30).setSecond(22);

    std::cout << "Universal time: ";
    t.printUniversal();

    std::cout << "\nStandard time: ";
    t.printStandard();

    std::cout << "\n\nNew standard time: ";
    t.setTime(20, 20, 20).printStandard();

    std::cout << std::endl;

    return 0;
}

