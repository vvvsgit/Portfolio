#include "headers/Date.hpp"

#include <iostream>


int main()
{
    std::cout << std::endl;

    Date date1(0, 0, 0);
    date1.print();
    std::cout << std::endl;

    Date date2(29, 2, 1600);
    date2.print();
    std::cout << std::endl;

    Date date3(28, 11, 1999);
    date3.print();
    for (int i = 0; i < 35; ++i) {
        date3.nextDay();
        date3.print();
    }

    std::cout << std::endl;
    return 0;
}

