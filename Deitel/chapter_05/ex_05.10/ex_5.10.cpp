#include <iostream>

int
main()
{
    int factorial = 1;
    for (int i = 1; i <= 5; ++i) {
        factorial *= i;
        std::cout << i << "! = " << factorial << std::endl;
    }
    return 0;
}

