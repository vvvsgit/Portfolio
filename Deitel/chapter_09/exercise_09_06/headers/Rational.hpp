#ifndef __RATIONAL_HPP__
#define __RATIONAL_HPP__

class Rational
{
public:
    Rational(const int numerator = 1, const int denominator = 1);

    void setNumber(int numerator, int denominator);
    int getNumerator() const;
    int getDenominator() const;

    Rational add(const Rational& right);
    Rational subtract(const Rational& right);
    Rational multiply(const Rational& right);
    Rational divid(const Rational& right);
    void print();
    void printFloat();

private:
    int numerator_;
    int denominator_;
};

#endif

