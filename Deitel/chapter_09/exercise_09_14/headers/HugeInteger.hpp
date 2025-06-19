#ifndef __HUGE_INTEGER_HPP__
#define __HUGE_INTEGER_HPP__

#include <string>

const int SIZE = 40;

class HugeInteger
{
public:
    HugeInteger();
    HugeInteger(const char* integer);

    void setHugeInteger(const std::string& integer);

    void input(const std::string& integer);
    void output();

    HugeInteger add(const HugeInteger& right);
    HugeInteger subtract(const HugeInteger& right);

    bool isEqualTo(const HugeInteger& right);
    bool isNotEqualTo(const HugeInteger& right);
    bool isGreaterThan(const HugeInteger& right);
    bool isLessThan(const HugeInteger& right);
    bool isGreaterThanOrEqualTo(const HugeInteger& right);
    bool isLessThanOrEqualTo(const HugeInteger& right);
    bool isZero();

private:
    char digits_[SIZE + 1];
};

#endif

