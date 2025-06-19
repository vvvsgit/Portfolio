#include <iostream>

int
main()
{
    int product = 1;
    for (int i = 1; i <= 15; i += 2) {
        product *= i;
    }
    std::cout << "\nProduct of odd numbers between 1-15 is " << product << std::endl;
    return 0;
}

