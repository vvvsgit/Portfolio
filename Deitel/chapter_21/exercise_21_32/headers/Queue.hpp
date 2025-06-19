#ifndef __QUEUE_HPP__
#define __QUEUE_HPP__

#include "headers/List.hpp"

template <typename QUEUETYPE>
class Queue : private List<QUEUETYPE>
{
public:
    inline void enqueue(const QUEUETYPE& data);
    inline bool dequeue(QUEUETYPE& data);
    inline bool isQueueEmpty() const;
    inline void printQueue() const;
};

#include "templates/Queue.cpp"

#endif

