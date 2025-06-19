#include <iostream>
#include <cmath>

bool prime(int);

int
main()
{
    for (int i = 1; i < 10000; ++i) {
        if (prime(i)) {
            std::cout << i << std::endl;
        }
    }
    return 0;
}

bool
prime(int number)
{
    if ((number % 2 == 0) && number != 2) {
        return false;
    }
    for (int i = 3; i <= sqrt(number); ++i) {
        if (number % i == 0) {
            return false;
        }
    }
    return true;
}

