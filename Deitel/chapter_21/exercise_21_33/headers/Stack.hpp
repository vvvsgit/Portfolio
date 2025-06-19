#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "headers/List.hpp"

template <typename STACKTYPE>
class Stack
{
public:
    inline void push(const STACKTYPE& data);
    inline bool pop(STACKTYPE& data);
    inline bool isStackEmpty() const;
    inline void printStack() const;
private:
    List<STACKTYPE> stackList_;
};

#include "templates/Stack.cpp"

#endif

