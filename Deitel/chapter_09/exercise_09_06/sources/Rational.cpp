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
Rational::add(const Rational& right)
{
    const Rational result(getNumerator() * right.getDenominator() + right.getNumerator() * getDenominator(), getDenominator() * right.getDenominator());
    return result;
}

Rational
Rational::subtract(const Rational& right)
{
    const Rational result(getNumerator() * right.getDenominator() - right.getNumerator() * getDenominator(), getDenominator() * right.getDenominator());
    return result;
}

Rational
Rational::multiply(const Rational& right)
{
    const Rational result(getNumerator() * right.getNumerator(), getDenominator() * right.getDenominator());
    return result;
}

Rational
Rational::divid(const Rational& right)
{
    const Rational result(getNumerator() * right.getDenominator(), getDenominator() * right.getNumerator());
    return result;
}

void
Rational::print()
{
    if (0 == getNumerator())
    {
        std::cout << 0 << std::endl;
        return;
    }
    std::cout << getNumerator() << '/' << getDenominator() << std::endl;
}

void
Rational::printFloat()
{
    if (0 == getNumerator())
    {
        std::cout << 0 << std::endl;
        return;
    }
    std::cout << static_cast<float>(getNumerator()) / getDenominator() << std::endl;
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

