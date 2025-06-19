#ifndef __TERM_HPP__
#define __TERM_HPP__

class Term
{
public:
    Term(const int coefficient = 1, const int exponent = 1);

    void setCoefficient(const int coefficient);
    void setExponent(const int exponent);
    int getCoefficient() const;
    int getExponent() const;

private:
    int coefficient_;
    int exponent_;
};

#endif

