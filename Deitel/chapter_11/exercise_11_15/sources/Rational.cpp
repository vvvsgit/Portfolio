#include "headers/Rational.hpp"

#include <iostream>
#include <cassert>
#include <cmath>

int greatestCommonDivisor(int number1, int number2);

Rational::Rational(const int numerator, const int denominator)
{
    setNumber(numerator, denominator);
}

void
Rational::setNumber(int numerator, int denominator)
{
    assert(0 != denominator);

    if (0 == numerator) {
        numerator_ = 0;
        denominator_ = denominator;
        return;
    }

    int gcd = greatestCommonDivisor(numerator, denominator);
    if (denominator < 0) {
        denominator = -denominator;
        numerator = -numerator;
    }
    numerator_ = numerator / gcd;
    denominator_ = denominator / gcd;
}

int
Rational::getNumerator() const
{
    return numerator_;
}

int
Rational::getDenominator() const
{
    return denominator_;
}

Rational
Rational::operator+(const Rational& right) const
{
    return Rational(getNumerator() * right.getDenominator() + right.getNumerator() * getDenominator(), getDenominator() * right.getDenominator());
}

Rational
Rational::operator-(const Rational& right) const
{
    return Rational(getNumerator() * right.getDenominator() - right.getNumerator() * getDenominator(), getDenominator() * right.getDenominator());
}

Rational
Rational::operator*(const Rational& right) const
{
    return Rational(getNumerator() * right.getNumerator(), getDenominator() * right.getDenominator());
}

Rational
Rational::operator/(const Rational& right) const
{
    return Rational(getNumerator() * right.getDenominator(), getDenominator() * right.getNumerator());
}

bool
Rational::operator==(const Rational& right) const
{
    return numerator_ == right.numerator_ && denominator_ == right.denominator_;
}

bool
Rational::operator!=(const Rational& right) const
{
    return !(*this == right);
}

bool
Rational::operator>(const Rational& right) const
{
    return numerator_ * right.denominator_ > right.numerator_ * denominator_;
}

bool
Rational::operator<(const Rational& right) const
{
    return numerator_ * right.denominator_ < right.numerator_ * denominator_;
}

bool
Rational::operator>=(const Rational& right) const
{
    return !(*this < right);
}

bool
Rational::operator<=(const Rational& right) const
{
    return !(*this > right);
}

int
greatestCommonDivisor(int number1, int number2)
{
    number1 = std::abs(number1);
    number2 = std::abs(number2);
    while (number1 != number2) {
        if (number1 > number2) {
            number1 -= number2;
        } else { 
            number2 -= number1;
        }
    }
    return number1;
}

std::istream&
operator>>(std::istream& input, Rational& number)
{
    input >> number.numerator_ >> number.denominator_;
    return input;
}

std::ostream&
operator<<(std::ostream& output, const Rational& number)
{
    if (0 == number.getNumerator())
    {
        output << 0 << std::endl;
        return output;
    }
    output << number.getNumerator() << '/' << number.getDenominator() << std::endl;
    return output;
}


