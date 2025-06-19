#include "headers/Time.hpp"

#include <iostream>

int
main()
{
    std::cout << std::endl;

    Time t1;
    Time t3(10, 10, 10);
    Time t5(102, 101, 100);

    std::cout << "Constructed with defaulted argument: Current time\n ";
    t1.printUniversal();
    std::cout << "\n ";
    t1.printStandard();

    std::cout << "\n\nWith all values specified\n ";
    t3.printUniversal();
    std::cout << "\n ";
    t3.printStandard();

    std::cout << "\n\nWith all values specified as invalid\n ";
    t5.printUniversal();
    std::cout << "\n ";
    t5.printStandard();

    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}

