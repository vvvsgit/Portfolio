#ifndef __STACK_HPP__
#define __STACK_HPP__

#include "Vector.hpp"
#include "List.hpp"

template <typename T>
class Stack
{
public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;

public:
    Stack();
    Stack(const Stack<T>& rhv);
    ~Stack();
    inline const Stack<T>& operator=(const Stack<T>& rhv);
    inline bool empty() const;
    inline size_type size() const;
    inline reference top();
    inline const_reference top() const;
    inline void push(const_reference rhv);
    inline void pop();
    inline bool operator==(const Stack<T>& rhv) const;
    inline bool operator<(const Stack<T>& rhv) const;
private:
    List<T> stack_;
};

#include "../templates/Stack.cpp"

#endif

