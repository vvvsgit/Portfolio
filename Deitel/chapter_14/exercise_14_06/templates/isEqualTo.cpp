#include "headers/isEqualTo.hpp"

template<typename Type>
bool
isEqualTo(const Type& left, const Type& right)
{
    return left == right;
}

Class::Class(const int value)
    : data_(value)
{
}

bool
Class::operator==(const Class& right) const
{
    return this->data_ == right.data_;
}
/// Without overloaded operator== template function call for user defined types causes compiller error

