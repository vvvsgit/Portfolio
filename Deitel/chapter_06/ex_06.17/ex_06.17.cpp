#include <iostream>

int
main()
{
    srand(time(0));
    std::cout << '\n' << (rand() % 5 + 1) * 2 << std::endl;
    std::cout << (rand() % 5 + 1) * 2 + 1 << std::endl;
    std::cout << ((rand() % 5 + 1) * 2 + 1) * 2 << std::endl;
    std::cout << std::endl;
    return 0;
}

