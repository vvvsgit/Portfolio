#include "headers/Polynomial.hpp"

Polynomial::Polynomial(const Term& term)
    : size_(1)
    , termPtr_(new Term[1])
{
    termPtr_[0] = term;
}

Polynomial::Polynomial(const Term* terms, const size_t size)
    : size_(size)
    , termPtr_(new Term[size])
{
    for (size_t i = 0; i < size; ++i) {
        termPtr_[i] = terms[i];
    }
}

Polynomial::Polynomial(const Polynomial& copy)
    : size_(copy.size_)
    , termPtr_(new Term[copy.size_])
{
    for (size_t i = 0; i < copy.size_; ++i) {
        termPtr_[i] = copy.termPtr_[i];
    }

}

Polynomial::~Polynomial()
{
    if (termPtr_ != NULL) {
        delete [] termPtr_;
        termPtr_ = NULL;
    }
}

const Polynomial&
Polynomial::operator=(const Polynomial& right)
{
    if (&right == this) return *this;

    if (right.size_ != size_) {
        size_ = right.size_;
        delete [] termPtr_;
        termPtr_ = new Term[size_];
    }
    for (size_t i = 0; i < size_; ++i) {
        termPtr_[i] = right.termPtr_[i];
    }
    return *this;
}

Polynomial
Polynomial::operator+(const Polynomial& right) const
{
    Polynomial result(*this);
    for (size_t i = 0; i < right.size_; ++i) {
        bool notInserted = true;
        for (size_t j = 0; j < size_; ++j) {
            if (result.termPtr_[j].getExponent() == right.termPtr_[i].getExponent()) {
                result.termPtr_[j].setCoefficient(result.termPtr_[j].getCoefficient() + right.termPtr_[i].getCoefficient());
                notInserted = false;
                break;
            }
        }
        if (notInserted) {
            result.insert(right.termPtr_[i]);
        }
    }
    return result;
}

Polynomial
Polynomial::operator-(const Polynomial& right) const
{
    Polynomial result(*this);
    for (size_t i = 0; i < right.size_; ++i) {
        bool notInserted = true;
        for (size_t j = 0; j < size_; ++j) {
            if (result.termPtr_[j].getExponent() == right.termPtr_[i].getExponent()) {
                result.termPtr_[j].setCoefficient(result.termPtr_[j].getCoefficient() - right.termPtr_[i].getCoefficient());
                notInserted = false;
                break;
            }
        }
        if (notInserted) {
            result.insert(right.termPtr_[i]);
        }
    }
    return result;
}

Polynomial
Polynomial::operator+=(const Polynomial& right)
{
    const size_t size = size_;
    for (size_t i = 0; i < right.size_; ++i) {
        bool notInserted = true;
        for (size_t j = 0; j < size; ++j) {
            if (termPtr_[j].getExponent() == right.termPtr_[i].getExponent()) {
                termPtr_[j].setCoefficient(termPtr_[j].getCoefficient() + right.termPtr_[i].getCoefficient());
                notInserted = false;
                break;
            }
        }
        if (notInserted) {
            insert(right.termPtr_[i]);
        }
    }
    return *this;
}

Polynomial
Polynomial::operator-=(const Polynomial& right)
{
    const size_t size = size_;
    for (size_t i = 0; i < right.size_; ++i) {
        bool notInserted = true;
        for (size_t j = 0; j < size; ++j) {
            if (termPtr_[j].getExponent() == right.termPtr_[i].getExponent()) {
                termPtr_[j].setCoefficient(termPtr_[j].getCoefficient() - right.termPtr_[i].getCoefficient());
                notInserted = false;
                break;
            }
        }
        if (notInserted) {
            insert(right.termPtr_[i]);
        }
    }
    return *this;
}

void
Polynomial::insert(const Term& term)
{
    Term* tempPtr = new Term[size_ + 1];
    for (size_t i = 0; i < size_; ++i) {
        tempPtr[i] = termPtr_[i];
    }
    delete [] termPtr_;
    tempPtr[size_++] = term;
    termPtr_ = tempPtr;
}

std::ostream&
operator<<(std::ostream& output, const Polynomial& polynomial)
{
    for (size_t i = 0; i < polynomial.size_; ++i) {
        output << ' ' 
               << (polynomial.termPtr_[i].getCoefficient() >= 0 ? "+" : "") 
               << polynomial.termPtr_[i].getCoefficient() 
               << '^' 
               << polynomial.termPtr_[i].getExponent();
    }
    return output;
}

