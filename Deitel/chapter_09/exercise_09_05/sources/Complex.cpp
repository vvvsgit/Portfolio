#include "headers/Complex.hpp"

#include <iostream>

Complex::Complex(const double realPart, const double imaginaryPart)
    : real_(realPart),
      imaginary_(imaginaryPart)
{
}

double
Complex::getReal() const
{
    return real_;
}

double
Complex::getImaginary() const
{
    return imaginary_;
}

Complex
Complex::adding (const Complex& right)
{
    Complex result(getReal() + right.getReal(),
                   getImaginary() + right.getImaginary());
    return result;
}

Complex
Complex::subtracting (const Complex& right)
{
    Complex result(getReal() - right.getReal(),
                   getImaginary() - right.getImaginary());
    return result;
}

void
Complex::print()
{
    std::cout << '(' << getReal() << ", " << getImaginary() << ')' << std::endl;
}

