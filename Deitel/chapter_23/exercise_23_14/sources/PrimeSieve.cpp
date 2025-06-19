#include "headers/PrimeSieve.hpp"

#include <iostream>

void 
sieveEratosthenes(std::bitset<SIZE>& sieve)
{
    sieve.flip();
    sieve.reset(0);
    sieve.reset(1);
    
    const int finalBit = std::sqrt(static_cast<double>(sieve.size())) + 1;
    
    for (int i = 2; i < finalBit; ++i) {
        if (sieve.test(i)) {
            for (int j = 2 * i; j < SIZE; j += i)
                sieve.reset(j);
        }
    }
}

void 
printPrimes(const std::bitset<SIZE>& sieve)
{
    std::cout << "The prime numbers in the range 2 to " << SIZE << " are:\n";
    
    for (int k = 2, counter = 1; k < SIZE; ++k) {
        if (sieve.test(k)) {
            std::cout << std::setw(5) << k;
            if (counter++ % 10 == 0)
            std::cout << std::endl;
        }
    }
    std::cout << std::endl;
}

void
tryPrimes(const std::bitset<SIZE>& sieve, int value)
{
    if (sieve[value]) {
        std::cout << value << " is a prime number" << std::endl;
        return;
    } 

    std::cout << value << " is not a prime number" << std::endl;
    std::cout << "The unique prime factorization of " << value << " is: ";
    const int finalBit = std::sqrt(static_cast<double>(value)) + 1;
    for (int i = 2; i < finalBit; ++i) {
        if (sieve.test(i)) {
            while (value % i == 0) {
                std::cout << i << " * ";
                value /= i;
            }
        }
    }
    std::cout << std::endl;
}

