#include "headers/Complex.hpp" // Complex class definition

#include <iostream>

Complex::Complex(const double realPart, const double imaginaryPart)
    : real_(realPart)
    , imaginary_(imaginaryPart)
{
}

Complex
Complex::operator+(const Complex& right) const
{
    return Complex(real_ + right.real_, imaginary_ + right.imaginary_);
}

Complex
Complex::operator-(const Complex& right) const
{
    return Complex(real_ - right.real_, imaginary_ - right.imaginary_);
}

Complex
Complex::operator*(const Complex& right) const
{
    return Complex(real_ * right.real_ - imaginary_ * right.imaginary_,
                   real_ * right.imaginary_ + imaginary_ * right.real_);
}

bool
Complex::operator==(const Complex& right) const
{
    return real_ == right.real_ && imaginary_ == right.imaginary_;
}

bool
Complex::operator!=(const Complex& right) const
{
    return !(*this == right);
}

std::istream&
operator>>(std::istream& input, Complex& number)
{
    input >> number.real_ >> number.imaginary_;
    return input;
}

std::ostream&
operator<<(std::ostream& output, const Complex& number)
{
    output << '(' << number.real_ << ", " << number.imaginary_ << ')';
    return output;
}

