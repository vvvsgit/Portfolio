#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include "Vector.hpp"
#include "List.hpp"

template <typename T>
class Queue : private List<T>
{
public:
    typedef T value_type;
    typedef value_type& reference;
    typedef const value_type& const_reference;
    typedef size_t size_type;

public:
    Queue();
    Queue(const Queue<T>& rhv);
    inline const Queue<T>& operator=(const Queue<T>& rhv);
    inline bool empty() const;
    inline size_type size() const;
    inline reference front();
    inline const_reference front() const;
    inline reference back();
    inline const_reference back() const;
    inline void push(const_reference value);
    inline void pop();
    inline bool operator==(const Queue<T>& rhv) const;
    inline bool operator<(const Queue<T>& rhv) const;
};

#include "../templates/Queue.cpp"

#endif

