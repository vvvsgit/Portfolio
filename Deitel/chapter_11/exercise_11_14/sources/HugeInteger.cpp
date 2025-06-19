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

HugeInteger::HugeInteger(long integer)
{
    int i = SIZE - 1;
    for (; integer != 0; --i) {
        digits_[i] = (integer % 10) + '0';
        integer /= 10;
    }
    for (--i; i >= 0; --i) {
        digits_[i] = '0';
    }
    digits_[SIZE] = '\0';
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

std::istream&
operator>>(std::istream& input, HugeInteger& integer)
{
    std::string newInteger;
    input >> newInteger;
    integer.setHugeInteger(newInteger);
    return input;
}

std::ostream& 
operator<<(std::ostream& output, const HugeInteger& integer)
{
    if (integer.isEmpty()) {
        output << '0';
        return output;
    }
    int startIndex;
    for (startIndex = 0; startIndex < SIZE; ++startIndex) {
        if (integer.digits_[startIndex] != '0') {
            break;
        }
    }
    for (; startIndex < SIZE; ++startIndex) {
        output << integer.digits_[startIndex];
    }

    return output;
}

HugeInteger
HugeInteger::operator+(const HugeInteger& right)
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
HugeInteger::operator-(const HugeInteger& right)
{
    if (*this < right) { assert(0); }

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
HugeInteger::operator==(const HugeInteger& right)
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits_[i] != right.digits_[i]) {
            return false;
        }
    }
    return true;
}

bool
HugeInteger::operator!=(const HugeInteger& right)
{
    return !(*this == right);
}

bool
HugeInteger::operator>(const HugeInteger& right)
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
HugeInteger::operator<(const HugeInteger& right)
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
HugeInteger::operator>=(const HugeInteger& right)
{
    return !(*this < right);
}

bool
HugeInteger::operator<=(const HugeInteger& right)
{
    return !(*this > right);
}

bool
HugeInteger::isEmpty() const
{
    for (int i = 0; i < SIZE; ++i) {
        if (digits_[i] != '0') {
            return false;
        }
    }
    return true;
}

