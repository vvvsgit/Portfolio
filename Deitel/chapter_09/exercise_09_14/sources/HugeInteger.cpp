#include "headers/HugeInteger.hpp"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cassert>

HugeInteger::HugeInteger()
{
    for (int i = 0; i < SIZE; ++i) {
        digits_[i] = '0';
    }
    digits_[SIZE] = '\0';
}

HugeInteger::HugeInteger(const char* integer)
{
    for (int i = 0; i < SIZE; ++i) {
        digits_[i] = '0';
    }
    digits_[SIZE] = '\0';
    setHugeInteger(integer);
}

void
HugeInteger::setHugeInteger(const std::string& integer)
{
    const int length = integer.length();
    assert(length < SIZE);

    for (int i = 0; i < length; ++i) {
        assert('0' <= integer[i] && integer[i] <= '9');
    }
    for (int i = SIZE - length, j = 0; i < SIZE; ++i, ++j) {
        digits_[i] = integer[j];
    }
}

void
HugeInteger::input(const std::string& integer)
{
    setHugeInteger(integer);
}

void
HugeInteger::output()
{
    if (isZero()) {
        std::cout << '0';
        return;
    }
    int startIndex;
    for (startIndex = 0; startIndex < SIZE; ++startIndex) {
        if (digits_[startIndex] != '0') {
            break;
        }
    }
    for (; startIndex < SIZE; ++startIndex) {
        std::cout << digits_[startIndex];
    }
}

HugeInteger
HugeInteger::add(const HugeInteger& right)
{
    HugeInteger result;

    int nextDigit = 0;
    for (int i = SIZE - 1; i >= 0; --i) {
        const int digitSum = (digits_[i] - '0') + (right.digits_[i] - '0') + nextDigit;
        result.digits_[i] = digitSum % 10 + '0';
        nextDigit = digitSum / 10;
    }

    return result;
}

HugeInteger
HugeInteger::subtract(const HugeInteger& right)
{
    if (this->isLessThan(right)) { assert(0); }

    HugeInteger result;

    bool borrowed = false;
    for (int i = SIZE - 1; i >= 0; --i) {
        int nextDigit = digits_[i] - '0';
        if (borrowed) {
            if (0 == nextDigit) {
                nextDigit = 9;
            } else {
                nextDigit -= 1;
                borrowed = false;
            }
        }
        if (nextDigit + '0' < right.digits_[i]) {
            borrowed = true;
            nextDigit += 10;
        }
        result.digits_[i] = (nextDigit - (right.digits_[i] - '0') + '0');
    }

    return result;
}

bool
HugeInteger::isEqualTo(const HugeInteger& right)
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits_[i] != right.digits_[i]) {
            return false;
        }
    }
    return true;
}

bool
HugeInteger::isNotEqualTo(const HugeInteger& right)
{
    return !isEqualTo(right);
}

bool
HugeInteger::isGreaterThan(const HugeInteger& right)
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits_[i] > right.digits_[i]) {
            return true;
        }
        if (digits_[i] < right.digits_[i]) {
            return false;
        }
    }
    return false;
}

bool
HugeInteger::isLessThan(const HugeInteger& right)
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits_[i] < right.digits_[i]) {
            return true;
        }
        if (digits_[i] > right.digits_[i]) {
            return false;
        }
    }
    return false;
}

bool
HugeInteger::isGreaterThanOrEqualTo(const HugeInteger& right)
{
    return !isLessThan(right);
}

bool
HugeInteger::isLessThanOrEqualTo(const HugeInteger& right)
{
    return !isGreaterThan(right);
}

bool
HugeInteger::isZero()
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits_[i] != '0') {
            return false;
        }
    }
    return true;
}

