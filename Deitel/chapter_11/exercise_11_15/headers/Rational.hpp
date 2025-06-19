#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

#include <iostream>

class Rational
{
    friend std::istream& operator>>(std::istream& input, Rational& number);
    friend std::ostream& operator<<(std::ostream& output, const Rational& number);

public:
    Rational(const int numerator = 1, const int denominator = 1);

    void setNumber(int numerator, int denominator);
    int getNumerator() const;
    int getDenominator() const;

    Rational operator+(const Rational& right) const;
    Rational operator-(const Rational& right) const;
    Rational operator*(const Rational& right) const;
    Rational operator/(const Rational& right) const;

    bool operator==(const Rational& right) const;
    bool operator!=(const Rational& right) const;
    bool operator>(const Rational& right) const;
    bool operator<(const Rational& right) const;
    bool operator>=(const Rational& right) const;
    bool operator<=(const Rational& right) const;

private:
    int numerator_;
    int denominator_;
};

#endif

