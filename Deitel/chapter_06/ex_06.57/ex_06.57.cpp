#include <iostream>

int i = 5;

int
main()
{
    std::cout << std::endl;
    for (int i = 0; i < ::i; ++i) {
        std::cout << i << std::endl;
    }
    std::cout << std::endl;
    return 0;
}

