#include <iostream>

int
main()
{
    int counter = 0;
    int power = 1;
    std::cout << std::endl;
    while (counter < 35) {
        std::cout << power << std::endl;
        power *= 2;
        ++counter;
    }
    std::cout << std::endl;
    return 0;
}

