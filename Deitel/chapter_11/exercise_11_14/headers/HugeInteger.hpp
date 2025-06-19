#ifndef __HUGE_INTEGER_HPP__
#define __HUGE_INTEGER_HPP__

#include <string>
#include <iostream>

const int SIZE = 40;

class HugeInteger
{
    friend std::ostream& operator<<(std::ostream& output, const HugeInteger& integer);
    friend std::istream& operator<<(std::istream& input, HugeInteger& integer);
public:
    HugeInteger();
    HugeInteger(const char* integer);
    HugeInteger(const long integer);

    void setHugeInteger(const std::string& integer);

    HugeInteger operator+(const HugeInteger& right);
    HugeInteger operator-(const HugeInteger& right);

    bool operator==(const HugeInteger& right);
    bool operator!=(const HugeInteger& right);
    bool operator>(const HugeInteger& right);
    bool operator<(const HugeInteger& right);
    bool operator>=(const HugeInteger& right);
    bool operator<=(const HugeInteger& right);

    bool isEmpty() const;

private:
    char digits_[SIZE + 1];
};

#endif

