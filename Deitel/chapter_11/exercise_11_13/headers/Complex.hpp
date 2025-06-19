#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

#include <iostream>

class Complex
{
    friend std::istream& operator>>(std::istream& input, Complex& number);
    friend std::ostream& operator<<(std::ostream& output, const Complex& number);

public:
    Complex(const double realPart = 0.0, const double imaginaryPart = 0.0);

    Complex operator+(const Complex& right) const;
    Complex operator-(const Complex& right) const;
    Complex operator*(const Complex& right) const;
    bool operator==(const Complex& right) const;
    bool operator!=(const Complex& right) const;

private:
    double real_;
    double imaginary_;
};

#endif

