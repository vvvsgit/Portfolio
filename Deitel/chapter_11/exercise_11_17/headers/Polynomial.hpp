#ifndef __POLYNOMIAL_HPP__
#define __POLYNOMIAL_HPP__

#include "headers/Term.hpp"

#include <iostream>


class Polynomial
{
    friend std::ostream& operator<<(std::ostream& output, const Polynomial& polynomial);

public:
    Polynomial(const Term& term);
    Polynomial(const Term* terms, const size_t size);
    Polynomial(const Polynomial& copy);
    ~Polynomial();

    const Polynomial& operator=(const Polynomial& right);

    Polynomial operator+(const Polynomial& right) const;
    Polynomial operator-(const Polynomial& right) const;

    Polynomial operator+=(const Polynomial& right);
    Polynomial operator-=(const Polynomial& right);

    void insert(const Term& term);

private:
    size_t size_;
    Term* termPtr_;
};

#endif

