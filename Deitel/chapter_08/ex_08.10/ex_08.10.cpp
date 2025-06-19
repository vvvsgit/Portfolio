#include <iostream>

int
main()
{
    std::cout << std::endl;

    long int value1 = 200000;
    long int value2;

    long int *longPtr;

    longPtr = &value1;

    std::cout << *longPtr << std::endl;

    value2 = *longPtr;

    std::cout << value2 << std::endl;

    std::cout << &value1 << std::endl;

    std::cout << longPtr << std::endl;

    std::cout << std::endl;
    return 0;
}

