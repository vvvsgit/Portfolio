#include "headers/Time.hpp"

#include <iostream>


int
main()
{
    std::cout << std::endl;

    Time time(102, 101, 100);

    std::cout << "\nWith all values specified as invalid\n ";
    time.printUniversal();
    std::cout << "\n ";
    time.printStandard();
    std::cout << std::endl;

    std::cout << std::endl;

    return 0;
}

