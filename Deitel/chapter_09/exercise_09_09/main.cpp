#include "headers/DateAndTime.hpp"

#include <iostream>


int main()
{
    std::cout << std::endl;

    DateAndTime timeTick(23, 58, 57, 31, 12, 1999);
    for (int i = 0; i < 64; ++i) {
        timeTick.tick();
        timeTick.printUniversal();
        std::cout << std::endl;
        timeTick.printStandard();
        std::cout << std::endl;
        std::cout << std::endl;
    }

    std::cout << std::endl;
    return 0;
}

