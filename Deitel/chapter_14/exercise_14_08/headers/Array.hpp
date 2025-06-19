#ifndef __ARRAY_HPP__
#define __ARRAY_HPP__

template<typename Type>
class Array
{
public:
    Array();
};

template<>
class Array<float>
{
public:
    Array();
};

#include "templates/Array.cpp"

#endif

