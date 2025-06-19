#include "headers/Time.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    Time timeTick(23, 58, 57);
    for (int i = 0; i < 64; ++i) {
        timeTick.tick();
        timeTick.printUniversal();
        std::cout << std::endl;
        timeTick.printStandard();
        std::cout << std::endl;
        std::cout << std::endl;
    }

    return 0;
}

