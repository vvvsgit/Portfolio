#include "headers/Term.hpp"

#include <cassert>

Term::Term(const int coefficient, const int exponent)
{
    setCoefficient(coefficient);
    setExponent(exponent);
}

void
Term::setCoefficient(const int coefficient)
{
    coefficient_ = coefficient;
}

void
Term::setExponent(const int exponent)
{
    assert(exponent >= 0);
    exponent_ = exponent;
}

int
Term::getCoefficient() const
{
    return coefficient_;
}

int
Term::getExponent() const
{
    return exponent_;
}

