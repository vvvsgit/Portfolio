#include <iostream>
#include <cassert>

bool perfect(int);

int
main()
{
    std::cout << std::endl;
    for (int i = 1; i < 10000; ++i) {
        if (perfect(i)) {
            std::cout << i << std::endl;
        }
        if (i % 10000 == 0) {
            std::cout << '\t' << i << std::endl;
        }
    }
    std::cout << std::endl;
    return 0;
}

bool
perfect(int number)
{
    assert(number > 0);
    if (number % 2 == 1) {
        return false;
    }
    int perfect = 3 + number / 2;
    for (int i = 3; i < number / 2; ++i) {
        if (number % i == 0) {
            perfect += i;
        }
    }
    return perfect == number;
}

