template<typename Type>
bool isEqualTo(const Type& left, const Type& right);

#ifndef __CLASS_HPP__
#define __CLASS_HPP__

class Class
{
public:
    Class(const int value = 0);
    bool operator==(const Class& right) const;
private:
    int data_;
};

#include "templates/isEqualTo.cpp"

#endif

