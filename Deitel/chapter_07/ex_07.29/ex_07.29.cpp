#include <iostream>

int
main()
{
    std::cout << std::endl;

    const int SIZE = 10000;
    bool prime[SIZE];
    for (int i = 0; i < SIZE; ++i) {
        prime[i] = true;
    }
    
    for (int i = 2; i < SIZE; ++i) {
        for (int j = i + i; j < SIZE; j += i) {
            prime[j] = false;
        }
    }

    for (int i = 1; i < SIZE; ++i) {
        if (prime[i]) {
            std::cout << i << std::endl;
        }
    }

    std::cout << std::endl;
    return 0;
}

