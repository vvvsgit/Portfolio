#include <iostream>

int
main()
{
    srand(time(0));
    std::cout << '\n' << rand() % 2 + 1 << std::endl;
    std::cout << rand() % 100 + 1 << std::endl;
    std::cout << rand() % 10 << std::endl;
    std::cout << rand() % 113 + 1000 << std::endl;
    std::cout << rand() % 1 + 1 << std::endl;
    std::cout << rand() % 9 + 3 << '\n' << std::endl;
    return 0;
}

