#ifndef __PRIME_SIEVE_HPP__
#define __PRIME_SIEVE_HPP__

#include <bitset>
#include <iostream>
#include <iomanip>
#include <cmath>

const int SIZE = 1024;

void sieveEratosthenes(std::bitset<SIZE>& sieve);
void printPrimes(const std::bitset<SIZE>& sieve);
void tryPrimes(const std::bitset<SIZE>& sieve, int value);

#endif

