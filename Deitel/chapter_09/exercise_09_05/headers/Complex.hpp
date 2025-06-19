#ifndef __COMPLEX_HPP__
#define __COMPLEX_HPP__

class Complex
{
public:
    Complex(const double realPart = 1.0, const double imaginaryPart = 1.0);
    
    double getReal() const;
    double getImaginary() const;

    Complex adding (const Complex& right);
    Complex subtracting (const Complex& right);
    void print();

private:
    double real_;
    double imaginary_;
};

#endif

